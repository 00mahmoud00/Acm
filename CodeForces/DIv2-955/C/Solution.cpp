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
    int n, l, r;
    cin >> n >> l >> r;
    vector<long long> vec(n);
    for (auto &v : vec)
        cin >> v;

    long long p1 = 0, p2 = 0, ans = 0, sum = 0;
    while (p1 < n && p2 < n)
    {
        if (sum < l && p2 < n)
            sum += vec[p2++];

        if (l <= sum && sum <= r)
        {
            ans++;
            sum = 0;
            p1 = p2;
        }

        if (sum > r)
            sum -= vec[p1++];
    }
    while (p1 < n)
    {
        if (l <= sum && sum <= r)
        {
            ans++;
            break;
        }
        sum -= vec[p1++];
    }
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