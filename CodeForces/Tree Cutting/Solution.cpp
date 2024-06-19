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
int n, k;
map<int, vector<int>> tree;
vector<int> parent, weight, visited;

int dfs(int node, int size, int &ans, int &total)
{
    if (visited[node])
        return 0;

    visited[node] = true;
    int w = 1;
    for (auto subnode : tree[node])
    {
        if (subnode == node)
            continue;

        int ww = dfs(subnode, size, ans, total);
        if (ww >= size && (total - ww) >= size)
        {
            total -= ww;
            ans++;
            // w = 1;
        }
        else
            w += ww;
    }
    return w;
}

void solve()
{
    cin >> n >> k;

    visited.resize(n + 1, false);
    parent.resize(n + 1, -1);
    weight.resize(n + 1, 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int l = 0, r = 1e6, ans = 0, cutcounts = 0, total = n;
    while (l <= r)
    {
        cutcounts = 0;
        total = n;

        int mid = (l + r) / 2;
        // cout << "l = " << l << ", r = " << r << ", mid = " << mid << endl;
        dfs(1, mid, cutcounts, total);
        // cout << "cutcount = " << cutcounts << endl;
        if (cutcounts >= k)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;

        visited.clear();
        visited.resize(n + 1, 0);
    }
    cout << ans << endl;

    visited.clear();
    tree.clear();
    weight.clear();
    parent.clear();
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