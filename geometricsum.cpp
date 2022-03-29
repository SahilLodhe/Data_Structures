#include <bits/stdc++.h>
using namespace std;
float G_sum(int k,int n){
    //base case
    if(k == 0){
        return 1.0;
    }
    //recursive case
    float smallans = G_sum(k-1,n);
    //calculation step
    return smallans + (1.0/(pow(n,k)));
}
int main(){
    int k,n;
    cin>>k>>n;
    cout<<G_sum(k,n);
    
    return 0;
}