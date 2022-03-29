#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<endl;
    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}