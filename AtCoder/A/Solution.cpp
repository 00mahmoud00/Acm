#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
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
    int n, a;
    cin >> n >> a;
    vector<long long> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    vector<long long> ans(n);
    ans[0] = vec[0] + a;

    for (int i = 1; i < n; i++)
        ans[i] = max(vec[i], ans[i - 1]) + a;

    for (auto a : ans)
        cout << a << " ";
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