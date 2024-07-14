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
    long long x, y, k;
    cin >> x >> y >> k;

    while (k > 0 && x != 1)
    {
        long long num = y - (x % y);
        if (num > k)
        {
            x += k;
            k = 0;
        }
        else
        {
            x += num;
            k -= num;
            while (x % y == 0)
                x /= y;
        }
        // cout << "k = " << k << endl;
    }
    cout << x + (k % (y - 1)) << endl;
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