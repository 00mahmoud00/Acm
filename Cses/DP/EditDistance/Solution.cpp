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

string s, t;
vector<vector<int>> dp(5001, vector<int>(5001, -1));

int calc(int i, int j)
{
    if (i == s.size())
        return t.size() - j;

    if (j == t.size())
        return s.size() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = calc(i + 1, j + 1);

    return dp[i][j] = 1 + min({calc(i, j + 1), calc(i + 1, j), calc(i + 1, j + 1)});
}
void solve()
{
    cin >> s >> t;
    cout << calc(0, 0) << endl;
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