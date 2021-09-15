#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getSum(vector<string> nums){
    string ans = "";
    int col_sum = 0, ones = 0;
    for(int i= 49; i >=0; i--){
        for(int j = 0; j< nums.size(); j++)
            col_sum += nums[j][i]-'0';
        ones = col_sum % 10;
        col_sum = col_sum / 10;
        ans = to_string(ones) + ans;
    }
    ans = to_string(col_sum) + ans;

    return ans.substr(0,10); 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    string num;
    vector<string> nums;
    cin>>t;
    while(t--){
        cin>>num;
        nums.push_back(num);
    }  
    cout<<getSum(nums)<<endl;
    return 0;
}
