#include <bits/stdc++.h>
using namespace std;
int length(char input[])
{
    if (input[0] == '\0')
    {
        return 0;
    }
    int smallLength = length(input + 1);
    return 1 + smallLength;
}
int main()
{
    char input[100];
    cin >> input;
    int l = length(input);
    cout << l << endl;
    return 0;
}