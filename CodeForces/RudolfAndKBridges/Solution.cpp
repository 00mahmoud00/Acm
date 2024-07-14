#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    // freopen(output.c_str(), "w", stdout);
#endif
}
struct myQueue
{
    queue<int> queue, min;

    void push(int val)
    {
        queue.push(val);
        int queue_min = min.back();
        if (val > queue_min)
        {
            min.pop();
            min.push(val);
            min.back(queue_min);
        }
        else
        {
            min.back(val);
        }
    }

    void erase_top()
    {
        int queue_min = min.back();
        int queue_back = queue.back();
        if (queue_min == queue_back)
            min.pop();
        queue.pop();
    }
};
long long n, m, k, d;
vector<vector<ll>> vec;

long long calc(int row)
{
    vector<ll> dp(m + 1, 1e18);
    multiset<ll> ms;

    for (int i = m - 1; i >= 0; i--)
    {
        if (ms.size() > d + 1)
            ms.erase(ms.find(dp[i + d + 2]));

        dp[i] = vec[row][i] + 1 + *ms.begin();
        ms.insert(dp[i]);
    }
    return dp[0];
}

void solve()
{
    cin >> n >> m >> k >> d;
    vec.resize(n, vector<ll>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> vec[i][j];

    vector<long long> rows(n, 0);

    for (int i = 0; i < n; i++)
        rows[i] = calc(i);

    for (int i = 1; i < n; i++)
        rows[i] += rows[i - 1];

    long long p1 = 0, p2 = k - 1, ans = rows[p2];
    while (p1 < n && p2 < n)
    {
        ans = min((long long)ans, rows[p2] - (p1 == 0 ? 0 : rows[p1 - 1]));
        p1++, p2++;
    }

    cout << ans << endl;
    vec.clear();
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