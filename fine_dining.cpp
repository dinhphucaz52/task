// https://oj.vnoi.info/problem/usaco18dg_dining
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>    

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
#define fi first
#define se second
#define endl "\n"

const int maxn=5e4+5;
const int maxm=2e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;
int test=1;

void testt(){
    // cin>>test;
}

int n,m,k,u,v,w;
vii adj[maxn];
vector<vector<int>> d(2,vector<int> (maxn,INF));

void dijkstra(int s,vector<int>& d){
    priority_queue<ii,vii,greater<ii>> q; 
    d[s]=0; q.push({d[s],s});
    while(!q.empty()){
        ii top=q.top(); q.pop();
        int u=top.se,dis=top.fi;
        if (dis>d[u])
            continue;
        for(ii x:adj[u]){
            int v=x.fi,w=x.se;
            if (d[v]>d[u]+w)
                d[v]=d[u]+w,
                q.push({d[v],v});
        }
    }    
}

void solve(){
    cin>>n>>m>>k;
    while(m--)
        cin>>u>>v>>w,
        adj[u].push_back({v,w}),
        adj[v].push_back({u,w});
    dijkstra(n,d[0]);
    while(k--)
        cin>>u>>v,
        adj[n+1].push_back({u,d[0][u]-v});
    dijkstra(n+1,d[1]);
    FORR(i,1,n)
        if (d[1][i]>d[0][i])
            cout<<0<<endl;
        else
            cout<<1<<endl;
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