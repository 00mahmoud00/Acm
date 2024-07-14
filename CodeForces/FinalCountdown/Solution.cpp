#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
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
    int n;
    cin >> n;

    string s;
    cin >> s;

    long long po = 1, ans = (s[n - 1] - '0');
    for (int i = n - 2; i >= 0; i--)
    {
        long long num = (s[i] - '0') * po;
        ans += (num * 9);
        ans += (num * 2);
        po *= 10;
    }
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