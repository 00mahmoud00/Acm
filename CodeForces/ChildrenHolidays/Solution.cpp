#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
// #define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
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

struct assistants
{
    ll t, z, y, ballonCount = 0, temp = 0;

    void setballonCount(int count)
    {
        ballonCount = count;
    }

    ll totalTime()
    {
        return t * z + y;
    }

    ll countBallons(ll seconds)
    {
        ll ans = seconds / (z * t + y);
        ll temp = seconds - ans;
        if (temp - z * t >= 0)
            ans++;
        return ans;

        // while (seconds - z * t >= 0)
        // {
        //     seconds -= z * t;
        //     ans++;
        //     if (seconds >= 0)
        //         seconds -= y;
        // }
        // return ans;
    }
};
ll n, m;
vector<assistants> vec;
bool isValid(ll seconds)
{
    ll ballon = 0;
    ll currenballoncount = 0;
    for (int i = 0; i < n; i++)
    {
        currenballoncount = 0;
        ll ss = vec[i].totalTime();
        ll timecycle = floor(seconds / vec[i].totalTime());
        ll remSeconds = seconds % vec[i].totalTime();
        ll currnetballoncount = vec[i].z * timecycle;
        if (remSeconds >= vec[i].t)
            currnetballoncount += ((remSeconds / vec[i].t) > vec[i].z ? vec[i].z : remSeconds / vec[i].t);
        vec[i].setballonCount(currnetballoncount);
        ballon += currnetballoncount;
    }

    return ballon >= (m);
}
void solve()
{
    cin >> m >> n;
    vec.resize(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i].t >> vec[i].z >> vec[i].y;

    ll l = 0, r = 1e9, ans = 0;

    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (isValid(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << endl;
    isValid(ans);
    ll remainBallons = m;
    for (int i = 0; i < n; i++)
    {
        cout << min(remainBallons, vec[i].ballonCount) << " ";
        remainBallons -= min(remainBallons, vec[i].ballonCount);
    }
}

int main()
{
    // ReadWriteIO();
    //  FastIO();
    //  int t;
    //  cin >> t;
    //  while (t--)
    solve();
}