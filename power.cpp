#include <bits/stdc++.h>
using namespace std;

int Power(int x, int n){
    //base case
    if(n == 0){
        return 1;
    }
    //recursive step
    int smalloutput = Power(x,n-1);
    //calculation
    return x*smalloutput;
}
int main(){
    int base,power;
    cin>>base>>power;
    cout<<Power(base,power);
    return 0;
}

/*

x^n = x * x^(n-1)
so x^n and x^(n - 1) are in recursion

*/