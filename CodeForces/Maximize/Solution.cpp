#include <bits/stdc++.h>
using namespace std;
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
void FastIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void ReadWriteIO()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}

int inputMultiple()
{
    int t;
    cin >> t;
    return t;
}

long long gcd(long long a, long long b)
{
    return (!b ? a : gcd(b, a % b));
}

void solve()
{
    int x;
    cin >> x;
    int mx = 0, ans = 0;
    for (int i = 1; i < x; i++)
    {
        if (mx < max(mx, gcd(x, i) + i))
        {
            ans = i;
            mx = gcd(x, i) + i;
        }
    }
    cout << ans << endl;
}

int main()
{
    // ReadWriteIO();
    // FastIO();
    int t;
    cin >> t;
    while(t--)
        solve();
}