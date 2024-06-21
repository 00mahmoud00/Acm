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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int onesCount = 0;
    for (auto c : s)
        onesCount += (c == '1');

    if (onesCount % 2 != 0 || s[0] != '1' || s[s.size() - 1] != '1')
    {
        cout << "NO\n";
        return;
    }

    string a = "", b = "";
    int ones = 0;
    bool openzeros = true;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            string ch = (ones < (onesCount / 2) ? "(" : ")");
            a += ch;
            b += ch;
            ones++;
        }
        else
        {
            if (openzeros)
            {
                a += "(";
                b += ")";
            }
            else
            {
                a += ")";
                b += "(";
            }

            openzeros = !openzeros;
        }
    }
    cout << "YES" << endl
         << a << endl
         << b << endl;
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