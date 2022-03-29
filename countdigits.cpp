#include <bits/stdc++.h>
using namespace std;
int count(int n){
    //base case
    if(n == 0){
        return 0;
    }
    //recursive step
    int smallans = count(n/10);

    //calculation step
    return smallans + 1;
}
int main(){
    int n;
    cin>>n;
    cout<<count(n)<<endl;
    
    return 0;
}