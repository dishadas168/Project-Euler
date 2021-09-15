#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int smallestMultiple(int t){
    // Initialize result
    int ans = 1;

    // after i'th iteration,
    for (int i = 2; i <= t; i++)
        ans = (((i * ans)) /
                (gcd(i, ans)));
 
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    int num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<smallestMultiple(num)<<endl;
    }  
    return 0;
}
