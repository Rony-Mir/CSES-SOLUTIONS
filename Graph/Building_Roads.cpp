
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

int node, edge;
vector<int> par, level;
vector<vector<int>> graph;

int f(int x)
{
    return par[x] = x == par[x] ? x : f(par[x]);
}
void unite(int x, int y)
{
    x = f(x);
    y = f(y);
    if (x != y)
    {
        if (level[x] < level[y])
            swap(x, y);
        par[y] = x;
        if (level[x] == level[y])
            ++level[x];
    }
}
void sol(int tc)
{
    cin >> node >> edge;
    par.resize(node + 5);
    level.resize(node + 5);
    graph.resize(node + 5);
    rep(ii, 1, node + 1, 1)
    {
        level[ii] = 0;
        par[ii] = ii;
    }
    rep(ii, 1, edge + 1, 1)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        unite(u, v);
    }
    vector<int> comp;
    rep(ii, 1, node + 1, 1) if (par[ii] == ii) comp.push_back(ii);
    cout << sz(comp) - 1 << "\n";
    rep(ii, 1, sz(comp), 1) cout << comp[ii] << " " << comp[ii - 1] << "\n";
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
