
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
char dz[] = {'U', 'D', 'L', 'R'};

int n, m;
string res = "";
vector<string> graph;
vector<vector<char>> vis;
vector<vector<pair<int, int>>> par;

bool path(int ii, int jj)
{
    queue<pair<int, int>> waiting;
    waiting.push({ii, jj});
    vis[ii][jj] = true;
    pair<int, int> tar = {-1, -1};

    while (!waiting.empty())
    {
        int x = waiting.front().first;
        int y = waiting.front().second;
        waiting.pop();
        if (graph[x][y] == 'B')
        {
            tar = {x, y};
            break;
        }
        rep(id, 0, 4, 1)
        {
            int nxtx = x + dx[id];
            int nxty = y + dy[id];
            if (nxtx < 0 || nxty < 0 || nxtx >= n || nxty >= m || vis[nxtx][nxty] || graph[nxtx][nxty] == '#')
                continue;

            vis[nxtx][nxty] = true;
            par[nxtx][nxty] = {x, y};
            waiting.push({nxtx, nxty});
        }
    }
    if (tar.first == -1)
        return false;

    while (graph[tar.first][tar.second] != 'A')
    {
        rep(id, 0, 4, 1)
        {
            int nxtx = tar.first + dx[id];
            int nxty = tar.second + dy[id];
            if (par[tar.first][tar.second] == make_pair(nxtx, nxty))
            {
                res += dz[id];
                break;
            }
        }
        tar = par[tar.first][tar.second];
    }
    return true;
}
void sol(int tc)
{
    cin >> n >> m;
    graph.resize(n);
    vis.resize(n, vector<char>(m));
    par.resize(n, vector<pair<int, int>>(m));

    rep(ii, 0, n, 1) cin >> graph[ii];
    rep(ii, 0, n, 1) rep(jj, 0, m, 1) if (graph[ii][jj] == 'A')
    {
        bool pas = path(ii, jj);
        if (pas)
        {
            cout << "YES\n";
            cout << sz(res) << "\n";
            reverse(all(res));
            cout << res << "\n";
        }
        else
            cout << "NO\n";
        return;
    }
    cout << "NO\n";
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
