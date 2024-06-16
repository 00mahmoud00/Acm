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
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    bool breaki = false, breakj = false;

    for (int i = 0; i < n; i++)
    {
        if (breaki)
            break;
        for (int j = 0; j < m; j++)
        {
            if (breakj)
                break;

            if (arr[i][j] == '#')
            {
                int coun = 0;
                breaki = true;
                breakj = true;

                for (int k = i; k < n; k++)
                {
                    if (arr[k][j] == '#')
                        coun++;
                }

                cout << i + (coun + 1) / 2 << " " << j + 1 << endl;
            }
        }
    }
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