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

    int arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int mx = 0;

            int n1 = i > 0 ? arr[i - 1][j] : 0;
            int n2 = i < n - 1 ? arr[i + 1][j] : 0;
            int n3 = j > 0 ? arr[i][j - 1] : 0;
            int n4 = j < m - 1 ? arr[i][j + 1] : 0;

            mx = max(mx, n1);
            mx = max(mx, n2);
            mx = max(mx, n3);
            mx = max(mx, n4);

            if (
                n1 < arr[i][j] &&
                n2 < arr[i][j] &&
                n3 < arr[i][j] &&
                n4 < arr[i][j])
                arr[i][j] = mx;
            // cout << mx << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
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