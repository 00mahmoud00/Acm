#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    // freopen(output.c_str(), "w", stdout);
#endif
}

bool all(vector<string> &s, int st, int end, int m)
{
    bool ans = true;

    vector<bool> frq(m + 1, false);
    for (int i = st; i <= end; i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            frq[j] = frq[j] || (s[i][j] == 'o');
        }
    }

    for (int i = 0; i < m; i++)
        ans &= frq[i];
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int res = 1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            bool ans = all(s, i, j,m);
            if (ans)
            {
                res = min(res, j - i + 1);
            }
        }
    }

    cout << res << endl;
}
int main()
{
    // readFromFile();
    // FastIO
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}