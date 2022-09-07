// https://oj.vnoi.info/problem/atcoder_dp_h
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

int test=1;
int dp[maxm][maxm];

void testt(){
    // cin>>test;
}

void solve(){
    int n,m;
    char ch;
    // fileI("grid_1.inp");
    cin>>n>>m;
    dp[1][1]=1;
    FOR(i,1,n)
        FOR(j,1,m){
            cin>>ch;
            if (ch=='#')
                dp[i][j]=0;
            else
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%mod; 
        }
    cout<<dp[n][m];
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