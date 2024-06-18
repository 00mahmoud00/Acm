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

bool checkK(long long k, long long n)
{
    if (k % 2 == 1)
        return false;

    long long xx = 1, sum = 0;
    while (n - xx > 0)
    {
        sum += 2 * (n - xx);
        xx += 2;
    }

    if (k > sum)
        return false;
    return true;
}
void solve()
{
    // long long n = 1, k = 1000000000000;
    // long long n = 3, k = 4;
    long long n, k;
    cin >> n >> k;
    vector<long long> ans(n + 1, 0);

    if (!checkK(k, n))
    {
        cout << "NO\n";
        return;
    }

    long long extrasteps = 0, elm = 1, x = 1;
    while (k > 0)
    {
        long long idx = 1 + extrasteps;
        long long swaps = min(2 * (n - x), k) / 2;
        idx += swaps;
        ans[idx] = elm;
        k -= swaps * 2;
        elm++;
        extrasteps++;
        x += 2;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            ans[i] = elm;
            elm++;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    readFromFile();
    // FastIO;
    int t;
    cin >> t;
    while (t--)
        solve();
}