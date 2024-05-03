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
    int pref;
    int suf;
    int seg;
    node(){};
    node(int sum, int pref, int suf, int seg)
    {
        this->value = sum;
        this->pref = pref;
        this->suf = suf;
        this->seg = seg;
    }

    void display()
    {
        cout << "SUM: " << value << "\npref: " << pref << "\nsuf: " << suf << "\nseg: " << seg << endl;
    }
    int getSeg()
    {
        return seg;
    }
};
const int N = 1e5 + 5;
int a[N];
node st[4 * N];

node out()
{
    return node(0, 0, 0, 0);
}

node func(node a, node b)
{
    return node(
        a.value + b.value,
        max(a.pref, a.value + b.pref),
        max(b.suf, b.value + a.suf),
        max(a.seg, max(b.seg, a.suf + b.pref)));
}

void build(int ind, int l, int r)
{
    if (l == r)
    {
        st[ind] = node(a[l], a[l], a[l], a[l]);
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
        st[ind] = node(x, x, x, x);
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid)
    {
        update(i, x, 2 * ind, l, mid);
    }
    else
    {
        update(i, x, 2 * ind + 1, mid + 1, r);
    }
    st[ind] = func(st[ind * 2], st[ind * 2 + 1]);
}

node get(int ql, int qr, int ind, int l, int r)
{
    if (qr < l || r < ql)
    {
        return out();
    }
    if (ql <= l && r <= qr)
    {
        return st[ind];
    }
    int mid = (l + r) / 2;
    return func(get(ql, qr, ind * 2, l, mid), get(ql, qr, ind * 2 + 1, mid + 1, r));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ans(m + 1);
    int ansPointer = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    build(1, 0, n - 1);
    node node = get(0, n - 1, 1, 0, n - 1);
    ans[ansPointer++] = node.seg < 0 ? 0 : node.seg;
    // node.display();

    while (m--)
    {
        int value, idx;
        cin >> idx >> value;
        update(idx, value, 1, 0, n - 1);
        node = get(0, n - 1, 1, 0, n - 1);
        ans[ansPointer++] = node.seg < 0 ? 0 : node.seg;
        // node.display();
    }

    for (auto it : ans)
        cout << it << endl;
}

int main()
{
    // ReadWriteIO();
    // for (int i = 0; i < input(); i++)
    solve();
}