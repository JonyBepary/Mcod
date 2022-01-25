#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    // ll ara[] = {1, 1, 1, 1, 1, 1, 1, 1};
    ll ara[] = {12, 32, 2, 544, 34, 45, 23, 45, 37, 42, 86, 95, 23, 67};
    int sizeof_ara = sizeof(ara) / sizeof(ara[0]);
    ll prefi[sizeof_ara] = {[0] = ara[0]};
    for (int i = 1; i < sizeof_ara; i++)
    {
        prefi[i] = prefi[i - 1] + ara[i];
    }
    int t;
    cout << "Enter the number of test case: ";
    cin >> t;
    for (int r, l; t; t--)
    {
        cout << "Enter the range: ";
        cin >> l >> r;
        cout << prefi[r] - prefi[l - 1] << endl;
    }
    cout << endl;
    return 0;
}
