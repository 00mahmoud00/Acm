#include <bits/stdc++.h>
using namespace std;
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

int leftmost(vector<long long> &arr, int n, int target)
{
    int l = 0, r = n - 1;

    if (arr[r] < target)
        return 1e9;

    int ans = 1e9;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (arr[m] >= target)
        {
            ans = m;
            r = m - 1;
        }

        else
        {
            l = m + 1;
        }
    }
    return ans;
}

int rightmost(vector<long long> &arr, int n, int target)
{
    int l = 0, r = n - 1;

    if (arr[0] > target)
        return 1e9;

    int ans = 1e9;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (arr[m] <= target)
        {
            ans = m;
            l = m + 1;
        }

        else
        {
            r = m - 1;
        }
    }
    return ans;
}
void solve()
{
    int n, k;
    cin >> n;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        int left = lower_bound(vec.begin(), vec.end(), l) - vec.begin(), right = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
        cout << right - left << " ";
    }
}

int main()
{
    // ReadWriteIO();
    FastIO();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}