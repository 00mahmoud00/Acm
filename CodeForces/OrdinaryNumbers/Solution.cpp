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

void solve(vector<long long> &numbers)
{
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] >= n)
        {
            cout << i + 1 - (n != numbers[i]) << endl;
            return;
        }
    }
}

int main()
{
    readFromFile();
    vector<long long> numbers;
    for (long long i = 1; i <= 9; i++)
    {
        long long x = i;
        numbers.push_back(x);
        for (long long j = 0; j < 9; j++)
        {
            x *= 10;
            x += i;
            // cout << x << endl;
            numbers.push_back(x);
        }
    }
    sort(numbers.begin(), numbers.end());
    // FastIO
    int t;
    cin >> t;
    while (t--)
        solve(numbers);
}