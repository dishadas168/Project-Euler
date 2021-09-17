#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int factorialSum(int n){
 
    static int sums[1001] = {0};
    if(!sums[1]){
        sums[1] = 1;
        sums[0] = 1;
        int arr[INT16_MAX] = {0}, prod, carry=0, sum=0;
        arr[0] = 1;
        for(int i = 2; i<= 1000; i++){
            for(int j = 0; j<= INT16_MAX; j++){
                prod = arr[j]*i + carry;
                arr[j] = prod%10;
                carry = prod/10;
            }
            carry = 0;
            for(int k = 0; k< INT16_MAX; k++)
                sums[i] += arr[k];
        
        }
    }

    return sums[n];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<factorialSum(n)<<endl;
    } 
    return 0;
}
