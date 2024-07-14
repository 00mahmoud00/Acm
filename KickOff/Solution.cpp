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

void solve(int s)
{
    int n = s;
    int ans = 0;
    vector<int> vec(n + 1);
    for (int i = 1; i < n + 1; i++)
        vec[i] = i;

    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    do
    {
        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (vec[i] % vec[j] == 0)
                    ans++;
            }
        }
    } while (next_permutation(vec.begin() + 1, vec.end()));

    cout << s << "  " << ans << endl;
    cout << "============\n";
}

int main()
{
    // readFromFile();
    FastIO;
    int t = 0;
    // cin >> t;
    while (t++ < 20)
        solve(t);
}