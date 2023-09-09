
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

int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};

int ans = 0;
vector<vector<int>> grid(8, vector<int>(8));

void gen(int id)
{
    if (id == 8)
    {
        ++ans;
        return;
    }

    rep(jj, 0, 8, 1) if (!grid[id][jj])
    {
        vector<vector<int>> save(8, vector<int>(8));
        save = grid;
        grid[id][jj] = 1;
        rep(kk, 0, 8, 1)
        {
            int x = id + dx[kk];
            int y = jj + dy[kk];

            while (x >= 0 && x < 8 && y >= 0 && y < 8)
            {
                grid[x][y] = 1;
                x += dx[kk];
                y += dy[kk];
            }
        }
        gen(id + 1);
        grid = save;
    }
}

void sol(int tc)
{
    rep(ii, 0, 8, 1)
    {
        string s;
        cin >> s;
        rep(jj, 0, 8, 1) grid[ii][jj] = s[jj] == '*';
    }
    gen(0);
    cout << ans << "\n";
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
