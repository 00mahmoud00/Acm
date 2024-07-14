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
    long long x = 16, y = 3, k = 2;
    cin >> x >> y >> k;

    cout << "x = " << x << ", y = " << y << ", k = " << k << endl;
    while (x > y && k > 0)
    {
        int diff = y - (x - (x / y) * y);
        if (k >= diff)
        {
            k -= diff;
            x += diff;
            while (x % y == 0)
                x /= y;
        }
        else
        {
            x += k;
            k = 0;
        }
    }

    cout << x << endl;
    // while (k > 0)
    // {
    //     int diff = y - (x - (x / y) * y);
    //     if (k >= diff)
    //     {
    //         k -= diff;
    //         x += diff;
    //         while (x % y == 0)
    //             x /= y;
    //     }
    //     else
    //     {
    //         x += k;
    //         k = 0;
    //     }
    // }
    // cout << x << endl;
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