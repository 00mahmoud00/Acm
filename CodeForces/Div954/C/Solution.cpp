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
    string s;
    cin >> s;

    set<int> indices;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        indices.insert(x);
    }

    string replace;
    cin >> replace;
    sort(replace.begin(), replace.end());

    // cout << replace << endl;
    int idx = 0;
    for (auto it : indices)
    {
        s[it - 1] = replace[idx];
        idx++;
    }

    cout << s << endl;
    // cout << "===========\n";
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