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
    ll n, x;
    cin >> n >> x;

    vector<ll> vec(n);

    for (auto &v : vec)
        cin >> v;

    int l = 0, r = 0, temp = 1, ans = 0;
    while (l < n && r < n)
    {
        if (temp * vec[r] % x != 0)
        {
            temp *= vec[r];
            r++;
        }

        else
        {
            temp = vec[r];
            r++;
            ans++;
            while (l < r)
                l++;
        }
    }

    cout << "l = " << l << ", r = " << r << endl;
    cout << ans << endl;
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