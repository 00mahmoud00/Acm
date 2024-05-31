#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
using namespace std;

void ReadWriteIO()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}
int n;
vector<int> a, b;
void solve()
{
    cin >> n;
    a.resize(n);
    b.resize(n + 1);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        cin >> b[i];

    bool between = false;
    long long temp = a[0], ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i] - b[i]);
        between |= (a[i] <= b[n] && b[n] <= b[i]) || (b[i] <= b[n] && b[n] <= a[i]);

        if (abs(a[i] - b[n]) < abs(temp - b[n]))
            temp = a[i];

        if ((abs(b[i] - b[n]) < abs(temp - b[n])))
            temp = b[i];
    }

    cout << ans + (between ? 1 : (abs(temp - b[n]) + 1)) << endl;
}

int main()
{
    // ReadWriteIO();
    // FastIO
    int t;
    cin >> t;
    while (t--)
        solve();
}