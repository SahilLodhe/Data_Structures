#include <bits/stdc++.h>
using namespace std;
int count = 0;
void no_of_occurences(int a[], int n, int x, int i, int ans)
{
    if (i == n)
    {
        return;
    }
    if (a[i] == x)
    {
        ans++;
    }
    no_of_occurences(a, n, x, i + 1, ans);
}
int main()
{
    int ans = 0;
    int n = 13;    //limit of the array
    int count = 0; //number of occurences
    int x = 3;     //number to find
    int a[] = {1, 2, 3, 5, 5, 3, 3, 3, 7, 2, 3, 6, 3};
    no_of_occurences(a, 13, 3, 0, ans);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "number of times the element has occured : " << endl;
    cout << ans << endl;
    return 0;
}