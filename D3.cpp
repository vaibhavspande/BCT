#include <bits/stdc++.h>
using namespace std;


// int knapsack(vector<int>&val,vector<int>&wt,int W,int n){

// vector<vector<int>>dp(n+1,vector<int>(W+1,0));

// for(int i=1;i<=n;i++){
//     for(int w=1;w<=W;w++){
//         if(wt[i-1] > w){
//             dp[i][w]=dp[i-1][w];

//         }else{
//             dp[i][w]= max(val[i-1] + dp[i-1][w-wt[i-1]],dp[i-1][w]);
//         }
//     }
// }

// return dp[n][W];

// }

int knapsack(vector<int>&val,vector<int>&wt,int W,int n){
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            if(wt[i-1]>w){
                dp[i][w]=dp[i-1][w];
            }else{
                dp[i][w]=max(val[i-1]+ dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }
        }
    }

    return dp[n][W];
}

int main(){

    int n;
    cout<<"Enter the number of items: ";
    cin>>n;

    vector<int>val(n);
    vector<int>wt(n);

    for(int i=0;i<n;i++){
        cout<<"Enter the value of item: "<<i+1<<": ";
        cin>>val[i];
        cout<<"Enter the weight of item "<<i+1<<": ";
        cin>>wt[i];
    }

    int W;
    cout<<"Enter the maximum weight capacity: ";
    cin>>W;

    auto start= chrono::steady_clock::now();
    int result=knapsack(val,wt,W,n);
    auto end=chrono::steady_clock::now();

    size_t space_complexity= sizeof(val)+sizeof(wt)+ sizeof(n)+sizeof(W)+sizeof(result);


    cout<<"\nMaximum value: "<<result<<endl;
    cout<<"Elapsed Time: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<" microseconds"<<endl;
  cout<<"Space Complexity: "<<space_complexity<<" bytes"<<endl;
    return 0;
}