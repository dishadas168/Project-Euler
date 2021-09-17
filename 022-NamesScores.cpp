#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    map<string,int> names;
    string name;
    cin>>n;
    while(n--){
        cin>> name;
        names[name]++;
    }
    int i = 1;
    for(auto& x:names)
        x.second = i++;
    
    cin>>q;
    int sum;
    while(q--){
        sum = 0;
        cin>>name;
        for(auto x: name)
            sum += x - 'A'+1;
        cout<<sum*names[name]<<endl;
    }
    return 0;
}
