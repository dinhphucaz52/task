// https://oj.vnoi.info/problem/lubenica
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORR(i,a,b) for (int i=a;i<b;i++)
#define DOWN(i,a,b) for (int i=a;i>=b;i--)
#define DOWNN(i,a,b) for (int i=a;i>b;i--)
#define fileI(st) freopen(st,"r",stdin)
#define fileO(st) freopen(st,"w",stdout)
#define all(a) a.begin(),a.end()
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define bit(i,j) ((i>>j)&1)
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define endl "\n"

const int maxn=1e6+5;
const int maxm=2e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

int n,q,u,v,w;
vii adj[maxn];
bool vst[maxn];
int up[20][maxn],h[maxn];
int max_dis[20][maxn],min_dis[20][maxn];

void dfs(int u){
    vst[u]=true;
    FOR(i,1,17)
        up[i][u]=up[i-1][up[i-1][u]],
        max_dis[i][u]=max(max_dis[i-1][u],max_dis[i-1][up[i-1][u]]),
        min_dis[i][u]=min(min_dis[i-1][u],min_dis[i-1][up[i-1][u]]);
    for (auto x:adj[u]){
        v=x.fi,w=x.se;
        if (!vst[v])
            up[0][v]=u,
            h[v]=h[u]+1,
            max_dis[0][v]=min_dis[0][v]=w,
            dfs(v);
    }
}

void query(int u,int v){
    if (h[u]<h[v])
        swap(u,v);
    int res_min=INF,res_max=-INF;
    for (int i=0;(1<<i)<=h[u]-h[v];i++)
        if (bit(h[u]-h[v],i))
            res_max=max(res_max,max_dis[i][u]),
            res_min=min(res_min,min_dis[i][u]),
            u=up[i][u];
    if (u==v)
        return cout<<res_min<<" "<<res_max<<endl,void();
    int k=__lg(h[u]);
    DOWN(i,k,0)
        if (up[i][u]!=up[i][v])
            res_max=max({res_max,max_dis[i][u],max_dis[i][v]}),
            res_min=min({res_min,min_dis[i][u],min_dis[i][v]}),
            u=up[i][u],
            v=up[i][v];
    res_max=max({res_max,max_dis[0][u],max_dis[0][v]});
    res_min=min({res_min,min_dis[0][u],min_dis[0][v]});
    cout<<res_min<<" "<<res_max<<endl;
}

void init(int root){
    h[root]=1; 
    up[0][root]=root; 
    max_dis[0][root]=-INF;
    min_dis[0][root]=INF;
    dfs(root);
}

void inp(){
    cin>>n;
    FOR(i,2,n)
        cin>>u>>v>>w,
        adj[u].push_back({v,w}),
        adj[v].push_back({u,w});
    init(1);
}

void solve(){
    // fileI("main.inp");
    inp();
    cin>>q;
    while (q--)
        cin>>u>>v,
        query(u,v);
}

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/

    testt();
    while(test--){
        solve();
    }


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