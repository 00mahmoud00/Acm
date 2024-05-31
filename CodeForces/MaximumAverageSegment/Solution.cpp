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

int n, d;
const int maxn = 1e5 + 10;
vector<double> vec(maxn), cumsum(maxn), minimum(maxn, 1e9), minidx(maxn);
vector<vector<pair<int, int>>> graph;
vector<bool> visited(n, false);

bool dfs(int vertex, ll averave, ll sum, ll edgsCount, bool printAns = false)
{
    if (visited[vertex])
        return true;

    if (vertex == n)
        return averave * edgsCount == sum;

    for(auto [])
}

void solve()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int l = 0, r = 101;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (isgood(m))
            r = m;
        else
            l = m;
    }

    cout << r << endl;
    isgood(r, true);
}

int main()
{
    ReadWriteIO();
    FastIO;
    //  int t;
    //  cin >> t;
    //  while (t--)
    solve();
}