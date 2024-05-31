#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
using namespace std;

void ReadWriteIO()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}
int poweroftwo[32];
void solve()
{
    int x;
    cin >> x;
}

int main()
{
    // ReadWriteIO();
    // FastIO
    for (int i = 0; i < 32; i++)
        poweroftwo[i] = 1 << i;
    int t;
    cin >> t;
    while (t--)
        solve();
}