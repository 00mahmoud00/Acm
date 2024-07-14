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
    for (int x = 1; x < 10; x++)
    {
        for (int y = x; y < 10; y++)
        {
            for (int z = y; z < 10; z++)
            {
                if (x * y * z == 36)
                {
                    cout << x << " " << y << " " << z << " " << x + y + z << endl;
                }
            }
        }
    }
}

int main()
{
    readFromFile();
    // FastIO
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}