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

void fillVec(vector<vector<long long>> &vec, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> vec[i][j];
}
int N = 2 * 1e5 + 10;
long long p = 37, mod = 1e9 + 123;
vector<long long> power(N);

map<long long, long long> hashrows(vector<vector<long long>> &vec, int n, int m)
{
    map<long long, long long> mp;
    for (int i = 0; i < n; i++)
    {
        int hash = 0;
        for (int j = 0; j < m; j++)
            hash += (vec[i][j] * power[vec[i][j]]) % mod;

        for (int j = 0; j < m; j++)
            mp[vec[i][j]] = hash;
    }
    return mp;
}

map<long long, long long> hashcolumn(vector<vector<long long>> &vec, int n, int m)
{
    map<long long, long long> mp;
    for (int i = 0; i < m; i++)
    {
        long long hash = 0;
        for (int j = 0; j < n; j++)
            hash += (vec[j][i] * power[vec[j][i]]) % mod;

        for (int j = 0; j < n; j++)
        {
            // cout << vec[j][i] << " ";
            mp[vec[j][i]] = hash;
        }
    }

    return mp;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> vec(n, vector<long long>(m)), vecFinal(n, vector<long long>(m));
    fillVec(vec, n, m);
    fillVec(vecFinal, n, m);

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << vec[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    map<long long, long long> mprows = hashrows(vec, n, m);
    map<long long, long long> mpcolumns = hashcolumn(vec, n, m);

    map<long long, long long> mprowsfinal = hashrows(vecFinal, n, m);
    map<long long, long long> mpcolumnsfinal = hashcolumn(vecFinal, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mprows[vec[i][j]] != mprowsfinal[vec[i][j]])
            {
                cout << "No\n";
                return;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mpcolumns[vec[j][i]] != mpcolumnsfinal[vec[j][i]])
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

int main()
{
    readFromFile();

    power[0] = 1;
    for (int i = 1; i < N; i++)
        power[i] = (power[i - 1] * p) % mod;

    // FastIO
    int t;
    cin >> t;
    while (t--)
        solve();
}