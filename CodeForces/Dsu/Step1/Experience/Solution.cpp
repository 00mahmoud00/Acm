#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n";
// #define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
void FastIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void ReadWriteIO()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}
struct Task
{
    string Name;
    int U, V;
    Task() {}
    Task(string name, int u, int v)
    {
        Name = name;
        U = u;
        V = v;
    }
};

int const maxn = 3e5 + 10;
int p[maxn], dsusize[maxn], n, m, k;
Task tasks[maxn];

int get(int a)
{
    return p[a] = (p[a] == a ? a : get(p[a]));
}
void mrg(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
        return;

    if (dsusize[a] > dsusize[b])
        swap(a, b);

    p[a] = b;
    dsusize[b] += dsusize[a];
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= maxn; i++)
    {
        p[i] = i;
        dsusize[i] = 1;
    }

    while (m--)
    {
        int u, v;
        cin >> u >> v;
    }

    for (int i = 0; i < k; i++)
    {
        string name;
        int u, v;
        cin >> name >> u >> v;
        tasks[i] = Task(name, u, v);
    }

    vector<bool> ans;
    for (int i = k - 1; i >= 0; i--)
    {
        if (tasks[i].Name == "ask")
            ans.push_back(get(tasks[i].U) == get(tasks[i].V));
        else
            mrg(tasks[i].U, tasks[i].V);
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << (ans[i] ? "YES" : "NO") << "\n";
}

int main()
{
    ReadWriteIO();
    //   FastIO();
    //   int t;
    //   cin >> t;
    //   while (t--)
    solve();
}