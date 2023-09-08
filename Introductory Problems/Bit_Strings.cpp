
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

/*
 *   1. if M is a prime : binPow(base , pow) == binPow(base, pow % (M - 1)), base ^ pow = base ^ (pow % (M - 1)) (%M)
 *   2. if M is a prime : binPow(base, M - 2) == a ^ -1 (modular multiplicative inverse of base)
 *   3. To calculate a * b % M with overflow issues : just do ans = 0 and ans = (ans + base) % M and
 *      base = (2 * base) % M and explaination to that method :
 *      we can do a * b = a + a + ... b times or just 8a = 2 * 4a = 4 * 2a.
 */
long long bin(long long base, long long pow, long long m)
{
    if (base >= m)
        base %= m;
    long long res = 1;
    while (pow)
    {
        if (pow & 1)
        {
            res = res * base;
            if (res >= m)
                res %= m;
        }
        base = base * base;
        if (base >= m)
            base %= m;
        pow >>= 1;
    }
    return res;
}

void sol(int tc)
{
    int n;
    cin >> n;
    cout << bin(2, n, MOD) << "\n";
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
