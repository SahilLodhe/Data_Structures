#include <bits/stdc++.h>
using namespace std;
int count_zeroes(int n){
    //base case
    if(n == 0){
        return 0;
    }
    //recursive case
    int smallans = count_zeroes(n/10);
    //calculation step
    int last_digit = n%10;
    
    if(last_digit == 0){
        return smallans + 1;
    }
    else
    {
        return smallans;
    }
    
}
int main(){
    int n;
    cin>>n;
    cout<<count_zeroes(n);
    
    
    return 0;
}