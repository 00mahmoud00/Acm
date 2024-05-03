#include <bits/stdc++.h>
using namespace std;
typedef int int;
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

struct node
{
    int value;
    node() {}
    node(int sum)
    {
        this->value = sum;
    }
};
const int N = 1e5 + 5;
int a[N], leftmost;
node st[4 * N];
node out()
{
    return node(INT_MAX);
}

node func(node a, node b)
{
    return a.value >= b.value ? a : b;
}

void build(int ind, int l, int r)
{
    if (l == r)
    {
        st[ind].value = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l, mid);
    build(ind * 2 + 1, mid + 1, r);
    st[ind] = func(st[ind * 2], st[ind * 2 + 1]);
}

void update(int i, int x, int ind, int l, int r)
{
    if (l == r)
    {
        st[ind] = node(x);
        return;
    }

    int mid = (l + r) / 2;

    if (i <= mid)
        update(i, x, 2 * ind, l, mid);
    else
        update(i, x, 2 * ind + 1, mid + 1, r);

    st[ind] = func(st[ind * 2], st[ind * 2 + 1]);
}

int get(int l, int r, int target, int idx)
{
    if (st[idx].value < target)
        return -1;

    int mid = (l + r) / 2;
    if (l == r)
        return l;

    if (target <= st[2 * idx].value && mid >= leftmost)
        return get(l, mid, target, 2 * idx);
    return get(mid + 1, r, target, 2 * idx + 1);
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);
    // for (int i = 0; i < 4 * n; i++)
    // {
    //     cout << st[i].value << " ";
    // }
    // cout << endl;
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
            cout << get(leftmost, n - 1, iOrx, 1) << endl;
            // cout << get(0, n - 1, 1, 0, n - 1, value) << endl;
        }
    }
}

int main()
{
    ReadWriteIO();
    // for (int i = 0; i < input(); i++)
    solve();
}