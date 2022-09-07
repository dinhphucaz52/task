// https://codeforces.com/contest/1709/problem/D
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

const int maxn=2e5+5;
const int maxm=1e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

int n,m;
int a[maxn];
int st[4*maxn];

void build(int id,int l,int r){
    if (l==r){
        st[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=max(st[id*2],st[id*2+1]);
}

int query(int id,int l,int r,int u,int v){
    if (v<l || u>r)
        return -INF;
    if (u<=l && r<=v) {
        return st[id];
    }
    int mid=(l+r)>>1;
    return max(query(id*2,l,mid,u,v),query(id*2+1,mid+1,r,u,v));
}  



void solve(){
    cin>>n>>m;
    FOR(i,1,m) cin>>a[i]; build(1,1,m);
    int q; cin>>q; int u,v,s,t,k;
    while(q--){
        cin>>u>>v>>s>>t>>k;
        int block=query(1,1,m,min(v,t),max(v,t));
        if (block>=n){
            cout<<"NO"<<endl;
            continue;
        }
        if (abs(u-s)%k!=0 || abs(v-t)%k!=0)
            cout<<"NO"<<endl;
        else{
            u=max(u,s);
            int tmp=(n-u)/k*k;
            u+=tmp;
            if (u>block && u<=n)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
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