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
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = n; i >= k; i--)
        cout << i << " ";
    for (int i = m + 1; i < k; i++)
        cout << i << " ";
    for (int i = 1; i <= m; i++)
        cout << i << " ";
    cout << endl;
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