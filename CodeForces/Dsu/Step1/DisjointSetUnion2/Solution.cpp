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
int const maxn = 3e5 + 10;
int p[maxn], minm[maxn], maxm[maxn], dsusize[maxn], n, m;
int get(int a)
{
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void mrg(int a, int b)
{
    a = get(a);
    b = get(b);

    if(a == b)
        return;

    if (dsusize[a] > dsusize[b])
        swap(a, b);

    p[a] = b;
    minm[b] = min(minm[a], minm[b]);
    maxm[b] = max(maxm[a], maxm[b]);
    dsusize[b] += dsusize[a];
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= maxn; i++)
    {
        p[i] = i;
        maxm[i] = i;
        minm[i] = i;
        dsusize[i] = 1;
    }

    while (m--)
    {
        string query;
        int u, v;
        cin >> query;
        if (query == "get")
        {
            cin >> u;
            cout << minm[get(u)] << " " << maxm[get(u)] << " " << dsusize[get(u)] << endl;
        }
        else
        {
            cin >> u >> v;
            mrg(u, v);
        }
    }
}

int main()
{
    //ReadWriteIO();
    //  FastIO();
    //  int t;
    //  cin >> t;
    //  while (t--)
    solve();
}