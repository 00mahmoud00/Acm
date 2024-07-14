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
    int n;
    cin >> n;
    vector<long long> vec(n);
    map<long long, long long> mp;
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int p1 = 0;
    for (int i = 1; i < n; i++)
    {
        if (vec[i] < vec[p1])
            mp[abs(vec[i] - vec[p1])]++;
        else
            p1 = i;
    }

    long long ans = 0;
    int allcount = 0;
    for (auto it : mp)
        allcount += it.second;

    // cout << "allcount = " << allcount << endl;
    long long minus = 0;
    for (auto it : mp)
    {
        // cout << it.first << " " << it.second << endl;
        long long num = it.first;
        num -= minus;
        ans += num * (allcount + 1);
        allcount -= it.second;
        minus = it.first;
    }
    cout << ans << endl;
    // cout << "\n============\n";
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