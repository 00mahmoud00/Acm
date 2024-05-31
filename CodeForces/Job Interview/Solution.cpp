#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
using namespace std;

void ReadWriteIO()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}

void PrinVec(vector<long long> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}
int n, m;
vector<int> a, b, ans;
void solve()
{
    cin >> n >> m;
    a.resize(n + m + 1);
    b.resize(n + m + 1);
    ans.resize(n + m + 1);

    for (int i = 0; i < n + m + 1; i++)
        cin >> a[i];

    for (int i = 0; i < n + m + 1; i++)
        cin >> b[i];

    for (int i = 0; i < n + m + 1; i++)
    {
        int pro = n, tester = m, anss = 0;
        for (int j = 0; j < n + m + 1; j++)
        {
            if (i == j)
                continue;
            if (tester == 0 && pro != 0)
            {
                pro--;
                anss += a[j];
            }
            else if (pro == 0 && tester != 0)
            {
                tester--;
                anss += b[j];
            }
            else
            {
                if (a[j] > b[j])
                {
                    pro--;
                    anss += a[j];
                }
                else
                {
                    tester--;
                    anss += b[j];
                }
            }
        }
        ans[i] = anss;
    }
    for (auto anss : ans)
        cout << anss << " ";
    cout << endl;
    a.clear();
    b.clear();
    ans.clear();
}

int main()
{
    // ReadWriteIO();
    // FastIO
    int t;
    cin >> t;
    while (t--)
        solve();
}