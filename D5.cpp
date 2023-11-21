#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }

    swap(arr[i+1],arr[high]);
    return (i+1);
}

void deterministicSort(vector<int>&arr,int low,int high){
    if(low<high){
        int median=(low+high)/2;
        if(arr[low]>arr[median]) swap(arr[low],arr[median]);
        if(arr[low]>arr[high]) swap(arr[low],arr[median]);
        if(arr[median]> arr[high]) swap(arr[median],arr[high]);
        swap(arr[high],arr[median]);

        int pivot=partition(arr,low,high);
        deterministicSort(arr,low,pivot-1);
        deterministicSort(arr,pivot+1,high);

    }
}

void randomizedSort(vector<int>&arr,int low,int high){
    if(low<high){
        int randomPivot=low+rand()%(high-low+1);
        swap(arr[randomPivot],arr[high]);
        int pivot=partition(arr,low,high);
        randomizedSort(arr,low,pivot-1);
        randomizedSort(arr,pivot+1,high);
    }
}


int main(){

    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int>arr(n),deterministicArr,randomizedArr;

    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    deterministicArr=arr;
    randomizedArr=arr;


    auto start1= chrono::steady_clock::now();
    deterministicSort(deterministicArr,0,n-1);
    auto end1=chrono::steady_clock::now();

    auto start2=chrono::steady_clock::now();
    randomizedSort(randomizedArr,0,n-1);
    auto end2= chrono::steady_clock::now();


    cout<<"\nAfter random: ";
     for(int i=0;i<n;i++){
        cout<<randomizedArr[i]<<" ";
    }


    cout<<"\nAfter deter: ";
     for(int i=0;i<n;i++){
        cout<<deterministicArr[i]<<" ";
    }

    size_t space_complexity= sizeof(randomizedArr)+ sizeof(arr)+sizeof(deterministicArr)+sizeof(arr)+sizeof(n);

    cout<<"\n Time taken for deterministic: "<<chrono::duration_cast<chrono::microseconds>(end1-start1).count()<<" microseconds"<<endl;
    cout<<"Time taken for randomized: "<<chrono::duration_cast<chrono::microseconds>(end2-start2).count()<<" microseconds"<<endl;
    cout<<"Space complexity: "<<space_complexity<<" bytes";

    return 0;
}