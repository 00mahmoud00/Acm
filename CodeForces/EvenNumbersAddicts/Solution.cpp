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
    int n;
    cin >> n;
    vector<long long> vec(n);
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (vec[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    if (odd % 4 == 2)
        cout << "Bob" << endl;
    else if (odd % 4 == 3)
        cout << "Alice" << endl;
    else if (odd % 4 == 0)
        cout << "Alice" << endl;
    else if (even % 2 == 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}

int main()
{
    readFromFile();
    // FastIO
    int t;
    cin >> t;
    while (t--)
        solve();
}