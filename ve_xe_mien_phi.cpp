// https://oj.vnoi.info/problem/dhfrbus
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define int long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORR(i,a,b) for (int i=a;i<b;i++)
#define DOWN(i,a,b) for (int i=a;i>=b;i--)
#define DOWNN(i,a,b) for (int i=a;i>b;i--)
#define fileI(st) freopen(st,"r",stdin)
#define fileO(st) freopen(st,"w",stdout)
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define viii vector<iii>
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define X first
#define Y second
#define endl "\n"

const int maxn=1e5+5;
const int maxm=1e3+5;
const int mod=1e9+7;
const int base=311;
const int INF=1e18+9;

vii adj[maxn];
bool vst[maxn];
int dp[maxn][6];
int n,m,s,t,k,u,v,w;

void input(){
    cin>>n>>m>>k>>s>>t;
    FOR(i,1,m){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
}


void dijkstra(int s){
    priority_queue<iii,vector<iii>,greater<iii>> q;
    memset(dp,0x3f,sizeof(dp)); dp[s][0]=0; 
    q.push({0,{s,0}});
    while(!q.empty()){
        iii top=q.top(); q.pop();
        int kc=top.X,u=top.Y.X,type=top.Y.Y;
        for(auto x:adj[u]){
            int v=x.X;
            int w=x.Y;
            if (type!=k){
                if (dp[v][type]>dp[u][type]+w){
                    dp[v][type]=dp[u][type]+w;
                    q.push({dp[v][type],{v,type}});
                }
                if (dp[v][type+1]>dp[u][type]){
                    dp[v][type+1]=dp[u][type];
                    q.push({dp[v][type+1],{v,type+1}});
                }
            }
            else{
                if (dp[v][k]>dp[u][k]+w){
                    dp[v][k]=dp[u][k]+w;
                    q.push({dp[v][k],{v,k}});
                }
            }   
        }
    }
    int res=(int)(1e18);
    FOR(i,0,k)
        res=min(res,dp[t][i]);
    cout<<res;
}

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/
    // fileI("main.inp");
    input();
    dijkstra(s);
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
//               |   | \\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
