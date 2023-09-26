
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

int n, m;
vector<string> graph;
vector<vector<char>> vis;

void dfs(int ii, int jj)
{
    vis[ii][jj] = true;
    rep(step, 0, 4, 1)
    {
        int nxtx = ii + dx[step];
        int nxty = jj + dy[step];
        if (nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m || graph[nxtx][nxty] == '#' || vis[nxtx][nxty])
            continue;
        dfs(nxtx, nxty);
    }
}
void sol(int tc)
{
    cin >> n >> m;
    graph.resize(n);
    vis.resize(n, vector<char>(m));
    rep(ii, 0, n, 1) cin >> graph[ii];

    int comp = 0;
    rep(ii, 0, n, 1) rep(jj, 0, m, 1) if (!vis[ii][jj] && graph[ii][jj] != '#')
    {
        comp++;
        dfs(ii, jj);
    }
    cout << comp << "\n";
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
