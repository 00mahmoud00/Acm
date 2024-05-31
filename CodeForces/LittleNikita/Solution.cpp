#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
void solve()
{
    int n, m;
    cin >> n >> m;
    cout << ((n >= m) && (n % 2 == m % 2) ? "Yes" : "No") << endl;
}

int main()
{
    // ReadWriteIO();
    // FastIO();
    int t;
    cin >> t;
    while (t--)
        solve();
}