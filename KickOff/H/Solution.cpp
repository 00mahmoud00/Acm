#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int s = n / m;
    if (s >= 150)
        cout << "VERY HAPPY\n";
    else if (s >= 100)
        cout << "HAPPY\n";
    else
        cout << "SAD\n";
}

int main()
{
    // readFromFile();
    // FastIO
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}