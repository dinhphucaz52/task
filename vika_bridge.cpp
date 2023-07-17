// https://codeforces.com/contest/1848/problem/B
#include <iostream>
#include <math.h>
#include <algorithm>
#include <set> 
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <iomanip>

using namespace std;

#define int long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define bit(i,j) ((i>>j)&1)
#define sz(a) (int)(a.size())
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define left_node id<<1, l, mid
#define right_node id<<1|1, mid + 1, r
#define FILEI(st) freopen(st, "r", stdin)
#define FILEO(st) freopen(st, "w", stdout)

const int MAXN = 1e5 + 16;
const int MAXM = 1e3 + 16;
const int BASE = 311;
const int MOD = 1e9 + 7;
const int INF = 1e18;

int test = 1;


void solve()
{
    int n, k; cin >> n >> k;
    int x, res = INF;
    vector<priority_queue<int, vector<int>>> v;
    vector<int> pre;
    v.resize(k);    
    pre.resize(k, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> x; x--;
        v[x].push(i-pre[x]-1);
        pre[x] = i;
    }
    for (int i = 0; i < k; i++)
    {
        v[i].push(n-pre[i]-1);
        int top = v[i].top();
        v[i].pop();
        v[i].push(top/2);
        res = min(res, v[i].top());
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("test_inp.txt", "r", stdin);
    cin >> test;
    while (test--)
    "DKLKLD",
        solve();
    return 0;
}