#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long mod = 1000000007;

long getLatticePaths(int n, int m){
    
    //Initialize the array for storing lattices paths (n,m)
    static long arr[501][501];
    if(!arr[1][1]){
        arr[1][1] = 2;
        for(int i=0; i < 501; i++){
            arr[0][i] = 1;
            arr[i][0] = 1;
        }
    }

    if(arr[n][m] != 0)
        return arr[n][m]%mod;
    
    //For each row
    long lattices = 0;
    for(int i = n-1; i >= 0; i--){
        if(!arr[i][m-1]){
            arr[i][m-1] = getLatticePaths(i, m-1);
            arr[m-1][i] = arr[i][m-1];
        }     
        lattices += arr[i][m-1];
    }
        
    //For each column
    for(int i = m-1; i >= 0; i--){
        if(!arr[n-1][i]){
            arr[n-1][i] = getLatticePaths(n-1, i);
            arr[i][n-1] = arr[n-1][i];
        }  
        lattices += arr[n-1][i];
    }
    return lattices%mod;
}

int main() {
    /* Enter your code here. Read input from STDIN. Prlong output to STDOUT */ 
    int t, N, M;
    cin>>t;
    
    while(t--){
        cin>>N>>M;
        cout<<getLatticePaths(N,M)<<endl;
    }  
    return 0;
}
