#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;
using namespace std;
void readFromFile(string input = "input.txt", string output = "output.txt")
{
#ifndef ONLINE_JUDGE
    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif
}

struct Hashing
{
    int n;
    string str;
    const int p1 = 37, p2 = 47, p3 = 23;
    const int Mod1 = 1e9 + 9, Mod2 = 1e9 + 7, Mod3 = 1e9 + 123;
    vector<ll> pre1, pre2, pre3;
    vector<ll> power1, power2, power3;
    vector<int> idxs;

    void init(string &s)
    {
        n = s.size();
        str = s;

        pre1.resize(n);
        pre2.resize(n);
        pre3.resize(n);

        power1.resize(n);
        power2.resize(n);
        power3.resize(n);

        power1[0] = power2[0] = power3[0] = 1;
        pre1[0] = pre2[0] = pre3[0] = getNumber(s[0]);
        for (int i = 1; i < n; i++)
        {
            power1[i] = (1ll * power1[i - 1] * p1) % Mod1;
            power2[i] = (1ll * power2[i - 1] * p2) % Mod2;
            power3[i] = (1ll * power3[i - 1] * p3) % Mod3;

            pre1[i] = ((1ll * pre1[i - 1] * p1) % Mod1 + getNumber(s[i])) % Mod1;
            pre2[i] = ((1ll * pre2[i - 1] * p2) % Mod2 + getNumber(s[i])) % Mod2;
            pre3[i] = ((1ll * pre3[i - 1] * p3) % Mod3 + getNumber(s[i])) % Mod3;
        }
    }

    int GetMatcingString()
    {
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            // cout << "i = " << i << endl;
            // cout << str.substr(0, i + 1) << endl;
            // cout << str.substr(n - 1 - i, i + 1) << endl;
            int suffixIdx = n - 2 - i;

            // pr1 = (pr1 - (1ll * pre1[l - 1] * power1[r - l + 1]) % Mod1 + Mod1) % Mod1;
            // pr2 = (pr2 - (1ll * pre2[l - 1] * power2[r - l + 1]) % Mod2 + Mod2) % Mod2;
            // pr3 = (pr3 - (1ll * pre3[l - 1] * power3[r - l + 1]) % Mod3 + Mod3) % Mod3;

            int pr1 = pre1[i];
            int pr11 = ((pre1[n - 1] - (1ll * pre1[suffixIdx] * power1[i + 1])) % Mod1 + Mod1) % Mod1;

            int pr2 = pre2[i];
            int pr22 = (pre2[n - 1] - (1ll * pre2[suffixIdx] * power2[i + 1]) % Mod2 + Mod2) % Mod2;

            int pr3 = pre3[i];
            int pr33 = (pre3[n - 1] - (1ll * pre3[suffixIdx] * power3[i + 1]) % Mod3 + Mod3) % Mod3;

            // cout << "pre1: " << pr1 << "  " << pr11 << endl;
            // cout << "pre2: " << pr2 << "  " << pr22 << endl;
            // cout << "pre3: " << pr3 << "  " << pr33 << endl;
            // cout << "------------\n";
            if (pr1 == pr11 && pr2 == pr22 && pr3 == pr33)
            {
                idxs.push_back(i);
                ans = i;
                // break;
            }
        }
        return ans;
    }

    bool isMatcing(int l, int r, int idx)
    {
        int suffixIdx = r - l + 1;

        // cout << "l = " << l << ", r = " << r << endl;
        int pr1 = pre1[idx];
        int pr11 = ((pre1[r] - (1ll * pre1[l - 1] * power1[r - l + 1])) % Mod1 + Mod1) % Mod1;

        int pr2 = pre2[idx];
        int pr22 = (pre2[r] - (1ll * pre2[l - 1] * power2[r - l + 1]) % Mod2 + Mod2) % Mod2;

        int pr3 = pre3[idx];
        int pr33 = (pre3[r] - (1ll * pre3[l - 1] * power3[r - l + 1]) % Mod3 + Mod3) % Mod3;

        return pr1 == pr11 && pr2 == pr22 && pr3 == pr33;
    }

    pair<int, pair<int, int>> get_prefix(int l, int r)
    {
        int pr1 = pre1[r], pr2 = pre2[r], pr3 = pre3[r];
        if (l > 0)
        {
            pr1 = (pr1 - (1ll * pre1[l - 1] * power1[r - l + 1]) % Mod1 + Mod1) % Mod1;
            pr2 = (pr2 - (1ll * pre2[l - 1] * power2[r - l + 1]) % Mod2 + Mod2) % Mod2;
            pr3 = (pr3 - (1ll * pre3[l - 1] * power3[r - l + 1]) % Mod3 + Mod3) % Mod3;
        }

        return make_pair(pr1, make_pair(pr2, pr3));
    }

    // void PrintHashes()
    // {
    //     for (auto x : pre1)
    //         cout << x << " ";
    //     cout << endl;

    //     for (auto x : pre2)
    //         cout << x << " ";
    //     cout << endl;

    //     for (auto x : pre3)
    //         cout << x << " ";
    //     cout << endl;
    // }
    int getNumber(char x)
    {
        return x - 'a' + 1;
    }
} hashing;

void solve()
{
    // string s = "fixprefixsuffix";
    string s;
    cin >> s;
    hashing.init(s);
    // hashing.PrintHashes();
    int idx = hashing.GetMatcingString();
    // cout << idx << endl;
    // cout << hashing.idxs.size() << endl;
    for (int j = hashing.idxs.size() - 1; j >= 0; j--)
    {
        bool ans = false;
        int idx = hashing.idxs[j];
        // cout << "idx = " << idx << endl;
        for (int i = 1; (i + idx) < s.size() - 1; i++)
        {
            // cout << "i = " << i << endl;
            if (hashing.isMatcing(i, i + idx, idx))
            {
                cout << s.substr(0, idx + 1) << endl;
                return;
            }
            // ans = true;
        }
    }
    cout << "Just a legend";
}

int main()
{
    // readFromFile();
    FastIO;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}