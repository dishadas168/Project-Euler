#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> triangle;

int maxPathSum( int row, int col){
    if(row == triangle.size()-1)
        return triangle[row][col];
    
    int suml = maxPathSum(row+1, col);
    int sumr = maxPathSum(row+1, col+1);
    return triangle[row][col] + max(suml, sumr );
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t,r, n;
    cin>>t;
    while(t--){
        cin>>r;
        for(int i=1; i <= r; i++){
            vector<int> row;
            for(int j=i-1; j >= 0; j--){
                cin>>n;
                row.push_back(n);
            }
            triangle.push_back(row);   
        }
        cout<<maxPathSum( 0, 0)<<endl;
        triangle.clear();
    }  
    return 0;
}