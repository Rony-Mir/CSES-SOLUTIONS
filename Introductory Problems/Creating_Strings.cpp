
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

string s, r = "";
set<string> bucket;
vector<int> ID(10);

void pmt()
{
    if (sz(r) == sz(s))
    {
        bucket.insert(r);
        return;
    }

    rep(ii, 0, sz(s), 1)
    {
        if (ID[ii])
            continue;

        ID[ii] = 1;
        r += s[ii];

        pmt();

        ID[ii] = 0;
        r.pop_back();
    }
}

void sol(int tc)
{
    cin >> s;
    sort(all(s));
    pmt();
    cout << sz(bucket) << "\n";
    for (string s : bucket)
        cout << s << "\n";
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
