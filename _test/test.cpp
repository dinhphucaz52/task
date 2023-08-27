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

const int MAXN = 1e6 + 16;
const int MAXM = 1e3 + 16;
const int BASE = 311;
const int MOD = 1e9 + 7;
const int INF = 1e18;

string s;
int pre[2][MAXN];

bool check(int l, int r)
{
    return (pre[0][r] - pre[0][l-1]) 
           ||  (pre[1][r] - pre[1][l-1]);
}

bool check(int length)
{
    for (int i = 0; i + length - 1 < sz(s); i++)
        if (!check(i + 1, i + length))
            return true;
    return false;
}

void solve()
{
    cin >> s;
    for (int i = 0; i < sz(s); i++)
    {
        pre[0][i+1] = pre[0][i] + (s[i] == s.front());
        pre[1][i+1] = pre[1][i] + (s[i] == s.back());
    }

    int res = -1, l = 1, r = sz(s);
    while (l <= r)
    {
        int length = (l + r) >> 1;
        if (check(length))
            res = max(res, length),
            l = ++length;
        else
            r = --length;
    }
    cout << res << endl;    
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
        int test; 
        cin >>test;
        while (test--)
            solve();
    return 0;
}