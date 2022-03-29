#include <bits/stdc++.h>
using namespace std;
int flag = 0;
int find_1st_index1(int a[],int n,int x){ //by using global variable
    //base case
    
    if(n == 0){
        cout<<"element not found"<<endl;
        return -1;
    }
    if(a[0] == x){
        cout<<"the element is at index: "<<endl;
        return flag; 
    }
    flag  = flag + 1;
    //recursive step
    int flagl = find_1st_index1(a + 1,n - 1,x);

    //calculative step
    return flagl;

}
//OR, here is another way to do it
int find_1st_index2(int a[],int n,int x,int i){
    //base case
    if(n == 0){
        cout<<"element not found"<<endl;
        return -1;
    }
    if(a[i] == x){
        cout<<"the index of the forst occurence of the element is"<<endl;
        return i;
    }
    //recursive step
    int flag2 = find_1st_index2(a,n,x,i + 1);
    //calculation step
    return flag2;
}
int main(){
    int i = 0;
    int n;
    int x;
    int a[n];
    cout<<"enter the limit"<<endl;
    cin>>n;
    cout<<"enter the number to be found"<<endl;
    cin>>x;
    cout<<"enter the elements of the array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<find_1st_index1(a,n,x);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<find_1st_index2(a,n,x,i);
    

    return 0;
}