
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
    ll n;
    cin >> n;

    if (n < 10)
    {
        cout << n << "\n";
        return;
    }

    ll sum = 9;
    ll cur = 10;
    ll mx = 2, dig = 2;
    for (ll ii = 2; sum < n; ++ii)
    {
        ll nxt = cur * 10;
        ll block = nxt - cur;
        block *= ii;
        sum += block;
        mx = cur;
        dig = ii;
        cur *= 10;
    }

    sum -= (mx * 10 - mx) * dig;
    n -= sum;
    ll low = mx - 1, high = mx * 10;
    while (high - low > 1)
    {
        ll mid = (low + high) / 2;
        ll dif = (mid - mx + 1) * dig;
        if (dif >= n)
            high = mid;
        else
            low = mid;
    }

    n -= max(0LL, (high - mx) * dig);
    vector<ll> num;
    while (high)
    {
        num.push_back(high % 10);
        high /= 10;
    }
    reverse(all(num));
    cout << num[n - 1] << "\n";
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
