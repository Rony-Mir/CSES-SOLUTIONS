
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
    ll cur = n * (n + 1) / 2;

    if (cur % 2)
    {
        cout << "NO\n";
        return;
    }

    cur /= 2;
    set<ll> s;
    vector<ll> bucket;
    rep(ii, 1, n + 1, 1) s.insert(ii);

    int cnt = 0;
    while (cur > 0)
    {
        auto ptr = s.lower_bound(cur);
        if (ptr == s.end())
        {
            cur -= *s.rbegin();
            bucket.push_back(*s.rbegin());
            s.erase(*s.rbegin());
            continue;
        }
        cur -= *ptr;
        bucket.push_back(*ptr);
        s.erase(ptr);
    }

    cout << "YES\n";
    cout << sz(bucket) << "\n";
    rep(ii, 0, sz(bucket), 1) cout << bucket[ii] << " \n"[ii + 1 == sz(bucket)];
    cout << sz(s) << "\n";
    for (int u : s)
        cout << u << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int ii = 1; ii <= T; ++ii)
        sol(ii);
}
