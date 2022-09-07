#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

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

const int maxn=1e6+5;
const int maxm=2e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    cin>>test;
}

int n,m,val;
int a[205][205];

int x[2001]; int y[2001];
int u[2001]; int v[2001];

bool vst[2001];
set<int> adj[2001];
vector<int> topo;
set<int> dinh;

void init(){
    topo.clear();
    dinh.clear();
    memset(x,0x3f3f3f3f,sizeof(x)); memset(y,0x3f3f3f3f,sizeof(y));    
    memset(u,0,sizeof(u)); memset(v,0,sizeof(v));    
    memset(vst,false,sizeof(vst));
    FOR(i,1,2000)
        adj[i].clear();
}

void dfs(int u){
    vst[u]=true;
    for(int v:adj[u])
        if (!vst[v])
            dfs(v);
    topo.push_back(u);
}

void solve(){
    init();
    cin>>n>>m;

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>a[i][j]; vst[a[i][j]]=true;
            dinh.insert(a[i][j]);
            x[a[i][j]]=min(x[a[i][j]],i);
            y[a[i][j]]=min(y[a[i][j]],j);
            u[a[i][j]]=max(u[a[i][j]],i);
            v[a[i][j]]=max(v[a[i][j]],j);
        }
    }

    FOR(color,1,2000){
        if (!vst[color])
            continue;
        FOR(i,x[color],u[color]){
            FOR(j,y[color],v[color])
                if (a[i][j]!=color)
                    adj[color].insert(a[i][j]);
        }
    }

    memset(vst,false,sizeof(vst));
    
    for(int u:dinh)
        if (!vst[u])
            dfs(u);

    reverse(topo.begin(),topo.end());
    
    cout<<sz(topo)<<endl;
    for(int color:topo)
        cout<<x[color]<<" "<<y[color]<<" "<<u[color]<<" "<<v[color]<<" "<<color<<endl;
    cout<<endl;
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