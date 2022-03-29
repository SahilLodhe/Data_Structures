#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    //base case
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    //recursive case
    int smalloutput1 = fib(n - 1);
    int smalloutput2 = fib(n - 2);

    //calculation
    return smalloutput1 + smalloutput2;

}

int main(){

    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}