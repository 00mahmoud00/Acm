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

bool isValid(ll sum)
{
    ll summ = 0, segCount = 1;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > sum)
            return false;
            
        if (summ + vec[i] <= sum)
            summ += vec[i];
        else
        {
            segCount++;
            summ = vec[i];
        }
    }

    // if (summ <= sum)
    //     segCount++;

    return segCount <= k;
}
void solve()
{
    cin >> n >> k;
    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    ll l = 0, r = 1e16;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        // cout << l << " " << r << endl;
        if (isValid(m))
            r = m;
        else
            l = m;
    }

    cout << r << endl;
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