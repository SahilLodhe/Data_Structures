#include <bits/stdc++.h>
using namespace std;
void print(char input[]){
    //base case
    if(input[0] == '\0'){
        return;
    }
    //recursive case
    cout<<input[0];
    //calculation step
    print(input + 1);
}
void rev_print(char input[]){
    //base case
    if(input[0] == '\0'){
        return;
    }
    
    rev_print(input + 1);
    cout<<input[0];
}
int main(){
    
    char input[20] = "sahil is the boss";
    print(input);
    cout<<endl;
    rev_print(input);
    return 0;
}