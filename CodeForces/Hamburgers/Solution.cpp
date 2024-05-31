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

string s;
ll nb, ns, nc, pb, ps, pc, r;
ll countb = 0, counts = 0, countc = 0;

bool isValid(ll hamburgerNeed)
{
    ll needRubl = 0;
    needRubl += max(hamburgerNeed * countb - nb, (ll)0) * pb;
    needRubl += max(hamburgerNeed * countc - nc, (ll)0) * pc;
    needRubl += max(hamburgerNeed * counts - ns, (ll)0) * ps;

    return needRubl <= r;
}
void solve()
{
    cin >> s;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            countb++;
        if (s[i] == 'S')
            counts++;
        if (s[i] == 'C')
            countc++;
    }

    ll l = 0, r = 1e12 + 1000, ans = 0;
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