#include <bits/stdc++.h>
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
#define ReadIO freopen("input.txt", "r", stdin);
#define WriteIO freopen("output.txt", "w", stdout);
using namespace std;

int n, m, procount = 0, testcount = 0;
vector<pair<pair<long long, long long>, bool>> input, programmers, testers;
void solve()
{
    cin >> n >> m;
    int sizee = n + m + 1;
    input.resize(sizee);

    int arr[sizee], b[sizee];
    for (int i = 0; i < input.size(); i++)
        cin >> arr[i];

    for (int i = 0; i < sizee; i++)
    {
        int x;
        cin >> x;
        // cin >> b[i];
        input[i] = make_pair(make_pair(arr[i], x), arr[i] > x);
    }

    long long baseans = 0, i = 0;
    for (auto &p : input)
    {
        if (programmers.size() >= n + 1 || (p.first.second > p.first.first && testers.size() < m + 1))
        {
            // p = make_pair(make_pair(arr[i], b[i]), 0);
            p.second = 0;
            testers.push_back(p);
            baseans += p.first.second;
            testcount++;
        }

        else if (testers.size() >= m + 1 || (p.first.first > p.first.second && programmers.size() < n + 1))
        {
            p.second = 1;
            programmers.push_back(p);
            baseans += p.first.first;
            procount++;
        }
    }

    for (int i = 0; i < n + m + 1; i++)
    {
        long long anss = baseans;
        if (input[i].second == 0)
            anss -= input[i].first.second;
        else
            anss -= input[i].first.first;

        if (input[i].second == 0 && testcount - 1 < m)
        {
            auto pp = programmers[programmers.size() - 1];
            // cout << "i = " << i << "  " << pp.first.first << ' ' << pp.first.second << endl;
            anss += pp.first.second;
            anss -= pp.first.first;
        }
        else if (input[i].second == 1 && procount - 1 < n)
        {
            auto pp = testers[testers.size() - 1];
            // cout << "i = " << i << "  " << pp.first.first << ' ' << pp.first.second << endl;
            anss += pp.first.first;
            anss -= pp.first.second;
        }

        // cout << "ans: " << anss << "\n";
        cout << anss << " ";
    }
    cout << endl;

    testers.clear();
    input.clear();
    programmers.clear();
    testcount = 0;
    procount = 0;
    baseans = 0;
}

int main()
{
    // ReadIO
    int t;
    cin >> t;
    while (t--)
        solve();
}