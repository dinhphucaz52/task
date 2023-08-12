// https://vinhdinhcoder.net/Problem/Details/4681
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
#define all(x) (x).begin(),(x).end()

const int MAXN = 1e5 + 16;
const int MAXM = 1e3 + 16;
const int BASE = 311;
const int MOD = 1e9 + 7;
const int INF = 1e18;

vector<int> nums, a, cnt;

void init(int val)
{
    vector<int> tmp;
    while (val != 0)
    {
        tmp.push_back(val % 2);
        val /= 2;
    }
    reverse(all(tmp));
    for (int x : tmp)
        nums.push_back(x);
}

int get(int l, int r)
{
    return cnt[r] - cnt[l-1];
}

void solve()
{
    int n, k, x;
    cin >> n >> k;
    while (n--)
    {
        cin >> x;
        init(x);
    }
    a.push_back(0);
    cnt.push_back(0);
    a.push_back(nums[0]);
    cnt.push_back(1);
    for (int i = 1; i < sz(nums); i++)
    {
        int x = nums[i];
        if (x == a.back())
            cnt.back()++;
        else
            a.push_back(x),
            cnt.push_back(1);
    }   
    for (int i = 1; i < sz(a); i++)
    {
        a[i] = a[i-1] + (a[i] == 0);
        cnt[i] += cnt[i-1];
    }
    int res = 0;
    for (int i = 1; i < sz(a); i++)
    {
        int pos = lower_bound(all(a), a[i] - k) - a.begin();
        res = max(res, get(++pos, i));
    }
    cout << res;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    solve();
    return 0;
}
    