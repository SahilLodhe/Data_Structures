#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int n){
    //base case
    if(n == 0){
        return 0;
    }

    //recursive step
    int smallans = sum_of_digits(n/10);

    //calculation step
    int last_digit = n%10; //we neew an number to add to the recursive function's returned integer
                           // so we have to introduce another variable "last_digit"
    return last_digit + smallans;
}
int main(){
    int n;
    cin>>n;
    cout<<sum_of_digits(n)<<endl;

    return 0;
}