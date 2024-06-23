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
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    int ans = 1e9;
    for (int i = 1; i <= 10; i++)
    {
        ans = min(ans, abs(x1 - i) + abs(x2 - i) + abs(x3 - i));
    }
    // int a = min(min(x1, x2), x3);
    // cout << abs(x1 - a) + abs(x2 - a) + abs(x3 - a) << endl;
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