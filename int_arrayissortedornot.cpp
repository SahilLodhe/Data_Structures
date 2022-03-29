#include <bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int n)
{

    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << n << endl;
    cout << endl;
    if (n == 1 || n == 0)
    {
        return true;
    }
    if (a[0] > a[1])
    {
        return false;
    }

    bool isSmallSorted = isSorted(a + 1, n - 1);
    /*if(isSmallSorted){
        return true;
    }
    else{
        return false;
    }*/
    return isSmallSorted;
}
bool isSorted2(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << n << endl;
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (a[n - 2] > a[n - 1])
    {
        return false;
    }
    bool isSmallSorted2 = isSorted2(a, n - 1);
    return isSmallSorted2;
}
int main()
{
    int n;
    int a[n];
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (isSorted2(a, n))
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not sorted" << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    if (isSorted(a, n))
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not sorted" << endl;
    }

    return 0;
}