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

void solve()
{
    int n, sz;
    cin >> n;

    string s = to_string(n);
    sz = s.size();

    vector<pair<ll, ll>> ans;

    for (ll a = 1; a < 10001; a++)
    {
        ll min_b = max(1ll, a * sz - 5);
        ll max_b = sz * a;

        for (ll b = min_b; b < max_b; b++)
        {
            ll ansNumber = a * n - b;
            ll ansString = 0;

            for (int i = 0; i < sz * a - b; i++)
                ansString = 10 * ansString + (s[i % sz] - '0');

            if (ansNumber == ansString)
                ans.push_back(make_pair(a, b));
        }
    }

    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.first << ' ' << it.second << endl;
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
