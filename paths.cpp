// https://oj.vnoi.info/problem/tht21_tphcm_ckc_paths
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORR(i,a,b) for (int i=a;i<b;i++)
#define DOWN(i,a,b) for (int i=a;i>=b;i--)
#define DOWNN(i,a,b) for (int i=a;i>b;i--)
#define fileI(st) freopen(st,"r",stdin)
#define fileO(st) freopen(st,"w",stdout)
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define bit(i,j) ((i>>j)&1)
#define ii pair<int,int>
#define vii vector<ii>
#define X first
#define Y second
#define endl "\n"
#define elif else if 
const int maxn=2e5+5;
const int maxm=1e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

struct data{int u,v,w;};
int n,m,u[maxn],v[maxn],w[maxn],sum;
int par[maxn];
vii adj[maxn];
bool vst[maxn];
vii mst[maxn];

void inp(){
    cin>>n>>m;
    FOR(i,1,m)
        cin>>u[i]>>v[i]>>w[i],
        adj[u[i]].push_back({v[i],w[i]}),
        adj[v[i]].push_back({u[i],w[i]});
}
void prim(int s){
    priority_queue<ii,vii,greater<ii>> q;
    vector<int> d(maxn,INF); 
    d[s]=0; q.push({d[s],s});
    while(!q.empty()){
        int u=q.top().Y,dis=q.top().X; q.pop();
        if (vst[u])
            continue;
        vst[u]=true;
        if (u!=s)
            sum=sum+dis,
            mst[par[u]].push_back({u,dis});
        for(ii x:adj[u]){
            int v=x.X,w=x.Y;
            if (d[v]>w)
                d[v]=w,
                q.push({w,v}),
                par[v]=u;
        }
    }
}

int h[maxn],kc[20][maxn],up[20][maxn];

void dfs(int u){
    h[u]=h[par[u]]+1;
    up[0][u]=par[u];
    FOR(i,1,17)
        up[i][u]=up[i-1][up[i-1][u]],
        kc[i][u]=max(kc[i-1][u],kc[i-1][up[i-1][u]]);
    for(ii x:mst[u])
        kc[0][x.X]=x.Y,
        par[x.X]=u,
        dfs(x.X);
}

void init(int root){
    h[root]=-1; par[root]=root;
    dfs(root);
}

int anc(int u,int k){
    for(int i=0;(1<<i)<=k;i++)
        if (bit(k,i))
            u=up[i][u];
    return u;
}

int lca(int u,int v){
    if (h[u]<h[v])
        swap(u,v);
    u=anc(u,h[u]-h[v]);
    if (u==v)
        return u,v;
    int k=__lg(h[u]);
    DOWN(i,k,0)
        if (up[i][u]!=up[i][v])
            u=up[i][u],
            v=up[i][v];
    return up[0][u];
}

int dis(int u,int v){
    int res=0;
    int tmp=lca(u,v);
    int k=h[u]-h[tmp];
    for(int i=0;(1<<i)<=k;i++)
        if (bit(k,i))
            res=max(res,kc[i][u]),
            u=up[i][u];
    k=h[v]-h[tmp];
    for(int i=0;(1<<i)<=k;i++)
        if (bit(k,i))
            res=max(res,kc[i][v]),
            v=up[i][v];
    return res;
}

int f(int u,int v,int w){
    return sum-dis(u,v)+w;
}

void solve(){
    fileI("new.inp");
    inp();
    prim(1); 
    init(1);
    FOR(i,1,m)
        cout<<f(u[i],v[i],w[i])<<endl;
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