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

const int Mod = 1e9 + 7;
void solve()
{
    int n, k;
    // cin >> n >> k;
    n = 3, k = 0;

    int used = 0;
    for (int i = 0; i < k; i++)
    {
        int c, r;
        cin >> c >> r;
        used += (2 - (c == r));
    }

    long long dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] % Mod + (long long)2 * (i - 1) * dp[i - 2] % Mod) % Mod;
    cout << dp[n - used] << endl;
}

int main()
{
    readFromFile();
    // FastIO
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}