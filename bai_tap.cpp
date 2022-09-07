// https://oj.vnoi.info/problem/tht21_ckb_task
#include <iostream>
#include <algorithm>
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

int m,n;
int a[maxn];
int d[20][maxn];

int query(int l,int r){
    int tmp=__lg(r-l+1);
    return max(d[tmp][l],d[tmp][r-(1<<tmp)+1]);
}

int del(){
    int res=INF;
    n--;
    FOR(i,1,n)
        d[0][i]=a[i+1]-a[i];
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
            d[i][j]=max(d[i-1][j],d[i-1][j+(1<<(i-1))]);
    m--;
    for(int i=1;i+m-1<=n;i++)
        res=min(res,query(i,i+m-1));        
    return res;
}


int dis[maxn];

bool f(int a[],int dis,int k){
    int cnt=0;
    FOR(i,1,n-1){
        int tmp=a[i+1]-a[i];
        if (tmp%dis==0)
            cnt+=(tmp/dis-1);
        else
            cnt+=(tmp/dis);
        if (cnt>k)
            return false;
    }
    return true;
}

void ins(int val){
    int l=1,r=INF,res=INF;
    while(l<r){
        int mid=(l+r)>>1;
        if (f(a,mid,val))
            r=mid,
            res=min(res,mid);
        else
            l=mid+1;
    }    
    cout<<res<<endl;
}

void solve(){
    // fileI("new.inp");
    cin>>n>>m;
    FOR(i,1,n)
        cin>>a[i];
    sort(a+1,a+n+1);
    if (m==n){
        int res=0;
        FOR(i,1,n-1)
            res=max(res,a[i+1]-a[i]);
        cout<<res;
        return; 
    }
    if (m<n)
        cout<<del();
    else
        ins(m-n);
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