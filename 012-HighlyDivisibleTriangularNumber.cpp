#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long getTriangular(long num){
    return num*(num+1)/2;
}

int getNumFactors(long n){
    int d = 2, p, prod = 1;
    while(n > 1){
        p = 0;
        while(n % d == 0){
            p++;
            n /= d;
        }
        if (p) prod *= (p + 1);
        d++;
        if (n > 1 && d*d > n)
            d = n;
    }
    return prod;
}

long triangularNum(int num){
    //Map stores the number and max num divisors until that num
    static map<int, long> first_occ;
    if(!first_occ.size()){
        long curr_num = 0;
        int last_N = 1;
        while(last_N <= 1000 ){
            curr_num++;
            long tri = getTriangular(curr_num);
            int numFactors = getNumFactors(tri);
            while(numFactors > last_N){
                first_occ[last_N] = curr_num;
                last_N++;
            } 
        } 
    }
    
    return getTriangular(first_occ[num]);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    int num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<triangularNum(num)<<endl;
    }     
    return 0;
}
