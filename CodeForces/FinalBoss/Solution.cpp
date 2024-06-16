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
long long h, n;
vector<long long> a, c;
map<long long, long long> mp;

bool IsBeaten(long long x)
{
    long long ans = 0, health = h;
    x--;
    for (auto it : mp)
        health -= it.second;

    if(health <= 0)
        return true;
        
    for (auto it : mp)
    {
        // cout << "h = " << h << endl;
        // cout << "inBinary:  ans = " << ans << "  with x = " << x << endl;
        long long roundcounts = x / it.first;
        // long long xx = x;
        // for (long long i = 1; i <= x; i *= 2)
        // {
        // health -= ((i / it.first) * it.second);
        // xx -= i;
        // }
        while (roundcounts--)
        {
            health -= it.second;
            if (health <= 0)
                return true;
        }
        // health -= (xx / it.first) * it.second;
        if (health <= 0)
            return true;
        // ans += ((x / it.first) * it.second);
        // if (ans >= h)
        // return true;
    }
    // cout << "ans out of loop = " << ans << endl;
    // cout << (ans > h ? "Yes" : "No") << endl;
    return health <= 0;
    // return ans >= h;
}
void solve()
{
    cin >> h >> n;

    a.resize(n);
    c.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    for (int i = 0; i < n; i++)
        mp[c[i]] += a[i];

    // cout << "MAP: " << endl;
    // for (auto it : mp)
    // cout << it.first << " " << it.second << endl;

    long long l = 1, r = 41e10, ans = 0;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (IsBeaten(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
        // cout << l << "  " << r << endl;
        // cout << "======================\n";
    }

    // cout << "r = " << r << endl;
    cout << ans << endl;
    // cout << "==============\n";
    a.clear();
    c.clear();
    mp.clear();
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