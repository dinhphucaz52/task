#include <iostream>
#include <vector>
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
const int maxm=1e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

int f[2][20][maxn];

int querymin(int l,int r){
    int tmp=__lg(r-l+1);
    return min(f[0][tmp][l],f[0][tmp][r-(1<<tmp)+1]);
}

int querymax(int l,int r){
    int tmp=__lg(r-l+1);
    return max(f[1][tmp][l],f[1][tmp][r-(1<<tmp)+1]);
}

void solve(){
    int n; cin>>n;
    FOR(i,1,n)
        cin>>f[0][0][i],
        f[1][0][i]=f[0][0][i];
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
            f[0][i][j]=min(f[0][i-1][j],f[0][i-1][j+(1<<(i-1))]),
            f[1][i][j]=max(f[1][i-1][j],f[1][i-1][j+(1<<(i-1))]);
    vector<int> res;
    for(int k=1;k<n;k++)
        if (querymax(1,k)<=querymin(k+1,n))
            res.push_back(k);
    cout<<sz(res)<<endl;
    for(int x:res)
        cout<<x<<" ";
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