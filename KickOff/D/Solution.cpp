#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif
}

const int Mod = 998244353;
const int N = (int)2 * (int)1e5 + 5;
long long fac[N], ans[N];
void solve()
{
    long long n;
    cin >> n;
    cout << ans[n] << endl;
}

int main()
{
    // readFromFile();
    // FastIO
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = (i * (fac[i - 1] % Mod)) % Mod;

    for (int i = 0; i <= N; i++)
    {
        cout << "t";
        ans[i] = 0;
        for (int j = 0; j < i; j++)
        {
            ans[i] = (ans[i] % Mod + ((fac[i]) / (fac[j]))) % Mod;
        }
        // fac[i] = ((fac[i] % Mod) + (fac[i - 1] % Mod)) % Mod;
    }
    cout << "Heelo";
    int t;
    cin >> t;
    while (t--)
        solve();
}