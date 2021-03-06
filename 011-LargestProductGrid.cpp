#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long gridProduct(vector<vector<int>> grid){
    long largest=0, prod;
    for(int i=0; i< 20; i++){
        for(int j=0; j< 20; j++){
            //down
            if(i<17){
                prod=1;
                for(int k=0; k < 4; k++)
                    prod *= grid[i+k][j];
                if(prod >= largest) largest = prod;
            }
            
            //right
            if(j<17){
                prod=1;
                for(int k=0; k < 4; k++)
                    prod *= grid[i][j+k];
                if(prod >= largest) largest = prod;
            }
            
            //down-right
            if(i<17 && j<17){
                prod=1;
                for(int k=0; k < 4; k++)
                    prod *= grid[i+k][j+k];
                if(prod >= largest) largest = prod;
            } 
            
            //down-left
            if(i<17 && j > 2){
                prod=1;
                for(int k=0; k < 4; k++)
                    prod *= grid[i+k][j-k];
                if(prod >= largest) largest = prod;
            }      
        }
    }
    return largest;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<vector<int>>  grid;
    int num;
    for(int i = 0; i < 20; i++){
        vector<int> row;
        for(int j= 0; j < 20; j++){
            cin>>num;
            row.push_back(num);
        }
        grid.push_back(row);
    }
    
    cout<<gridProduct(grid)<<endl;
    return 0;
}
