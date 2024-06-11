#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
typedef long long ll;
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    // freopen(output.c_str(), "w", stdout);
#endif
}

// ll modinverse(ll a, ll m)
// {
//     ll x, y;
//     ll d = extendedGcd(a, m, x, y);
//     return d == 1 ? -1 : (x + m) % m;
// }
void solve()
{
    int n = 57, m = 37;
    // cin >> n >> m;

    for (long long i = 1; i <= 20; i++)
        cout << (n ^ i) << "  " << (m ^ i) << endl;
}

int main()
{
    FastIO
    /// readFromFile();
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //  int t;
    //  cin >> t;
    //  while (t--)
    solve();
}