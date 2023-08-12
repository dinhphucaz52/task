#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define elif else if
#define int long long
#define ii pair<int, int>
#define bit(i, j) ((i>>j)&1)
#define sz(a) (int)(a.size())
#define left_node id<<1,l,mid
#define right_node id<<1|1,mid+1,r

const int MAXN = 1e5 + 16;
const int MAXM = 1e3 + 16;
const int BASE = 311;
const int MOD = 1e9 + 7;
const int INF = 1e18;

struct my_data
{
    int cnt, val;
    my_data() : cnt(0), val(0){}
    my_data(int cnt, int val) : cnt(cnt), val(val){}
};


void solve()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    vector<my_data> dp(n + 1);
    dp[1] = my_data(1, a[1]);

    for (int i = 2; i <= n; i++)
    {
        dp[i] = my_data(0, pre[i]);
        for (int j = 0; j < i; j++)
        {
            int val = pre[i] - pre[j];
            if (val >= dp[j].val)
                dp[i] = my_data(dp[j].cnt + 1, val);                
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}