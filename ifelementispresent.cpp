#include <bits/stdc++.h>
using namespace std;
bool find(int a[], int n, int x)
{
    //base case
    if (n == 0)
    {
        return false;
    }
    if (a[0] == x)
    {
        return true;
    }
    //recursive step
    bool ispresent = find(a + 1, n - 1, x);

    //calculation step
    return ispresent;
}
int main()
{
    int n;
    int a[n];
    cout << "enter the limit" << endl;
    cin >> n;
    cout << "enter the element you want to find" << endl;
    int x;
    cin >> x;
    cout << "enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (find(a, n, x))
    {
        cout << "element is present" << endl;
    }
    else
    {
        cout << "element is not present" << endl;
    }
    return 0;
}