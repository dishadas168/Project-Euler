#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Date{
    long y;
    int m,d;
    Date(long Y, int M, int D): 
                    y(Y), m(M), d(D){}
    
    bool operator<( const Date d2 ){
        if(y < d2.y) return true;
        else if(y == d2.y && m < d2.m) return true;
        else if(y==d2.y && m == d2.m && d < d2.d) return true;
        return false;
    }
    
    bool operator==( const Date d2 ){
        return y == d2.y && m == d2.m && d == d2.d;
    }
    
    int getWeekDay(){
        int q = d, mo, k;
        long j;
        if(m < 3){
            mo = m + 12;
            k = (y-1)%100;
            j = (y-1)/100;
        }else{
            mo = m;
            k = y%100;
            j = y/100;
        }
        long h = (q + 13*(mo + 1)/5 + k + k/4 + j/4 + 5*j)%7;
        return ((h+5)%7) + 1;
    }
    
    void toNextSunday(bool init){
        int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(isLeap()) months[2] = 29;
        
        //If given date may not be Sunday, init=true
        if(init){
            int w = this->getWeekDay();
            d += (7-w);
        }else d += 7;
        
        if(d > months[m]){
            d = d%months[m];
            m += 1;
        }
        if(m > 12){
            y ++;
            m = 1;
        }
    }
    
    bool isLeap(){
        if(y%4 == 0){
            if(y%100 != 0)
                return true;
            else if(y%400 == 0)
                return true;
            return false;
        }
        return false;
    }
};



int countSundays(Date d1, Date d2){
    
    d1.toNextSunday(true);
    int count = 0;
    while(d1 < d2 || d1 == d2){
        while(d1.y + 2800 < d2.y){
            d1.y += 2800;
            count += 4816;
        }
        
        if(d1.d == 1)
            count++;
        
        d1.toNextSunday(false);
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t, m1, m2, d1, d2;
    long y1, y2;
    cin>>t;
    while(t--){
        cin>>y1>>m1>>d1;
        cin>>y2>>m2>>d2;
        cout<<countSundays(Date(y1, m1, d1), Date(y2, m2, d2))<<endl;
    } 
    return 0;
}