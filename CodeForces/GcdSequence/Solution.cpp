#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    // freopen(output.c_str(), "w", stdout);
#endif
}

pair<bool, int> good(vector<int> &v)
{
    int idx = -1, gcd = -1;
    for (int i = 0; i < int(v.size()) - 1; i++)
    {
        int curgcd = __gcd(v[i], v[i + 1]);
        if (curgcd < gcd)
            return make_pair(false, i);
        gcd = curgcd;
    }
    return make_pair(true, -1);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    pair<bool, int> p = good(vec);

    if (p.first)
    {
        cout << "Yes\n";
        return;
    }

    vector<int> vec1 = vec, vec2 = vec, vec3 = vec;

    if (p.second > 0)
        vec1.erase(vec1.begin() + p.second - 1);

    vec2.erase(vec2.begin() + p.second);

    if (p.second + 1 < n)
        vec3.erase(vec3.begin() + p.second + 1);

    cout << ((good(vec1).first || good(vec2).first || good(vec3).first) ? "Yes" : "No") << endl;
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