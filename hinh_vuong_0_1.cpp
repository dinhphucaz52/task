// https://oj.vnoi.info/problem/qbsquare
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

void testt(){
    // cin>>test;
}
int m,n,val;
int pre[maxm][maxm];

bool get(int a,int b,int k){
    int x=a+k-1;
    int y=b+k-1;
    int res=pre[x][y]+pre[a-1][b-1]-pre[x][b-1]-pre[a-1][y];
    if (res==k*k || res==0)
        return true;
    return false;
}

void solve(){
    // fileI("hinh_vuong_0_1.inp");
    pre[0][0]=pre[0][1]=pre[1][0]=0;
    cin>>m>>n;
    FOR(i,1,m)
        FOR(j,1,n){
            cin>>val;
            pre[i][j]=pre[i][j-1]+pre[i-1][j]
                     -pre[i-1][j-1]+val;
        }
    int res=1;
    for(int i=1;i+res<=m;i++)
        for(int j=1;j+res<=n;j++)
            for(int k=res+1;k<=min(m-i+1,n-j+1);k++)
                if (get(i,j,k)){
                    res=max(res,k);
                    // cout<<i<<" "<<j<<" "<<k<<" "<<"true"<<endl;
                }
                else{
                    // cout<<i<<" "<<j<<" "<<k<<" "<<"false"<<endl;
                    break;
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