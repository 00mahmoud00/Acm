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

int calc(vector<int> &vector, int i)
{
    int n = vector.size();
    return min(vector[i] + (i + 1 < n ? calc(vector, i + 1) : 0), vector[i] * (i + 1 < n ? calc(vector, i + 1) : 1));
}
void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> vec(n - 1);
    int ans = 1e9, vecidx = 0;
    for (int idx = 1; idx < n; idx++)
    {
        vec.clear();
        vec.resize(n - 1);
        vecidx = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == idx - 1)
                vec[vecidx++] = ((s[i] - '0') * 10 + (s[i + 1] - '0')), i++;
            else
                vec[vecidx++] = (s[i] - '0');
        }
        // cout << "idx = " << idx << endl;
        // for (auto e : vec)
            // cout << e << " ";
        // cout << endl;
        ans = min(ans, calc(vec, 0));
    }
    cout << ans << endl;
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