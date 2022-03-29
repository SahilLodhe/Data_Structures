#include <bits/stdc++.h>
using namespace std;

int lastelement(int a[], int n, int x, int i)
{
    //base case
    if (i == -1)
    {
        cout << "element not found" << endl;
        return -1;
    }
    if (a[i] == x)
    {
        cout << "the element is found last at :" << endl;
        return i;
    }
    //recursive step
    int flag = lastelement(a, n, x, i - 1);
    //calculation step
    return flag;
}
int main()
{

    //int n;
    //int x;
    //int a[n];
    //cout << "enter the limit" << endl;
    //cin >> n;
    //cout << "enter the number to be found" << endl;
    //cin >> x;
    //cout << "enter the elements of the array" << endl;
    //int i = n - 1;
    //for (int i = 0; i < n; i++)
    //{
    //    cin >> a[i];
    //}
    int x = 6;
    int n = 9;
    int i = 8;
    int a[] = {1,2,3,3,4,5,6,6,7};
    
    cout << lastelement(a, n, x, i);
    return 0;
}