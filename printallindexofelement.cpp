#include <bits/stdc++.h>
using namespace std;

void print_all_positions(int a[],int n,int x,int i){
    //base case
    if(i == n){return;}
    if(a[i] == x){cout<<i<<" ";}
    //recursive step
    print_all_positions(a,n,x,i+1);
    //calculation step
    
}

int main(){
    int n = 10;
    int i = 0;
    int x = 4;
    int a[] = {1,2,4,4,3,5,4,6,4,2};
    cout<<"the element is found at the positions : ";
    print_all_positions(a,n,x,i);

    return 0;
}