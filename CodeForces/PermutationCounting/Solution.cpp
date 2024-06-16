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
long long n, k;
vector<long long> vec;

bool canConstruct(long long x)
{
    long long conis = 0;
    for (auto v : vec)
        conis += (v >= x ? 0 : (x - v));
    return conis <= k;
}

void solve()
{
    cin >> n >> k;
    vec.resize(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    long long l = 0, r = 2e12, ans = 0, rem = 0, res = 0;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (canConstruct(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    res = ans * n - (n - 1);
    for (int i = 0; i < n; i++)
    {
        if (vec[i] >= ans)
            continue;

        k -= (ans - vec[i]);
        vec[i] = ans;
    }

    for (int i = 0; i < n && k > 0; i++)
    {
        if (vec[i] > ans)
            continue;

        vec[i]++;
        k--;
    }

    for (int i = 0; i < n; i++)
        res += (vec[i] > ans);

    cout << res << endl;
    vec.clear();
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