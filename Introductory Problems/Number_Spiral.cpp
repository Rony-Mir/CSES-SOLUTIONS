
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define files                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ll long long

#define rep(ii, beg, till, inc) for (int ii = beg; ii < till; ii += inc)
#define repr(ii, beg, till, inc) for (int ii = beg - 1; ii >= till; ii -= inc)

const ll MOD = 1e9 + 7;
const int MXN = 2e5 + 5;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void sol(int tc)
{
    ll x, y;
    cin >> x >> y;
    ll res = 0;
    if (x >= y)
    {
        if (x % 2)
        {
            res = (x - 1) * (x - 1);
            res += y;
        }
        else
        {
            res = x * x;
            res -= y - 1;
        }
    }
    else
    {
        if (y % 2 == 0)
        {
            res = (y - 1) * (y - 1);
            res += x;
        }
        else
        {
            res = y * y;
            res -= x - 1;
        }
    }
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int ii = 1; ii <= T; ++ii)
        sol(ii);
}
