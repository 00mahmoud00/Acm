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
    int n, k;
    cin >> n >> k;

    vector<int> vec(k);
    for (auto &it : vec)
        cin >> it;

    sort(vec.begin(), vec.end());

    int ans = 0;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        ans += vec[i];
        ans += vec[i] - 1;
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