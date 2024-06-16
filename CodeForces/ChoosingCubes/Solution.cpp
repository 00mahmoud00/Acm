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
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    int fav = vec[f - 1];

    sort(vec.rbegin(), vec.rend());
    bool prefix = false, sufix = false;

    for (int i = 0; i < k; i++)
        prefix |= (vec[i] == fav);

    for (int i = k; i < n; i++)
        sufix |= (vec[i] == fav);
    // cout << "Pre: ";
    // for (int i = 0; i < k; i++)
        // cout << vec[i] << " ";
    // cout << endl;

    // cout << "Suf: ";
    // for (int i = k; i < n; i++)
        // cout << vec[i] << " ";
    // cout << endl;

    // cout << fav << endl;
    if (prefix && sufix)
        cout << "Maybe";
    else if (prefix && !sufix)
        cout << "Yes";
    else if (!prefix && sufix)
        cout << "No";
    cout << endl;
}

int main()
{
    readFromFile();
    FastIO;
    int t;
    cin >> t;
    while (t--)
        solve();
}