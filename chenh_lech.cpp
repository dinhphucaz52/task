// http://ntucoder.net/Problem/Details/5574
#include <iostream>
#include <vector>


using namespace std;

#define int long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORR(i,a,b) for (int i=a;i<b;i++)
#define DOWN(i,a,b) for (int i=a;i>=b;i--)
#define DOWNN(i,a,b) for (int i=a;i>b;i--)
// #define fileI(st) freopen(st,"r",stdin)
// #define fileO(st) freopen(st,"w",stdout)
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define bit(i,j) ((i>>j)&1)
#define ii pair<int,int>
#define vii vector<ii>
#define X first
#define Y second
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

int n,q,val,u,v;
int pre[maxn];

int f(int u,int v){
    int l=u,r=v;
    int res=INF;
    while(l<r){
        int mid=(l+r)>>1;
        int L=pre[mid]-pre[u-1];
        int R=pre[v]-pre[mid];
        if (L==R)
            return 0;
        else
            if (L<R)
                res=min(res,R-L),l=mid+1;
            else
                res=min(res,L-R),r=mid;            
    }
    return res;
}

void solve(){
    // fileI("chenh_lech.inp");
    cin>>n>>q;  
    FOR(i,1,n)
        cin>>val,pre[i]=pre[i-1]+val;
    while(q--){
        cin>>u>>v;
        cout<<f(u,v)<<endl;
    }
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