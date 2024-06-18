#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    // freopen(output.c_str(), "w", stdout);
#endif
}
long long n, a, b;
void solve()
{
    cin >> n >> a >> b;

    long long ans = 0, l = 0, r = 1e18;
    // cout << a << " " << b << " " << n << endl;
    if (a > b)
        cout << n * a << endl;
    else
    {
        int nn = min((b - a), n);
        // cout << "nn = " << nn << endl;
        long long first = b - a;
        long long last = b - (nn - 1) - a;
        // cout << first << "  " << last << endl;
        long long extra = ((first + last) * nn) / 2;
        ans += n * a;
        ans += extra;
        // ans += (nn * (nn + 1) / 2);
        cout << ans << endl;
        // cout << "================\n";
    }
    // for (long long i = 0; i <= min(n, b); i++)
    // {
    // }
    // while (l <= r)
    // {
    // long long mid = (l + r) / 2;
    // if ()
    // }
}

int main()
{
    readFromFile();
    // FastIO;
    int t;
    cin >> t;
    while (t--)
        solve();
}