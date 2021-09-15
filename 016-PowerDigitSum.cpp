#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int powerDigitSum(int n){
    vector<int> v;
    v.push_back(2);
    int prod, carry=0, sum=0;
    
    while(--n){
        for(int i=0; i< v.size(); i++){
            prod = v[i]*2;
            prod += carry;
            v[i] = prod%10;
            carry = prod/10;
        }
        if(carry) v.push_back(carry);
        carry = 0;
    }
    
    for(auto x:v) sum+= x;
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<powerDigitSum(n)<<endl;
    } 
    return 0;
}
