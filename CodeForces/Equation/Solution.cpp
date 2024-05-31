#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
// #define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
void FastIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void ReadWriteIO()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}
int inputMultiple()
{
    int t;
    cin >> t;
    return t;
}

// START CODING
double c;

float squareRoot(ll number, int precision)
{
    ll start = 0, end = number;
    ll mid;

    float ans;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (mid * mid == number)
        {
            ans = mid;
            break;
        }

        if (mid * mid < number)
        {
            start = mid + 1;
            ans = mid;
        }

        else
        {
            end = mid - 1;
        }
    }

    float increment = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while (ans * ans <= number)
        {
            ans += increment;
        }

        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}

bool isValid(double number)
{
    double ans = number * number + sqrt(number);
    return ans >= c;
}

void solve()
{
    cin >> c;

    double l = 0, r = 1e5;
    cout << setprecision(20);
    for (int i = 0; i < 100; i++)
    {
        double m = (l + r) / 2;
        if (isValid(m))
            r = m;
        else
            l = m;
        // cout << i << " " << l << " " << r << endl;
    }
    cout << l << endl;
}

int main()
{
    // ReadWriteIO();
    //  FastIO();
    //  int t;
    //  cin >> t;
    //  while (t--)
    solve();
}