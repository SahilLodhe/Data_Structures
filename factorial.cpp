#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    //cout<<n<<endl;
    if(n<=1){    //1st step base case 
        return 1;
    }
    int smallans = fact(n-1);  //2nd step assumption recursive case
    int ans = n*smallans;  //3rd step calculation
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans = fact(n);
    //cout<<ans<<endl;
    cout<<fact(n)<<endl;
    return 0;
}

/*
PMI 



*/