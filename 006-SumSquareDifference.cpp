#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long sumSquareDiff(long t){
    long sum = pow(t*(t+1)/2,2);
    long sum_of_squares = t*(t+1)*(2*t+1)/6;
    return abs(sum_of_squares - sum); 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    long num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<sumSquareDiff(num)<<endl;
    }   
    return 0;
}
