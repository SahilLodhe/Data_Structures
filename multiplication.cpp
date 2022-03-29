#include <bits/stdc++.h>
using namespace std;

//m*n = m*(n-1) + m

int multiply(int m, int n){
    //base case
    if(n==0){
        return 0;
    }

    //recursive step
    int smallans = multiply(m,n-1);

    //calculation step
    return smallans + m;
}
int main(){
    int m;
    int n;
    cin>>m>>n;
    cout<<multiply(m,n);

    return 0;
}