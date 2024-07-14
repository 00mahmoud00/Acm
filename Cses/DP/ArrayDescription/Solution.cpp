#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
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
    int n, m;
    cin >> n >> m;
    vector<ll> vec(n);
    for (auto &it : vec)
        cin >> it;

    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    if (vec[0] != 0)
        dp[0][vec[0]] = 1;
    else
    {
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (vec[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= Mod;

                if (j - 1 >= 1)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= Mod;
                }

                if (j + 1 <= m)
                {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= Mod;
                }
            }
        }

        else
        {
            dp[i][vec[i]] += dp[i - 1][vec[i]];
            dp[i][vec[i]] %= Mod;

            if (vec[i] - 1 >= 1)
            {
                dp[i][vec[i]] += dp[i - 1][vec[i] - 1];
                dp[i][vec[i]] %= Mod;
            }

            if (vec[i] + 1 <= m)
            {
                dp[i][vec[i]] += dp[i - 1][vec[i] + 1];
                dp[i][vec[i]] %= Mod;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += dp[n - 1][i];
        ans %= Mod;
    }
    cout << ans << endl;
}

int main()
{
    readFromFile();
    // FastIO
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}