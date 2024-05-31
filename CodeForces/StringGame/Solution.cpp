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

ll k, n;

vector<ll> vec;

bool isValid(ll councilsCount)
{
    ll sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += min(vec[i], councilsCount);
    }

    return ceil(sum / k) >= councilsCount;
}
void solve()
{
    cin >> k >> n;
    vec.resize(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    ll l = 0, r = 1e18, ans = 0;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (isValid(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans << endl;
}

int main()
{
    // ReadWriteIO();
    // FastIO();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}