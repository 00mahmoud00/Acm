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
int p[maxn], sizedsu[maxn], n, m;
int get(int a)
{
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void mrg(int a, int b)
{
    a = get(a);
    b = get(b);

    if (sizedsu[a] > sizedsu[b])
        swap(a, b);

    p[a] = b;
    sizedsu[b] += sizedsu[a];
}
void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        string query;
        int u, v;
        cin >> query >> u >> v;
        if (query == "get")
        {
            cout << (get(u) == get(v) ? "Yes" : "No") << endl;
        }
        else
        {
            mrg(u, v);
        }
    }
}

int main()
{
    // ReadWriteIO();
    //  FastIO();
    //  int t;
    //  cin >> t;
    //  while (t--)
    solve();
}