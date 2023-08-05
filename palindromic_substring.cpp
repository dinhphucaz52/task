// https://www.hackerrank.com/contests/security-challenge/challenges/largest-palindromic-substring/problem
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
const int MOD  = 1e9 + 7;
const int INF = 1e18;

string a; 
vector<int> p, pre, suf;

int getL(int l,int r){
    return (pre[r] - pre[l-1] * p[r-l+1] + MOD * MOD ) % MOD ;
}
int getR(int l,int r){
    return (suf[l] - suf[r+1] * p[r-l+1] + MOD * MOD) % MOD;
}

void xuat(int l,int r){
    for (int i = l; i <= r; i++)
        cout << a[i];
}

bool check(int mid)
{
    for (int i = 1; i + mid - 1 < sz(a); i++)
        if (getL(i, i + mid - 1) == getR(i, i + mid - 1))
            return true;
    return false;
}

void solve(){
    // freopen("temp.inp", "r" ,stdin);
    cin >> a;
    int n = sz(a); a = " " + a; 
    p.resize(sz(a));
    pre = suf = p; p[0] = 1;
    for (int i = 1; i <= n; i++)
        pre[i] = (pre[i-1] * BASE + a[i] - 'a' + 1) % MOD,
        p[i] = (p[i-1] * BASE) % MOD;
    for (int i = n; i >= 1; i--)
        suf[i] = (suf[i+1] * BASE + a[i] - 'a' + 1) % MOD;
    int res = 1, l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (mid % 2 == 0)
            mid++;
        if (mid > r)
            break;
        if (check(mid))
            res = max(res, mid),
            l = ++mid;
        else
            r = --mid;
    }
    l = 1; r = n;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (mid % 2 == 1)
            mid++;
        if (mid > r)
            break;
        if (check(mid))
            res = max(res, mid),
            l = ++mid;
        else
            r = --mid;
    }
    for (int i = 1; i + res - 1 < sz(a); i++)
        if (getL(i, i + res - 1) == getR(i, i + res - 1))
        {
            xuat(i, i + res - 1);
            break;
        }
}
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}