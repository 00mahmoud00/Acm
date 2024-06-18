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
void outputPermetation(long long n)
{
    for (int i = 1; i <= n; i++)
        cout << i << " ";
}
void solve()
{
    long long n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (i * (2 * i - 1));

    cout << ans << " " << 2 * n << endl;

    for (int i = n; i > 0; i--)
    {
        cout << 1 << " " << i << " ";
        outputPermetation(n);
        cout << endl;

        cout << 2 << " " << i << " ";
        outputPermetation(n);
        cout << endl;
    }
}

int main()
{
    // readFromFile();
    // FastIO
    int t;
    cin >> t;
    while (t--)
        solve();
}