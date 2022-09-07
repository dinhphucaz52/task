// https://oj.vnoi.info/problem/fct020_seq51
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
#define fi first
#define se second
#define endl "\n"

const int maxn=1e5+5;
const int maxm=1e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

int n,res,a[maxn],sp[20][maxn];

int query(int l,int r){
    int tmp=__lg(r-l+1);
    return min(sp[tmp][l],sp[tmp][r-(1<<tmp)+1])+l-1;
}

void solve(){
    // fileI("new.inp");
    cin>>n;
    FOR(i,1,n)
        cin>>a[i],
        sp[0][i]=a[i]-i;
    for (int i=1;(1<<i)<=n;i++)
        for (int j=1;j+(1<<i)-1<=n;j++)
            sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
    FOR(i,1,n){
        int l=i,r=n,tmp=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if (query(i,mid)>=0)
                tmp=mid,
                l=mid+1;
            else
                r=mid-1;
        }
        res=max(res,tmp-i+1);
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








