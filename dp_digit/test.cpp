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



int dp[18][200];
vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int g(int x, int target)
{
    string s = to_string(x);
    if (sz(s) == 1)
        return x < target ? 0 : 1;
    int tmp = 0;
    for (int i = 0; i < s[0] - '0'; i++)
        tmp += dp[sz(s)-1][target-i];
    int n = s[0] - '0';
    return tmp + g(x - n * pow(10, sz(s) - 1), target - n);
}

void solve()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    for (int x : digits)
        dp[1][x] = 1;
    for (int i = 1; i < 18; i++)
        dp[i][0] = 1;
    for (int i = 2; i < 18; i++)
        for (int tong = 1; tong <= 9 * i; tong++)
            for (int x : digits)
                if (tong - x >= 0)
                    dp[i][tong] += dp[i-1][tong - x];
    int x, target;
    cin >> x >> target;
    cout << g(x, target) << endl;
    for (int i = 1; i <= x; i++)
    {
        string s = to_string(i);
        int tmp = 0;
        for (char x : s)
            tmp += x - '0';
        if (tmp == target)
            cout << i << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}