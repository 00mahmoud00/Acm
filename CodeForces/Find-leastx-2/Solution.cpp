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

const int N = 1e5 + 5;
int n, m, a[N], leftmost;
int st[4 * N];

void build(int ind, int l, int r)
{
    if (l == r)
    {
        st[ind] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l, mid);
    build(ind * 2 + 1, mid + 1, r);
    st[ind] = max(st[ind * 2], st[ind * 2 + 1]);
}

void update(int i, int x, int ind, int l, int r)
{
    if (l == r)
    {
        st[ind] = x;
        return;
    }

    int mid = (l + r) / 2;

    if (i <= mid)
        update(i, x, 2 * ind, l, mid);
    else
        update(i, x, 2 * ind + 1, mid + 1, r);

    st[ind] = max(st[ind * 2], st[ind * 2 + 1]);
}

int get(int l, int r, int target, int idx)
{
    if (l == r)
    {
        if (r == (n - 1) && st[idx] < target)
            return 1e9;
        return l;
    }

    int mid = (l + r) / 2;

    int val1 = 1e9, val2 = 1e9;

    if (target <= st[2 * idx] && mid >= leftmost)
        val1 = get(l, mid, target, 2 * idx);

    if (val1 != 1e9)
        return val1;

    if (target <= st[2 * idx + 1])
        val2 = get(mid + 1, r, target, 2 * idx + 1);

    return min(val1, val2);
}
void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);

    while (m--)
    {
        int type, iOrx, v;
        cin >> type >> iOrx;
        if (type == 1)
        {
            cin >> v;
            update(iOrx, v, 1, 0, n - 1);
            a[iOrx] = v;
        }
        else
        {
            cin >> leftmost;
            int ans = get(0, n - 1, iOrx, 1);
            cout << (ans == 1e9 ? -1 : ans) << endl;
        }
    }
}

int main()
{
    // ReadWriteIO();
    // for (int i = 0; i < input(); i++)
    FastIO();
    solve();
}