#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
using namespace std;

long MAX_NUM = 5000001;
long collatzFreq[5000001];
long longest[5000001];

long getCollatzChain(long n){

    if(collatzFreq[n] != 0)
        return collatzFreq[n];
    
    if(n%2 == 0)
        collatzFreq[n] = 1 + getCollatzChain(n/2);
    else{
        long count = 1;
        long nn = 3*n + 1;
        while(nn> MAX_NUM){
            if(nn%2 == 0) nn/= 2;
            else nn = nn*3 + 1;
            count++;
        }
        collatzFreq[n] = count + getCollatzChain(nn);
    }
        
    return collatzFreq[n];
}

void getLongestChains(){
    collatzFreq[2] = 1;
    for(long i = 1; i < MAX_NUM; i++)
        getCollatzChain(i);
    for(long i=2; i< MAX_NUM; i++){
        if(collatzFreq[i] >= collatzFreq[longest[i-1]])
            longest[i] = i;
        else longest[i] = longest[i-1];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    long n;
    cin >>t;
    
    getLongestChains();
    while(t--){
        cin>>n;
        cout<<longest[n]<<endl;
    } 
    return 0;
}
