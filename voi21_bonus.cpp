// https://oj.vnoi.info/problem/voi21_bonus
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = a;i <= b; i++)
#define DOWN(i, a, b) for (int i = a; i >= b; i--)
#define fileI(st) freopen(st, "r", stdin)
#define fileO(st) freopen(st, "w", stdout)
#define fileE(st) freopen(st, "w", stderr)
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define bit(i,j) ((i>>j)&1)
#define all(a) (a).begin(),(a).end()
#define left_node id<<1,l,mid
#define right_node id<<1|1,mid+1,r
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
const int maxn = 3e5  + 5;
const int maxm = 1e5  + 5;
const int base = 311;

int test = 1;

void testt() {
    // fileI("test.inp"); 
    // cin >> test;
}

int n, m, w[maxn], dp[maxn]; string s[maxn];
vector<int> cost[maxm], adj[maxm];

struct node {
    int val = 0;
    node * child[26];
};

typedef struct node* trie;

trie push() {
    trie tmp = new node();
    FOR (i, 0, 25)
        tmp->child[i] = NULL;
    return tmp;
}

trie root = push();

void insert(string s, int val, int k) {
    int id, tmp = -1; trie p = root;
    for (char x : s) {
        id = x - 'A';
        if (p->child[id] == NULL) 
            p->child[id] = push();
        p = p->child[id];
    }
    FOR (i, 0, 25)
        if (p->child[i] != NULL)
            maximize(tmp, p->child[i]->val);
    tmp = (tmp == -1 ? val : tmp + val);    
    p = root; maximize(dp[k], tmp);
    if (!adj[val].empty())
        for (int u : adj[val])
            if (u > k)
                maximize(dp[u], dp[k] + w[u]);
    for (char x : s) {
        id = x - 'A';
        maximize(p->child[id]->val, dp[k]);
        p = p->child[id];
    }
}

void solve() {
    cin >> n >> m; int res = 0;
    FOR (i, 1, n)
        cin >> s[i] >> w[i],
        cost[w[i]].push_back(i);
    int u, v;
    while (m--) {
        cin >> u >> v; 
        if (!cost[u].empty())
            for (int x : cost[u])
                adj[v].push_back(x);
        if (!cost[v].empty())
            for (int x : cost[v])
                adj[u].push_back(x);
    }
    FOR (i, 1, n)
        insert(s[i], w[i], i),
        maximize(res, dp[i]);
    cout << res << endl;
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
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \|     |// '.
//                 / \|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
