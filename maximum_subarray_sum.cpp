// https://www.hackerrank.com/challenges/maximum-subarray-sum/problem
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 1e5 + 6;

set<int> s;
int n, m, x, mod[MAXN];

void solve()
{
    int res = -INF;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        mod[i] = (mod[i-1] + x) % m;
        res = max({res, mod[i]});
        set<int>::iterator it = s.upper_bound(mod[i]);
        if (it != s.end())
            res = max(res, m + mod[i] - *it);
        s.insert(mod[i]);
    }
    s.clear();
    cout << res << endl;
}

signed main()
{   
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int test; cin >> test;
    while (test--)
        solve();
    return 0;
}