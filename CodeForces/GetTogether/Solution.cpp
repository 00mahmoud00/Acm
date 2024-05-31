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
struct people
{
    double x, v;
    people(){};
};

ll n;
vector<people> peoples;

bool isValid(double time)
{
    double leftmost = -1e10;
    double rightmost = 1e10;

    for (int i = 0; i < n; i++)
    {
        double xl = peoples[i].x - time * peoples[i].v;
        double xr = peoples[i].x + time * peoples[i].v;

        leftmost = max(leftmost, xl);
        rightmost = min(rightmost, xr);
    }

    return leftmost < rightmost;
}
void solve()
{
    cin >> n;
    peoples.resize(n);
    for (int i = 0; i < n; i++)
        cin >> peoples[i].x >> peoples[i].v;

    double l = 0, r = 1e18;
    for (int i = 0; i < 80; i++)
    {
        double m = (l + r) / 2;
        if (isValid(m))
            r = m;
        else
            l = m;
    }

    cout << setprecision(30) << l << endl;
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