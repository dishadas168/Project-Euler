#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int getFactorSums(int n){
    int sum = 1;
    for (int i=2; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i)
                sum+= i;
            else 
                sum += i + n/i;
        }
    }
    return sum;
}

int amicableNumbersSum(int n){
    static map<int, int> an;
    int a, b, sum = 0;
    if(an.size() == 0){
        for(int i = 1; i<= 100000; i++){
            a = getFactorSums(i);
            b = getFactorSums(a);
            if(i == b && i!= a) {
                an[i]++;
                an[a]++;
            }    
        }
    }
    
    for(auto x: an){
        if(x.first < n)
            sum += x.first;
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n;
    cin>> t;
    while(t--){
        cin>>n;
        cout<<amicableNumbersSum(n)<<endl;
    }
    return 0;
}
