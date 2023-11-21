#include <bits/stdc++.h>
using namespace std;

bool isSafe(int col,int row,const vector<string>&board,vector<vector<string>>&ans,int n){
    int dupRow=row;
    int dupCol=col;

    while(row>=0&& col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }
     row=dupRow;
     col=dupCol;
    while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }

     row=dupRow;
     col=dupCol;
    while(row<n && col>=0){
        if(board[row][col] =='Q'){
            return false;
        }
        row++;
        col--;
    }


    return true;
}

void solve(int col,int n, int fixedRow, vector<string>&board,vector<vector<string>>&ans){

    if(col==n){
        ans.push_back(board);
        return;
    }

    if(col==0){
        solve(col+1,n,fixedRow,board,ans);
        return;
    }

    for(int row =0;row<n;row++){
        if(row != fixedRow && isSafe(col,row,board,ans,n)){
            board[row][col]='Q';
            solve(col+1,n,fixedRow,board,ans);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> solveQueens(int n,int fixedRow){

    vector<vector<string>>ans;

    vector<string>board(n,string(n,'.'));

    board[fixedRow][0]='Q';
    solve(1,n,fixedRow,board,ans);
    return ans;
}


int main(){
    int n;
    cout<<"Enter the size of board: ";
    cin>>n;

    int fixedRow;
    cout<<"Enter the fixed row between (0 - "<<n-1<<" )"<<endl;
    cin>>fixedRow;


    vector<vector<string>>ans=solveQueens(n,fixedRow);

    if(ans.empty()){
        cout<<"No output for given input"<<endl;
    }else{

         
         for(int i=0;i<ans.size();i++){
            cout<<"Arrangement: "<< i+1<<endl;
            for(int j=0;j<ans[0].size();j++){
                cout<<ans[i][j];
                cout<<endl;
            }
            cout<<endl;
         }

    }

    return 0;
}