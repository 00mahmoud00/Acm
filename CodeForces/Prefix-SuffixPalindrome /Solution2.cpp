#include <bits/stdc++.h>
#define ll long long
#define SD                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define flot(n) cout << setprecision(n) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
#define ar array
#define ld long double
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));
ll rand(ll x, ll y)
{
    return uniform_int_distribution<ll>(x, y)(rng);
}
const int INF = 0x3f3f3f3f;
const ll INFLL = 2e18;
const int mod = 1e9 + 9;
const ld eps = 1e-6;
int mul(int x, int y, int mod = mod) { return (long long)x * y % mod; }
int add(int x, int y, int mod = mod)
{
    x += y;
    return x < mod ? x : x - mod;
}
int sub(int x, int y, int mod = mod)
{
    x -= y;
    return x < 0 ? x + mod : x;
}
int power(int x, ll y, int mod = mod)
{
    if (!y)
        return 1;
    int ret = power(x, y / 2, mod);
    ret = mul(ret, ret, mod);
    if (y & 1)
        ret = mul(ret, x, mod);
    return ret;
}
const int N = 1e5 + 9;
const int sq = 500;
int n;
string s;
struct Hash
{
    int n, p1, p2, m1, m2, h1[N], h2[N], h3[N], h4[N], pw1[N], pw2[N];
    string s;
    void init(string &str, int _p1, int _p2, int _m1, int _m2)
    {
        p1 = _p1;
        p2 = _p2;
        m1 = _m1;
        m2 = _m2;
        s = str;
        n = s.size();
        pw1[0] = pw2[0] = 1;
        h1[0] = h2[0] = dif(s[0]);
        for (int i = 1; i < n; i++)
        {
            h1[i] = (1ll * h1[i - 1] * p1 + dif(s[i])) % m1;
            h2[i] = (1ll * h2[i - 1] * p2 + dif(s[i])) % m2;
            pw1[i] = (1ll * pw1[i - 1] * p1) % m1;
            pw2[i] = (1ll * pw2[i - 1] * p2) % m2;
        }
        h3[n - 1] = h4[n - 1] = dif(s[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            h3[i] = (1ll * h3[i + 1] * p1 + dif(s[i])) % m1;
            h4[i] = (1ll * h4[i + 1] * p2 + dif(s[i])) % m2;
        }
    }
    int dif(char x)
    {
        return x - 'a' + 1;
    }
    pair<int, int> pre_sub(int l, int r)
    {
        int t1 = h1[r], t2 = h2[r];
        if (l)
        {
            t1 = (t1 - (1ll * h1[l - 1] * pw1[r - l + 1]) % m1 + m1) % m1;
            t2 = (t2 - (1ll * h2[l - 1] * pw2[r - l + 1]) % m2 + m2) % m2;
        }
        return {t1, t2};
    }
    pair<int, int> suf_sub(int l, int r)
    {
        int t1 = h3[l], t2 = h4[l];
        if (r + 1 < n)
        {
            t1 = (t1 - (1ll * h3[r + 1] * pw1[r - l + 1]) % m1 + m1) % m1;
            t2 = (t2 - (1ll * h4[r + 1] * pw2[r - l + 1]) % m2 + m2) % m2;
        }
        return {t1, t2};
    }
    bool pal(int l, int r)
    {
        return pre_sub(l, r) == suf_sub(l, r);
    }
} h;


int gt(int x)
{
    int l = 0, r = min(n - x - 1, x), mid, ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (h.pal(x - mid, x + mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans * 2 + 1;
}
int gt2(int x)
{
    int l = 0, r = min(n - x - 2, x), mid, ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (h.pal(x - mid, x + 1 + mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans * 2 + 2;
}
void solve()
{
    cin >> s;
    n = s.size();
    h.init(s, 47, 51, 1e9 + 9, 1e9 + 7);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, gt(i));
    }
    for (int i = 0; i + 1 < n; i++)
    {
        if (s[i] == s[i + 1])
            ans = max(ans, gt2(i));
    }
    cout << ans << endl;
}
int32_t main()
{
    readFromFile();
    SD;
    int t = 1;
    //    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}