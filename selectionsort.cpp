#include <bits/stdc++.h>
using namespace std;
void selectionsort(int a[],int n){

    for(int i = 0;i<=n-2;i++){
        int smallest = INT_MAX;//we have to take int max because we want to declare smallest as the largest intger (+ infinity)
        for(int j = i + 1;j<=n-1;j++){
            if(a[j]<a[smallest]){
                smallest = j;
            }
        }
        swap(a[i],a[smallest]);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    selectionsort(a,n);
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}