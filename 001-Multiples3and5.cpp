#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long getMultiples(long num){
    num--;
    long num3 = (num - num%3)/3;
    long num5 = (num - num%5)/5;
    long num15 = (num - num%15)/15;
    
    return num3*(num3+1)*3/2 + 
            num5*(num5+1)*5/2 -
            num15*(num15+1)*15/2; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    long n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<getMultiples(n)<<endl;
    } 
    return 0;
}
