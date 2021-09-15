#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long primeSum(long num){
    long max_num = 1000000;
    static vector<bool> sieve(max_num, true);
    static vector<long> sums(max_num, 0);
    
    //Form Eratosthenes Sieve
    if(sieve[0]){
        sieve[0] = false;
        for(long i=4; i<= max_num; i +=2)
            sieve[i-1] = false;
        long i=3;
        while(i <= max_num){
            while(!sieve[i-1])
                i++;
            for(long j = i+i; j<= max_num; j +=i)
                sieve[j-1] = false;
            i+=2;
        }
        //Form sum array
        sums[0] = 0;
        for(long i = 1; i< max_num; i++)
            sums[i] = (sums[i-1]+(i+1)*sieve[i]);
    }
    
    return sums[num-1];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    int num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<primeSum(num)<<endl;
    }   
    return 0;
}
