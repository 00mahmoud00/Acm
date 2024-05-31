#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
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

int inputMultiple()
{
    int t;
    cin >> t;
    return t;
}

ll n, k;
vector<ll> vec;

bool isValid(ll distance)
{
    int p1 = 0, p2 = 0;
    ll cowscount = 1;
    while (p1 < vec.size() && p2 < vec.size())
    {
        if (vec[p2] - vec[p1] >= distance)
        {
            p1 = p2;
            cowscount++;
        }
        else
            p2++;
    }

    return cowscount >= k;
}
void solve()
{
    cin >> n >> k;
    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    ll l = 0, r = 1e18;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        // cout << l << " " << r << endl;
        if (isValid(m))
            l = m;
        else
            r = m;
    }

    cout << l << endl;
}

int main()
{
    // ReadWriteIO();
    // FastIO();
    // int t;
    // cin >> t;
    // while (t--)/
    solve();
}