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

void solve()
{
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> mp;

    vector<pair<int, pair<int, int>>> p(q);
    int x, l, r;
    int idx = 0;
    while (idx < q)
    {
        cin >> p[idx].first >> p[idx].second.first >> p[idx].second.second;
        idx++;
    }

    bool ans = false;
    for (int i = 0; i < q; i++)
    {
        bool cut = false;

        for (int idx = 1; idx <= n; idx++)
            mp[idx].resize(1010);

        for (int j = 0; j < q; j++)
        {
            if (i == j)
                continue;

            mp[p[j].first][p[j].second.first]++;
            mp[p[j].first][p[j].second.second + 1]--;
        }

        for (auto &it : mp)
        {
            for (int idx = 1; idx < it.second.size(); idx++)
                it.second[idx] += it.second[idx - 1];
        }

        for (auto it : mp)
        {
            for (int idx = 0; idx < it.second.size(); idx++)
            {
                if (it.second[idx] > 1)
                    cut = true;
            }
        }

        if (cut == false)
            ans = true;

        for (auto it : mp)
            it.second.clear();

        mp.clear();
    }

    cout << (ans ? "YES\n" : "NO\n");
}

int main()
{
    readFromFile();
    FastIO;
    int t;
    cin >> t;
    while (t--)
        solve();
}