#include <bits/stdc++.h>
using namespace std;

void remove_char(char input[], char r)
{
    //base case
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] != r)
    {
        remove_char(input + 1,r);
    }
    else{
        for(int i = 0;input[i] != '\0';i++){
            input[i] == input[i+1];
        }
        remove_char(input,r);
    }
    
    
}
int main()
{
    char input[100];
    cin >> input;
    char r;
    cin >> r;
    remove_char(input, r);
    cout << input;
    return 0;
}