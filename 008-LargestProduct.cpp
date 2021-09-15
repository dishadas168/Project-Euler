#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long largestProduct(string N, int k){
    long largest = 0;
    long curr =1;
    for(int i=0; i < N.length() - k; i++){
        curr = 1;
        for(int j=i; j< i+k; j++){
            curr *= (N[j]-'0');
        }
        if(curr > largest)
            largest = curr;
    }
    return largest;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t, k, n;
    string num;
    cin>>t;
    while(t--){
        cin>>n>>k>>num;
        cout<<largestProduct(num, k)<<endl;
    }   
    return 0;
}
