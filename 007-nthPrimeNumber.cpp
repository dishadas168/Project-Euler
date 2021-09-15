#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nthPM(int num){
    
    static vector<int> primes;
 
    if(primes.size()== 0){
        int ans, i=3;
        primes.push_back(2);

        while(primes.size()< 10000){     
            ans = i;
            for(auto x: primes){
                while(ans%x == 0)
                    ans = ans/x;
            }
            if(ans != 1)
                primes.push_back(i);
            i+= 2;
        }
    }
    
    return primes[num-1];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    int num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<nthPM(num)<<endl;
    }    
    return 0;
}
