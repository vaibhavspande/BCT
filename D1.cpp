#include <bits/stdc++.h>
using namespace std;

static unsigned long long lastTotalUser, lastTotalUserLow,lastTotalSys, lastTotalIdle;

void init(){
   FILE *file=fopen("/proc/stat","r");
   fscanf(file,"cpu %llu %llu %llu %llu", &lastTotalUser, &lastTotalUserLow, &lastTotalSys,&lastTotalIdle);
   fclose(file);
}

struct HuffmanNode{
    char data;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;
};

struct CompareNodes{
    bool operator()(HuffmanNode *left,HuffmanNode *right){
        return left->frequency > right->frequency;
    }
};

HuffmanNode *buildHuffmanTree(unordered_map<char,int>&frequencies){

    priority_queue<HuffmanNode *,vector<HuffmanNode*>, CompareNodes>minHeap;

    for(auto &entry:frequencies){
        HuffmanNode *node=new HuffmanNode;
        node->data=entry.first;
        node->frequency=entry.second;
        node->left=nullptr;
        node->right=nullptr;
        minHeap.push(node);
    }

    while(minHeap.size() >1){
        HuffmanNode *left = minHeap.top();
        minHeap.pop();
        HuffmanNode *right= minHeap.top();
        minHeap.pop();
        
        HuffmanNode *mergedNode = new HuffmanNode;
        mergedNode->data='\0';
        mergedNode->frequency=left->frequency + right->frequency;
        mergedNode->left=left;
        mergedNode->right=right;
        minHeap.push(mergedNode);
    }
    return minHeap.top();
}

void generateHuffmanCodes(HuffmanNode *root,string code, unordered_map<char,string>&huffmanCodes){
    if(root==nullptr){
        return;
    }
    if(root->data != '\0'){
        huffmanCodes[root->data]=code;
    }
    generateHuffmanCodes(root->left,code+"0",huffmanCodes);
    generateHuffmanCodes(root->right,code+"1",huffmanCodes);
}

string encodeMessage(const string &message,const unordered_map<char,string>&huffmanCodes){
    string encodedMessage;
    for(char c:message){
        encodedMessage += huffmanCodes.at(c);
    }
    return encodedMessage;
}

string decodeMessage (const string & encodedMessage, HuffmanNode *root){
    string decodedMessage;
    HuffmanNode *current =root;
    for(char bit: encodedMessage){
        if(bit=='0'){
            current=current->left;
        }
        else{
            current=current->right;
        }
        if(current->data != '\0'){
            decodedMessage += current->data;
            current=root;
        }
    }
    return decodedMessage;
}

int main(){

// step1: Take a file as input
    init();
    string filename;
    cout<<"Enter the filename to encode and decode: "<<endl;
    cin>>filename;

// step2: read the character from the file 

    ifstream inputFilename(filename);
    if(!inputFilename){
        cerr<<"Error: file not found"<<endl;
        return 1;
    }

// step 3: store character into message and close file

    string message; 
    char ch;
    while(inputFilename.get(ch)){
        message += ch;
    }
    inputFilename.close();

// step 4: count the frequencies of symbol

unordered_map<char,int>frequencies;
for(char ch:message){
    frequencies[ch]++;
}

// step5:BuildHuffman Tree

HuffmanNode *root=buildHuffmanTree(frequencies);

// step 6: generate huffman codes

unordered_map<char,string>huffmanCodes;
generateHuffmanCodes(root,"",huffmanCodes);

auto start1= chrono::steady_clock::now();

// stemp 7: encode the message
string encodedMessage=encodeMessage(message,huffmanCodes);
cout<<"Encoded Message: "<<encodedMessage<<endl;

auto end1 = chrono::steady_clock::now();
cout<<"\n Time Taken: "<<chrono::duration_cast<chrono::microseconds>(end1-start1).count()<<" microseconds"<<endl;


init();

auto start2= chrono::steady_clock::now();

// step 8: decode the message
string decodedMessage=decodeMessage(encodedMessage,root);

// step 9: output the message
cout<<"\nDecoded Message: "<<decodedMessage<<endl;
auto end2= chrono::steady_clock::now();

cout<<"\nElapsed time taken for decode: "<<chrono::duration_cast<chrono::microseconds>(end2-start2).count()<<" microseconds"<<endl;

return 0;
}