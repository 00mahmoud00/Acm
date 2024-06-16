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

int power(int x, unsigned int y)
{
    int res = 1; // Initialize result

    while (y > 0)
    {
        if (y & 1)
            res = res * x;

        y = y >> 1;
        x = x * x;
    }
    return res;
}

bool isGood(long long &n, long long y)
{
    bool ans = false;
    for (long long i = 0; i < 1000000; i++)
    {
        long long num = abs(n - i * i);
        long long sq = sqrt(num);
        if (sq * sq == (num) && ((abs(sq * sq + i * i - n)) <= y))
            return true;
    }

    return ans;
}
void solve()
{
    long long n;
    cin >> n;

    long long ans = 1e18;
    long long l = 0, r = 1e12;
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;
        if (isGood(n, mid))
            r = mid;
        else
            l = mid;
        // cout << l << "  " << r << endl;
    }

    cout << l << endl;
}

int main()
{
    // readFromFile();
    // FastIO
    int t;
    cin >> t;
    while (t--)
        solve();
}