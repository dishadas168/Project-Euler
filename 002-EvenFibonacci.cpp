#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long evenFibonacciSum(long long num){
    long long sum = 0;
    long long i=2, j=1;
    while(i <= num){
        if(i%2==0) sum+= i;
        i += j;
        j = i - j;
        
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    long long num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<evenFibonacciSum(num)<<endl;
    }
    return 0;
}
