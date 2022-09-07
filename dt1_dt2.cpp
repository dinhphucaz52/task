// http://ntucoder.net/Problem/Details/4501
#include <iostream>
#include <vector>


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

const int maxn=1e5+5;
const int maxm=105;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

int a[maxm][maxm];
ii par[maxm][maxm];
int dp[maxm][maxm];
vii res;

void solve(){
    // fileI("dt1_dt2.inp");
    int n,m;
    cin>>m>>n;
    FOR(i,1,m)
        FOR(j,1,n)
            cin>>a[i][j];
    FOR(i,1,m-1)
        FOR(j,1,n)
            if (dp[i-1][j]>dp[i][j-1])
                par[i][j]={i-1,j},
                dp[i][j]=dp[i-1][j]+a[i][j];
            else
                par[i][j]={i,j-1},
                dp[i][j]=dp[i][j-1]+a[i][j];
    int tmp=0;
    FOR(i,1,n){
        par[m][i]={m-1,i};
        dp[m][i]=dp[m-1][i]+a[m][i];
        if (dp[m][i]>dp[m][tmp])
            tmp=i;
    }
    ii tam={m,tmp},target={1,1};
    while(tam!=target){
        res.push_back(tam);
        tam=par[tam.X][tam.Y];
    }
    res.push_back(tam);
    cout<<dp[m][tmp]<<endl;
    DOWN(i,sz(res)-1,0)
        cout<<"("<<res[i].X<<","<<res[i].Y<<")"<<endl;
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