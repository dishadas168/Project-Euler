#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long largestPF(long long num){
    long long ans = num;
    long long i=2, max=1;
  
    while(ans%2 == 0){
            ans = ans/2;
            max = 2;
    }
    
    i = 3;
    while(i <= sqrt(ans)){
        while(ans%i == 0){
            ans = ans/i;
            if(i > max) max = i;
        }      
        i+=2;
    }
    return std::max(max, ans);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    long long num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<largestPF(num)<<endl;
    }  
    return 0;
}
