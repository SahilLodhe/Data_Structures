#include <bits/stdc++.h>
using namespace std;
void replace_char(char input[])
{
    //base case
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] == 'a')
    {
        input[0] == 'x';
    }
    //recursive case
    replace_char(input + 1);
    //calculation step
}
int main()
{
    char input[100];
    cin >> input;
    cout << input;
    replace_char(input);
    cout << input;
    return 0;
}