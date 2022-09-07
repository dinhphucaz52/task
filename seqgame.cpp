// https://oj.vnoi.info/problem/bedao_g01_seqgame
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

int n;
int a[maxn];
int st[4*maxn],t[4*maxn];

void down(int id){
    int tmp=t[id]; t[id]=0;
    st[id*2]+=tmp; t[id*2]+=tmp;
    st[id*2+1]+=tmp; t[id*2+1]+=tmp;
}

void upd(int id,int l,int r,int u,int v,int val){
    if (u>r || v<l)
        return;
    if (u<=l && r<=v){
        st[id]+=val;
        t[id]+=val;
        return;
    }
    down(id);
    int mid=(l+r)>>1;
    upd(id*2,l,mid,u,v,val);
    upd(id*2+1,mid+1,r,u,v,val);
    st[id]=max(st[id*2],st[id*2+1]);
}


int q,l[maxn],r[maxn],val[maxn];

void solve(){
    // fileI("new.inp");
    cin>>n>>q;
    FOR(i,1,q)
        cin>>l[i]>>r[i]>>val[i],
        upd(1,1,n,l[i],r[i],val[i]);
    int res=st[1];
    FOR(i,1,q)
        upd(1,1,n,l[i],r[i],-val[i]),
        res=min(res,st[1]),
        upd(1,1,n,l[i],r[i],val[i]);
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