#include <bits/stdc++.h>
using namespace std;
bool ispresent(int a[],int n,int k){
    //base case
    if(k == 0){
        return false;
    }
    if(a[0] == n){
        return true;
    }
    //recursive step
    bool checker = ispresent(a + 1,n,k - 1);

    //calcuation step
    return checker;

}
int main(){
    int k;//limit of the array
    cout<<"enter the limit of the array"<<endl;
    cin>>k;
    int n;//number to be found
    cout<<"enter the number to be found"<<endl;
    
    cin>>n;
    int a[k];
    cout<<"enter the elements of the array"<<endl;
    for(int i = 0;i<k;i++){
        cin>>a[i];
    }
    if(ispresent(a,n,k)){
        cout<<"element is present"<<endl;
    }
    else{
        cout<<"element is not present"<<endl;
    }
    return 0;
}