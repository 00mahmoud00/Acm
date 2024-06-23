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
    vector<ll> suf1, suf2, suf3;
    vector<ll> power1, power2, power3;

    void init(string &s)
    {
        n = s.size();
        str = s;

        pre1.resize(n);
        pre2.resize(n);
        pre3.resize(n);

        suf1.resize(n);
        suf2.resize(n);
        suf3.resize(n);

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

        suf1[n - 1] = suf2[n - 1] = suf3[n - 1] = getNumber(s[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            int number = getNumber(s[i]);
            suf1[i] = (1ll * suf1[i + 1] * p1 + number) % Mod1;
            suf2[i] = (1ll * suf2[i + 1] * p2 + number) % Mod2;
            suf3[i] = (1ll * suf3[i + 1] * p3 + number) % Mod3;
        }
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

    pair<int, pair<int, int>> get_suffix(int l, int r)
    {
        int sf1 = suf1[l], sf2 = suf2[l], sf3 = suf3[l];
        if (r + 1 < n)
        {
            sf1 = (sf1 - (1ll * suf1[r + 1] * power1[r - l + 1]) % Mod1 + Mod1) % Mod1;
            sf2 = (sf2 - (1ll * suf2[r + 1] * power2[r - l + 1]) % Mod2 + Mod2) % Mod2;
            sf3 = (sf3 - (1ll * suf3[r + 1] * power3[r - l + 1]) % Mod3 + Mod3) % Mod3;
        }
        return make_pair(sf1, make_pair(sf2, sf3));
    }

    bool isPalindrome(int l, int r)
    {
        pair<int, pair<int, int>> prefix = get_prefix(l, r);
        pair<int, pair<int, int>> suffix = get_suffix(l, r);
        return prefix.first == suffix.first &&
               prefix.second.first == suffix.second.first &&
               prefix.second.second == suffix.second.second;
    }

    int longestPalindrome()
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, palindromeOdd(i));

        for (int i = 0; i + 1 < n; i++)
        {
            if (str[i] == str[i + 1])
                ans = max(ans, palindromeEven(i));
        }

        return ans;
    }
    int palindromeOdd(int x)
    {
        int l = 0, r = min(n - x - 1, x), mid, ans = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (isPalindrome(x - mid, x + mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans * 2 + 1;
    }

    int palindromeEven(int x)
    {
        int l = 0, r = min(n - x - 2, x), mid, ans = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (isPalindrome(x - mid, x + 1 + mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans * 2 + 2;
    }

    int getNumber(char x)
    {
        return x - 'a' + 1;
    }
} hashing;
void solve()
{
    // = "abcdfdcecba"
    string s;
    cin >> s;
    int start = 0, n = s.size();
    while (s[start] == s[n - 1 - start])
        start++;

    if (start >= n)
    {
        cout << s << endl;
        return;
    }

    string s2 = s.substr(start, n - 2 * start);
    hashing.init(s2);

    int leftans = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        if (hashing.isPalindrome(0, i))
            leftans = i;
    }

    int rightans = s2.size() - 1;
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        if (hashing.isPalindrome(i, s2.size() - 1))
            rightans = i;
    }

    for (int i = 0; i < start; i++)
        cout << s[i];

    if ((leftans + 1) < (s2.size() - rightans + 1))
    {
        for (int i = rightans; i < s2.size(); i++)
            cout << s2[i];
    }
    else
    {
        for (int i = 0; i <= leftans; i++)
            cout << s2[i];
    }

    for (int i = n - start; i < n; i++)
        cout << s[i];
    cout << endl;
}

int main()
{
    // readFromFile();
    FastIO;
    int t;
    cin >> t;
    while (t--)
        solve();
}