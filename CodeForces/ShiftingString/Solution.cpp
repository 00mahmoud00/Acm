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
string s;
long long n;

void dfs(int node, map<long long, vector<long long>> &graph, vector<long long> &visited, string &ans)
{
    // cout << "Node = " << node << endl;
    ans += s[node - 1];
    visited[node] = true;
    for (auto subnode : graph[node])
    {
        if (visited[subnode])
            continue;

        dfs(subnode, graph, visited, ans);
    }
    return;
}

long long lcm(vector<long long> &arr)
{
    if (arr.size() == 0)
        return 1;

    long long ans = arr[0];

    for (int i = 1; i < arr.size(); i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));

    return ans;
}
void solve()
{
    cin >> n >> s;

    map<long long, vector<long long>> graph;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        graph[i].push_back(x);
    }

    vector<long long> sizes, visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        string ss = "";
        dfs(i, graph, visited, ss);

        int sz = ss.size();
        string temp = ss + ss;

        int len = ss.size();
        for (int i = 1; i < sz; i++)
        {
            // circular shift the string
            string shift = temp.substr(i, sz);

            if (shift == ss)
            {
                len = i;
                break;
            }
        }
        sizes.push_back(len);
    }

    cout << lcm(sizes) << endl;
    // cout << "==========\n";
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