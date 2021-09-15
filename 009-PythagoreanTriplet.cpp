#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pythagoreanTriplet(int num){
    int prod = 1;
        
    for(int i= num/2; i> 1; i--){
        int j = i-1;
        if(j < num-i-j)
            break;
        while( j> num-i-j){
            if(pow(i,2) == pow(j,2) + pow(num-i-j,2)){
                if(i*j*(num-i-j) > prod)
                    prod= i*j*(num-i-j);
            }
            j--;
        }  
    }
    if(prod != 1) return prod;
    else return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    int num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<pythagoreanTriplet(num)<<endl;
    }  
    return 0;
}