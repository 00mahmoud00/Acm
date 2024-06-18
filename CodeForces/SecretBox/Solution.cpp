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
    long long x, y, z, k;
    cin >> x >> y >> z >> k;
    
    long long ans = 0;
    for (long long i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            long long twod = i * j;
            if (k % twod != 0)
                continue;

            long long s = k / twod;
            long long curans = (x - i + 1) * (y - j + 1) * (z - k / twod + 1);
            ans = max(curans, ans);
        }
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