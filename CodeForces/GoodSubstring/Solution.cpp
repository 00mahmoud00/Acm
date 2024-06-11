#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
typedef long long ll;
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    // freopen(output.c_str(), "w", stdout);
#endif
}
const int Mod = 1e9 + 321;
const int Mod2 = 1e9 + 123;

const int p = 37;
const int p2 = 31;

int bad = 0, cnt = 0;
string s, binary;
set<pair<int, int>> ms;
vector<ll> frqcumsum, prefixHashed, prefixHashed2, ppow, ppow2;

void get_unique_substrings(string &s)
{
    int n = s.size();

    prefixHashed2.resize(n + 1);
    prefixHashed.resize(n + 1);
    ppow2.resize(n + 1);
    ppow.resize(n + 1);

    ppow[0] = ppow2[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ppow[i] = (ppow[i - 1] * p) % Mod;
        ppow2[i] = (ppow2[i - 1] * p2) % Mod2;
    }

    for (int i = 0; i < n; i++)
    {
        prefixHashed[i] = ((i == 0 ? 0 : prefixHashed[i - 1]) + (s[i] - 'a' + 1) * ppow[i]) % Mod;
        prefixHashed2[i] = ((i == 0 ? 0 : prefixHashed2[i - 1]) + (s[i] - 'a' + 1) * ppow2[i]) % Mod2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int curhash = (prefixHashed[j] - (i == 0 ? 0 : prefixHashed[i - 1]) + Mod) % Mod;
            curhash = (ppow[n - j - 1] * curhash) % Mod;

            int curhash2 = (prefixHashed2[j] - (i == 0 ? 0 : prefixHashed2[i - 1]) + Mod2) % Mod2;
            curhash2 = (ppow2[n - j - 1] * curhash2) % Mod2;

            pair<int, int> pr = make_pair(curhash, curhash2);
            int badcount = (frqcumsum[j] - (i == 0 ? 0 : frqcumsum[i - 1]));

            if (badcount > bad)
                break;
            ms.insert(pr);
        }
    }
}
void solve()
{
    cin >> s >> binary >> bad;

    int ssize = s.size();
    frqcumsum.resize(ssize);

    for (int i = 0; i < ssize; i++)
        frqcumsum[i] = ((binary[s[i] - 'a'] - '0') == 0) + (i == 0 ? 0 : frqcumsum[i - 1]);

    get_unique_substrings(s);
    cout << ms.size();
}

int main()
{
    // FastIO
    readFromFile();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //  int t;
    //  cin >> t;
    //  while (t--)
    solve();
}