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

int n, m, k;
string s;

bool can_go(int i, int swimCount)
{
    if (i > n + 1)
        return true;

    if (swimCount > k)
        return false;

    if (s[i] == 'C')
        return false;

    if (s[i] == 'L')
    {
        if (i + m > n + 1)
            return true;

        for (int idx = i + 1; idx <= i + m; idx++)
        {
            if (s[idx] == 'L')
                return can_go(idx, swimCount);
        }
        
        return can_go(i + m, swimCount);
    }

    return can_go(i + 1, swimCount + 1);
}
void solve()
{
    s = "L";
    cin >> n >> m >> k;
    string temp;
    cin >> temp;
    s += temp;
    s += "L";
    cout << (can_go(0, 0) ? "YES" : "NO") << endl;
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
