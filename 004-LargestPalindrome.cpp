#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int highestPalindrome(int num){
 
    static map<int, int> smap;
    string n;
    int max = 0;
    
    if(smap.size() == 0){
        for(int i= 999; i >100; i--){
            for(int j = 999; j >100; j--){
                n = to_string(i*j);
                if(n[0]==n[5]&&n[1]==n[4]&&n[2]==n[3])
                    smap[i*j] ++; 
            }
        }
    }
    
    map<int, int>::reverse_iterator it;
    for(it = smap.rbegin(); it != smap.rend(); it++){
        if(it->first < num){
            max = it->first;
            break;
        }
    }
    return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    int num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<highestPalindrome(num)<<endl;
    }  
    return 0;  
}
