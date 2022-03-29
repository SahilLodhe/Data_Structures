#include <bits/stdc++.h>
using namespace std;

void print_asc(int n){
    //base case
    if(n == 0){   //OR   if(n == 1){cout<<"1"<<endl;}
        return;   //writing the return is mandatory in every if condition       
    }
    //recursive case
    print_asc(n - 1);
    
    //calculation
    cout<<n<<endl;

}

void print_des(int n){
    //base case
    if(n == 0){
        return; //writing the return is mandatory in every if condition
    }
    //recursive step
    cout<<n<<endl;
    
    //calculation step
    print_des(n - 1);
    
}

int main(){
    int n;
    cin>>n;
    cout<<endl;
    print_asc(n);
    cout<<endl;
    print_des(n);
    return 0;
}