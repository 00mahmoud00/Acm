#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif
}

void solve()
{
    int n;
    cin >> n;
    vector<long long> veca(n), vecb(n);
    for (int i = 0; i < n; i++)
        cin >> veca[i];
    for (int i = 0; i < n; i++)
        cin >> vecb[i];
    int m;
    cin >> m;
    vector<long long> vecd(m);
    vector<bool> vecans(m, false);
    map<long long, vector<long long>> mp;
    for (int i = 0; i < m; i++)
    {
        cin >> vecd[i];
        mp[vecd[i]].push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (veca[i] == vecb[i])
            continue;

        if (mp[vecb[i]].size() == 0)
        {
            cout << "No\n";
            return;
        }
        int idx = mp[vecb[i]].back();
        mp[vecb[i]].pop_back();
        vecans[idx] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (veca[i] != vecb[i])
            continue;

        for (auto idx : mp[vecb[i]])
            vecans[idx] = true;

        mp[vecb[i]].clear();
    }

    if (vecans[m - 1] == false)
        cout << "No\n";
    else
        cout << "Yes\n";
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