// https://oj.vnoi.info/problem/nkcity
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
#define ii pair<int,int>
#define vii vector<ii>
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define X first
#define Y second
#define endl "\n"

const int maxn=1e5+5;
const int maxm=1e3+5;
const int mod=1e9+7;


int n,m,u,v,w;
vii adj[maxn];
vector<int> d(maxn,mod);
vector<bool> vst(maxn,false);
void input(){
    cin>>n>>m;
    FOR(i,1,m){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
}

void prim(int s){
    priority_queue<ii,vii,greater<ii>> q;
    q.push({0,s});
    int res=0;
    while(!q.empty()){
        ii top=q.top(); q.pop();
        int dis=top.X,dinh=top.Y;
        if (vst[dinh])
            continue;
        res=dis;
        vst[dinh]=true;            
        for(ii x:adj[dinh]){
            int v=x.X,w=x.Y;
            if (!vst[v] && w<d[v]){
                d[v]=w;
                q.push({d[v],v});
            }
        }
    }
    cout<<res<<endl;
}

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/
    // fileI("main.inp");
    input();
    prim(1);
    


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