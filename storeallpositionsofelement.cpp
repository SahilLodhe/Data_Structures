#include <bits/stdc++.h>
using namespace std;
void saveallpos(int a[], int n, int x, int flag, vector<int> &ans)
{
    //base case
    if (flag == n)
    {
        return;
    }
    if (a[flag] == x)
    {
        ans.push_back(flag);
    }
    //recursive step
    saveallpos(a, n, x, flag + 1, ans);
    //calculation step
}
int main()
{
    int flag = 0;
    int n;
    cout << "enter the limit" << endl;
    cin >> n;
    int a[n];
    int x;
    cout << "enter the number to find" << endl;
    cin >> x;
    cout << "enter the elements of the array" << endl;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    saveallpos(a, n, x, flag, v);

    vector<int>::iterator it;
    cout << "the elements are present at positions : ";

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}