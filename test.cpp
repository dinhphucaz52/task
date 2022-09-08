#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = a;i <= b; i++)
#define DOWN(i, a, b) for (int i = a; i >= b; i--)
#define fileI(st) freopen(st, "r", stdin)
#define fileO(st) freopen(st, "w", stdout)
#define fileE(st) freopen(st, "w", stderr)
#define bit(i,j) ((i >> j) & 1)
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define all(a) (a).begin(),(a).end()
#define l_node (id << 1)
#define r_node (id << 1 | 1)
#define left_node id << 1, l, mid
#define right_node id << 1 | 1, mid + 1, r
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define endl "\n"

template<class P, class Q>
bool maximize(P &res, const Q &val) {
    return res < val ? res = val, true : false;
}

template<class P, class Q>
bool minimize(P &res, const Q &val) {
    return res > val ? res = val, true : false;
}

const int INF  = 1e18 + 9;
const int mod  = 1e9  + 7;
const int maxn = 1e5  + 5;
const int maxm = 5e2  + 5;
const int base = 311;

int test = 1;

void testt() {
    fileI("hld.inp");
    // cin >> test;
}

// Tree
int n, m, u, v, w;
vector<int> adj[maxn];

// HLD
int nChain, nBase;
int head[maxn]; 
int chainHead[maxn]; 
int posInBase[maxn]; 
int nChild[maxn];    

// LCA
int h[maxn];         
int up[20][maxn];  

// ST
int st[maxn * 4 + 100]; 
vector<int> cost(maxn);

void enter() { 
    fileI("test.inp"); fileO("test.out");
    cin >> n; 
    FOR (i, 2, n)
        cin >> u >> v,
        adj[u].push_back(v),
        adj[v].push_back(u);
}


void dfs(int u, int pre) { 
    nChild[u] = 1;
    FOR (i, 1, 17)
        up[i][u] = up[i-1][up[i-1][u]];
    for (int v : adj[u]) {
        if (v == pre)
            continue;
        up[0][v] = u; h[v] = h[u] + 1; 
        dfs(v, u);
        nChild[u] += nChild[v];
    }
}

// Heavy Light Decomposition
void hld(int u) { 
    if (chainHead[nChain] == 0) 
        chainHead[nChain] = u;
    posInBase[u] = ++nBase; head[u] = chainHead[nChain];
    int mxVtx = -1;
    for (int v : adj[u]) {
        if (v != up[0][u]) 
            if (mxVtx == -1 || nChild[v] > nChild[mxVtx]) 
                mxVtx = v; 
    }
    if (mxVtx > -1)
        hld(mxVtx);

    for (int v : adj[u]) {
        if (v != up[0][u] && v != mxVtx) {
            nChain++;
            hld(v);
        }
    }
}

// Lowest Common Ancestor
int LCA(int u, int v ){ 
    if (u == v)
        return u;
    if (h[u] < h[v])
        swap(u, v);
    int k = h[u] - h[v];
    for (int i = 0; 1 << i <= u; i++)
        if (bit(k, i))
            u = up[i][u];
    if (u == v) 
        return u;
    k = __lg(h[u]);
    DOWN (i, k, 0)
        if (up[i][u] != up[i][v])
            u = up[i][u],
            v = up[i][v];
    return u == v ? u : up[0][u];
}

// Segment Tree
struct segment_tree {
    private:
        vector<int> st;
    public:
        void init() {
            st.resize(maxn<<2, 0);
        }
        void build(int id, int l, int r, const vector<int> & cost) {
            if (l == r)
                return st[id] = cost[l], void();
            int mid = (l + r) >> 1;
            build(left_node, cost); build(right_node, cost);
            st[id] = __gcd(st[id<<1], st[id<<1|1]);        
        }
        void build(vector<int> & cost) {build(1, 1, n, cost);}
        void update(int id, int l, int r, int node, int val) {
            if (node > r || node < l)
                return;
            if (l == r)
                return st[id]+= val, void();
            int mid = (l + r) >> 1;
            update(left_node, node, val); update(right_node, node, val);
            st[id] = __gcd(st[id<<1], st[id<<1|1]);
        }
        void update(int node, int val) {update(1, 1, n, node, val);}
        int get(int id, int l, int r, int u, int v) {
            if (u > r || v < l || u > v)
                return 0;
            if (u <= l && r <= v)
                return st[id];
            int mid = (l + r) >> 1;
            return __gcd(get(left_node, u, v), get(right_node, u, v));
        }
        int get(int u, int v) { return get(1, 1, n, u, v);}
};

segment_tree s;

void update_query(int u, int v, int val) { 
    int node = max(posInBase[u], posInBase[v]); 
    s.update(node, val);
}

int gcd_query(int u, int v) {  
    int lca = LCA(u, v); 
    int res = 0;
    while (head[u] != head[lca]) {
        res = __gcd(s.get(posInBase[head[u]], posInBase[u]), res);
        u = up[0][head[u]];
    }
    while (head[v] != head[lca]) {
        res = __gcd(s.get(posInBase[head[v]], posInBase[v]), res);
        v = up[0][head[v]];
    }
    if (posInBase[u] < posInBase[v])
        swap(u, v);
    res = __gcd(res, s.get(posInBase[lca], posInBase[u]));
    return res;
}


void solve() {
    enter(); h[1] = 0; up[0][1] = 1;
    dfs(1, 1); hld(1); s.init(); s.init(); s.build(cost);
}

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/

    testt();
    while (test--)
        solve();


    /*-------------*/
    return 0;
}