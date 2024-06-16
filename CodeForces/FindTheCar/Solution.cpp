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

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> a(k), b(k), cumsum(k);

    for (int i = 0; i < k; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> b[i];

    cumsum[0] = b[0];
    for (int i = 1; i < k; i++)
        cumsum[i] = cumsum[i - 1] + b[i];

    while (q--)
    {
        int x;
        cin >> x;

        int idx = lower_bound(a.begin(), a.end(), x) - a.begin();

        if (x == a[idx])
        {
            cout << b[idx] << " ";
            continue;
        }

        long long ans = (idx == 0 ? 0 : b[idx - 1]);
        long long remain = x - (idx == 0 ? 0 : a[idx - 1]);

        if (idx != n)
        {
            // long double speed = (long double)(a[idx] - (idx == 0 ? 0 : a[idx - 1])) /);
            // long long speed = (a[idx] - (idx == 0 ? 0 : [idx - 1])) / (a[idx] - (idx == 0 ? 0 : a[idx - 1]));
            // cout << "b: " << b[idx] << "  " << (idx == 0 ? 0 : b[idx - 1]) << endl;
            // cout << "a: " << a[idx] << "  " << (idx == 0 ? 0 : a[idx - 1]) << endl;
            // cout << "speed = " << speed << endl;
            ans += (remain * (b[idx] - (idx == 0 ? 0 : b[idx - 1]))) / (a[idx] - (idx == 0 ? 0 : a[idx - 1]));
        }
        cout << ans << " ";
    }
    // cout << "====================";
    cout << endl;
}

int main()
{
    readFromFile();
    FastIO;
    ShowPoint;
    int t;
    cin >> t;
    while (t--)
        solve();
}