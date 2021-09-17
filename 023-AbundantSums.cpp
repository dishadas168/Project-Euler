#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

void sumOfAbundants(int n){
    static map<int, int> abs;
  
    if(abs.size() == 0){
        for(int i = 12; i <= 100000; i++){
            int sum = 1;
            for (int j=2; j<=sqrt(i); j++){
                if (i%j == 0){
                    if (i/j == j)
                        sum+= j;
                    else 
                        sum += j + i/j;
                }
            }
            if(sum > i) abs[i]++;
        }
    }
    
    
    for(auto& x: abs){
        if(abs.find(n-x.first) != abs.end()){
            cout<<"YES"<<endl;
            return;
        }    
        if(x.first > n)
            break;
    }
    cout<<"NO"<<endl; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        sumOfAbundants(n);
    }   
    return 0;
}
