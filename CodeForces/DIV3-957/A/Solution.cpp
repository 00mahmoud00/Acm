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
    int a, b, c;
    cin >> a >> b >> c;

    int ans = a * b * c;
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            for (int k = 0; k <= 5; k++)
            {
                if (i + j + k == 5)
                {
                    ans = max(ans, ((a + i) * (b + j) * (c + k)));
                }
            }
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