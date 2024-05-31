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
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];

    for (int i = 0; i < k; i++)
        cin >> b[i];

    vector<int> minutes(k);

    for (int i = 0; i < k; i++)
        minutes[i] = b[i] - (i == 0 ? 0 : minutes[i - 1]);

    while (q--)
    {
        int x;
        cin >> x;
        int p = lower_bound(a.begin(), a.end(), x) - a.begin();
        int re = x - (p == 0 ? 0 : a[p - 1]);
        double speed = double(a[p] - (p == 0 ? 0 : a[p - 1])) / (double)minutes[p];
        cout << (p == 0 ? 0 : b[p - 1]) + (int)(re / speed) << " ";
    }
    cout << endl;
    // cout << "\n-------------------\n";
}

int main()
{
    ReadWriteIO();
    // FastIO();
    int t;
    cin >> t;
    while (t--)
        solve();
}