// https://oj.vnoi.info/problem/fcc2021_climbing
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

const int maxn=1e6+5;
const int maxm=2e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

struct data{
    int min,max;
};

int n,m,c;
int a[maxn];
int st[4*maxn],t[4*maxn];

void build(int id,int l,int r){
    if (l==r)
        return st[id]=t[id]=a[l],void();
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=max(st[id*2],st[id*2+1]);
    t[id]=min(t[id*2],t[id*2+1]);
}

int query_max(int id,int l,int r,int u,int v){
    if (u>r || v<l)
        return -INF;
    if (u<=l && r<=v)
        return st[id];
    int mid=(l+r)>>1;
    return max(query_max(id*2,l,mid,u,v),
               query_max(id*2+1,mid+1,r,u,v));
}

int query_min(int id,int l,int r,int u,int v){
    if (u>r || v<l)
        return INF;
    if (u<=l && r<=v)
        return t[id];
    int mid=(l+r)>>1;
    return min(query_min(id*2,l,mid,u,v),
               query_min(id*2+1,mid+1,r,u,v));
}

bool check(int l,int r){
    return query_max(1,1,n,l,r)-query_min(1,1,n,l,r)<=c;
}

void solve(){
    // fileI("test.txt");
    cin>>n>>m>>c; FOR(i,1,n) cin>>a[i]; build(1,1,n);
    for(int i=1;i+m-1<=n;i++)
        if (check(i,i+m-1))
            cout<<i<<endl;
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