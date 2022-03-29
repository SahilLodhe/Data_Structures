#include <bits/stdc++.h>
using namespace std;
int sum_of_array(int a[], int n)
{
    //base case
    if (n == 1)
    {
        return a[0]; //OR if(n == 0){return 0;}
    }
    //recursive n calculation step
    return a[0] + sum_of_array(a + 1, n - 1);
}
int sum_of_array2(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return a[n - 1] + sum_of_array2(a,n - 1);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << sum_of_array(a, n)<<endl;
    cout << sum_of_array2(a, n)<<endl;
    return 0;
}