#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    // freopen(output.c_str(), "w", stdout);
#endif
}
ll r, r1, r2;
bool calc(long long x, long long y)
{
    long long num = (x * x + y * y);
    // cout << "x = " << x << ",   y = " << y << ",  num = " << num << endl;
    // cout << r1 << "  " << r2 << endl;
    // cout << (r1 <= num && num < r2 ? "YES\n" : "NO\n");
    // r1 <= num &&
    return num < r2;
}

bool calc2(long long x, long long y)
{
    long long num = (x * x + y * y);
    return r1 <= num;
}

void solve()
{
    // r = 1;
    cin >> r;
    r1 = r * r;
    r2 = (r + 1) * (r + 1);

    // cout << r1 << "  " << r2 << endl;
    ll res = 0;
    for (ll i = 0; i <= r; i++)
    {
        long long l = 1, r = 1e10, ans0 = -1;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (calc(i, mid))
                ans0 = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        l = 0, r = ans0;
        ll ans1 = -1;

        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (calc2(i, mid))
                ans1 = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        // cout << i << "  " << ans1 << "  " << ans0 << endl;
        if (ans0 != -1 && ans1 != -1)
        {
            res += (ans0 - ans1 + 1) * 4;
            if (i == 0 || ans0 == 0 || ans1 == 0)
                res -= 2;
        }
    }

    cout << res << endl;
    // cout << "=======================\n";
}

int main()
{
    readFromFile();
    // FastIO
    int t;
    cin >> t;
    while (t--)
        solve();
}