
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

bool pas = false;
int n, m;
vector<int> vis;
vector<vector<int>> graph;

void dfs(int node, int col)
{
    vis[node] = col + 1;
    for (int child : graph[node])
    {
        if (!vis[child])
            dfs(child, col ^ 1);
        else if (col + 1 == vis[child])
            pas = true;
    }
}
void sol(int tc)
{
    cin >> n >> m;

    vis.resize(n + 5);
    graph.resize(n + 5);

    rep(ii, 0, m, 1)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    rep(ii, 1, n + 1, 1) if (!vis[ii])
        dfs(ii, 1);
    if (pas)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int ii = 1; ii <= n; ++ii)
        cout << vis[ii] << " \n"[ii == n];
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
