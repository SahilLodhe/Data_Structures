#include <bits/stdc++.h>
using namespace std;

void optimized_bubblesort(int a[],int n){
    for(int count = 1;count<=n-1;count++){
        //int flag = 0;
        for(int j = 0;j<=n-2;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                    //flag = 1;
                
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    cout<<endl;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    optimized_bubblesort(a,n);

    return 0;
}