#include <bits/stdc++.h>
using namespace std;
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

int n, m, d;
const int Max = 1e6;
map<int, map<int, int>> graph;
map<int, bool> visited;
vector<int> parent(Max);

bool bfs(int limit)
{
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty())
    {
        auto [vertex, taken] = q.front();
        q.pop();

        if (vertex == n)
            return true;

        if (taken == d)
            continue;

        for (auto [k, w] : graph[vertex])
        {
            if (w > limit || visited[k])
                continue;

            visited[k] = true;
            parent[k] = vertex;
            q.push({k, taken + 1});
        }
    }

    return false;
}

void solve()
{
    cin >> n >> m >> d;
    int l = 0, r = 2147483647;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // l = min(l, c);
        // r = max(r, c);

        graph[a][b] = c;
    }

    // l--;
    // r++;
    bool found = false;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;

        visited.clear();
        if (bfs(m))
        {
            r = m;
            found = true;
        }
        else
            l = m;
    }
    if (!found)
    {
        cout << -1 << endl;
        return;
    }

    visited.clear();
    bfs(r);

    int x = n;
    vector<int> result;
    while (x != 1)
    {
        result.push_back(x);
        x = parent[x];
    }
    result.push_back(1);
    cout << result.size() - 1 << endl;
    for (auto it = result.rbegin(); it != result.rend(); it++)
        cout << *it << " ";
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
// 1 2 3  5  7    11