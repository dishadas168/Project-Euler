#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getHundreds(int nums[]){
    string out = "";
    
    for(int i=0; i< 3; i++){
        
    //For Tens place and ones too in some cases
        if(i == 1){
            if(nums[i] == 1){
                switch(nums[i+1]){
                    case 0: out += "Ten ";
                            break;
                    case 1: out += "Eleven ";
                            break;
                    case 2: out += "Twelve ";
                            break;
                    case 3: out += "Thirteen ";
                            break;
                    case 4: out += "Fourteen ";
                            break;
                    case 5: out += "Fifteen ";
                            break;
                    case 6: out += "Sixteen ";
                            break;
                    case 7: out += "Seventeen ";
                            break;
                    case 8: out += "Eighteen ";
                            break;
                    case 9: out += "Nineteen ";
                            break;
                }
                break;
            }else{
                switch(nums[i]){
                    case 2: out += "Twenty ";
                            break;
                    case 3: out += "Thirty ";
                            break;
                    case 4: out += "Forty ";
                            break;
                    case 5: out += "Fifty ";
                            break;
                    case 6: out += "Sixty ";
                            break;
                    case 7: out += "Seventy ";
                            break;
                    case 8: out += "Eighty ";
                            break;
                    case 9: out += "Ninety ";
                            break;
                }
            }

        }else { //For hundreds and ones cases
            switch(nums[i]){
                case 1: out += "One ";
                        break;
                case 2: out += "Two ";
                        break;
                case 3: out += "Three ";
                        break;
                case 4: out += "Four ";
                        break;
                case 5: out += "Five ";
                        break;
                case 6: out += "Six ";
                        break;
                case 7: out += "Seven ";
                        break;
                case 8: out += "Eight ";
                        break;
                case 9: out += "Nine ";
                        break;
            }
            if(out != "" && i == 0) out += "Hundred ";
        }
    }
    return out;
}

string inWords(string num){
    
    int arr[12] = {0}, subarr[3];
    for(int i= num.size()-1, j=11; i >=0; i--, j--)
        arr[j] = num[i] - '0';
    
    string output = "";
    string hundreds = "";

    for(int i=0; i< 12; i +=3){
        subarr[0] = arr[i];
        subarr[1] = arr[i+1];
        subarr[2] = arr[i+2];
        hundreds = getHundreds(subarr);
        if(hundreds != ""){
            output = output + hundreds;
            switch(i){
                case 6: output += "Thousand ";
                        break;
                case 3: output += "Million ";
                        break;
                case 0: output += "Billion ";
                        break;
            }
        } 
    }
    
    if(output == "") return "Zero";
    
    return output;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    string num;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<inWords(num)<<endl;
    }  
    return 0;
}
