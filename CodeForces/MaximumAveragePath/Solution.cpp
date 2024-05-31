#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

void ReadWriteIO()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}

int n, m;
map<int, map<int, int>> graph;
const int maxn = 1e5 + 10;
vector<bool> visited;
// vector<pair<int, int>> graph;
bool dfs(int vertex, ll averave, ll sum, ll edgsCount, bool printAns = false)
{
    if (visited[vertex])
        return true;

    if (vertex == n)
    {
        if (edgsCount != 0 && averave * edgsCount == sum)
        {
            if (printAns)
                visited[vertex] = true;
            return true;
        }
        return false;
    }

    if (printAns)
        visited[vertex] = true;

    for (auto [edge, weight] : graph[vertex])
    {
        if (dfs(edge, averave, sum + weight, edgsCount + 1, printAns))
            return true;
    }

    if (printAns)
        visited[vertex] = false;

    return false;
}

void solve()
{
    cin >> n >> m;
    visited.resize(n + 10);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    ll l = 0, r = 2;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (dfs(1, m, 0, 0, false))
            l = m;
        else
            r = m;
    }

    // cout << l << endl;
    dfs(1, l, 0, 0, true);
    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (visited[i])
            ans++;

    // Print the Answer
    cout << ans - 1 << endl;
    for (int i = 0; i <= n; i++)
        if (visited[i])
            cout << i << " ";
    cout << endl;
}

int main()
{
    // ReadWriteIO();
    FastIO;
    //  int t;
    //  cin >> t;
    //  while (t--)
    solve();
}