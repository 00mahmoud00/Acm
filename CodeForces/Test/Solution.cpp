#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
using namespace std;

void ReadWriteIO()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}

void PrinVec(vector<long long> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void solve()
{
    int n = 5, m = 2;
    // cin >> x >> n;

    vector<long long> a(n + 1), b(n + 1);
    for (int i = 0; i <= n; i++)
        a[i] = i;

    // PrinVec(a);
    bool ans = false;
    while (m-- > 0)
    {
        for (int i = 0; i <= n; i++)
        {
            b[i] = a[i];
            if (i > 0)
                b[i] |= a[i - 1];
            if (i < n)
                b[i] |= a[i + 1];
        }

        for (int i = 0; i <= n; i++)
            a[i] = b[i];

        cout << "m = " << m << ": ";
        PrinVec(a);
    }
    // PrinVec(a);
    cout << (ans ? "Yes" : "No") << endl;
    cout << a[n] << endl;
}

int main()
{
    ReadWriteIO();
    // FastIO
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}