#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
void readFromFile ( string input = "input.txt" )
{
    #ifndef ONLINE_JUDGE
    freopen ( input.c_str(), "r", stdin );
    #endif
}

void solve()
{
    for ( int i = 0; i < 100; i++ )
    {
        cout << i << endl;
    }
}

int main()
{
    // readFromFile();
    FastIO
    int t = 1;
    cin >> t;

    while ( t-- )
    { solve(); }
}
