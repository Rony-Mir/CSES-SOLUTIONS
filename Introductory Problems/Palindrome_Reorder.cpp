
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
    string s;
    cin >> s;
    int ch[26] = {0};
    for (char cur : s)
        ch[cur - 'A']++;
    int cnt = 0;
    rep(ii, 0, 26, 1) cnt += ch[ii] % 2;
    if (cnt > 1)
    {
        cout << "NO SOLUTION\n";
        return;
    }
    string beg = "", mid = "";
    rep(ii, 0, 26, 1)
    {
        rep(jj, 0, ch[ii] / 2, 1) beg += char('A' + ii);

        if (ch[ii] % 2)
            mid += char('A' + ii);
    }
    cout << beg << mid;
    reverse(all(beg));
    cout << beg << "\n";
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
