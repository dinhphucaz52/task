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
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define DOWN(i, a, b) for(int i = a; i >= b; i--)
#define sz(a) (int)(a.size())
#define ii pair<int, int>
#define bit(i, j) ((i>>j)&1)
#define left_node id<<1,l,mid
#define right_node id<<1|1,mid+1,r

const int MAXN = 1e5 + 16;
const int MAXM = 1e3 + 16;
const int BASE = 311;
const int MOD = 1e9 + 7;
const int INF = 1e18;

struct myData
{
    public:
        int x, y;
        myData(){};
        myData(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
        friend ostream & operator << (ostream & cout, myData & a)
        {
            cout << a.x << " " << a.y;
            return cout;
        }
        myData operator + (myData a)
        {
            return myData(this->x + a.x, this->y + a.y);
        }
        void xoay(int k)
        {
            k %= 4;
            for (int i = 1; i <= k; i++)
            {
                swap(this->x, this->y);
                this->y *= -1;
            }
        }
};

myData add[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
myData st[MAXN];
int lazy[MAXN];

int get_id(char x)
{
    if (x == 'N')
        return 0;
    if (x == 'E')
        return 1;
    if (x == 'S')
        return 2;
    return 3;
}
void build(int id, int l, int r, vector<myData> & a)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(left_node, a);
    build(right_node, a);
    st[id] = st[id<<1] + st[id<<1|1];
}
void update(int id, int l, int r, int node, char x)
{
    if (node > r || node < l)
        return;
    if (l == r)
    {
        cout << id << endl;
        return st[id] = add[get_id(x)], void();
    }
    int mid = (l + r) >> 1;
    update(left_node, node, x);
    update(right_node, node, x);
    st[id] = st[id<<1] + st[id<<1|1];
}
void down(int id)
{
    int tmp = lazy[id];
    st[id<<1].xoay(tmp); lazy[id<<1] += tmp;
    st[id<<1|1].xoay(tmp); lazy[id<<1|1] += tmp;
}
void range_update(int id, int l, int r, int u, int v, int k)
{
    if (u > r || v  < l)
        return;
    if (u <= l && r <= v)
        {
            lazy[id] += k;
            st[id].xoay(k);
            return;
        }    
    down(id);
    int mid = (l + r) >> 1;
    range_update(left_node, u, v, k);
    range_update(right_node, u, v, k);
    st[id] = st[id<<1] + st[id<<1|1];
}
bool check(myData a)
{
    if (a.x == a.y == 0)
        return true;
    return false;
}

void solve()
{
    freopen("test.inp", "r", stdin);
    vector<myData> a;
    a.push_back(myData(0, 0));
    string s;
    cin >> s;
    int n = sz(s);
    for(char x : s)
        a.push_back(add[get_id(x)]);
    build(1, 1, n, a);
    cout << st[1];
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}