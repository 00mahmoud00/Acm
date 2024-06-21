#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define NO cout << "-1\n"
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
    int a, b;
    cin >> a >> b;

    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < (s.size() / 2); i++)
    {
        if (s[i] == '?' && s[n - i - 1] != '?')
            s[i] = s[n - i - 1];

        else if (s[i] != '?' && s[n - i - 1] == '?')
            s[n - i - 1] = s[i];

        else if (s[i] != s[n - i - 1])
        {
            NO;
            return;
        }
    }

    a -= count(s.begin(), s.end(), '0');
    b -= count(s.begin(), s.end(), '1');
    int comma = count(s.begin(), s.end(), '?');

    if (a < 0 || b < 0 || (a + b) != comma || (s.size() % 2 == 1 && s[s.size() / 2] == '?' && a % 2 == 0 && b % 2 == 0))
    {
        NO;
        return;
    }

    if (a % 2 == 1 || b % 2 == 1)
    {
        int mid = s.size() / 2;
        
        if (a % 2 != 0)
            a--, s[mid] = '0';
        else
            b--, s[mid] = '1';
    }

    if (a % 2 == 1 || b % 2 == 1)
    {
        NO;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            if (a > 0)
            {
                s[i] = s[n - i - 1] = '0';
                a -= 2;
            }
            else
            {
                s[i] = s[n - i - 1] = '1';
                b -= 2;
            }
        }
    }
    cout << s << endl;
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