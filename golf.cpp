#include <iostream>
#include <vector>
#include <cstring>
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
#define fi first
#define se second
#define endl "\n"

const int maxn=1e6+5;
const int maxm=5e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

int n,m;
int a[maxm][maxm];
bool vst[maxm][maxm];

const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};

vii hole;

bool check(int u,int v){
    return (!vst[u][v] && u>=1 && u<=n && v>=1 && v<=m);
}

bool bfs (int u,int v,int d){
    memset(vst,false,sizeof(vst));
    queue<ii> q; q.push({u,v}); vst[u][v]=true;

    while (!q.empty()){
        int x=q.front().fi; int y=q.front().se; q.pop();
        for (int i=0;i<4;i++){
            int u=x+dx[i],v=y+dy[i];
            if (check(u,v) && abs(a[x][y]-a[u][v])<=d)
                q.push({u,v}),
                vst[u][v]=true;
        }
    }
    for (ii x:hole)
        if (!vst[x.fi][x.se])
            return false;
    return true;
}

void solve(){
    fileI("golf.inp"); fileO("golf.out");
    
    cin>>n>>m;
    FOR(i,1,n)
        FOR(j,1,m)
            cin>>a[i][j];
    int val;
    FOR(i,1,n){
        FOR(j,1,m){
            cin>>val;
            if (val==1)
                hole.push_back({i,j});       
        }
    }

    int l=0,r=1e9,res=INF; 
    int u=hole[0].fi,v=hole[0].se;

    while (l<=r){
        int mid=(l+r)>>1;
        if (bfs(u,v,mid))
            res=min(res,mid),
            r=mid-1;
        else
            l=mid+1;
    }
    cout<<res;
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