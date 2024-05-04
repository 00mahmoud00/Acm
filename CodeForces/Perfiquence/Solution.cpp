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


void solve()
{
}

int main()
{
    // ReadWriteIO();
    // FastIO();
    int t;
    cin >> t;
    while(t--)
        solve();
}