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
    long long n, x;
    cin >> n >> x;
    vector<long long> fre(x + 2, 0);
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        fre[num]++;
    }

    for (int i = 1; i < x; i++)
    {
        if (fre[i] % (i + 1) == 0)
        {
            long long num = (fre[i] / (i + 1));
            fre[i + 1] += num;
            // fre[i] -= num;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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