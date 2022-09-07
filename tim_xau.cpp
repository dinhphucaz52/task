// https://oj.vnoi.info/problem/v11str
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
#define all(a) a.begin(),a.end()
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
const int base=110017;

int test=1;

void testt(){
    // cin>>test;
}


int n,m,val;

int hash_n[maxn],hash_m[maxn],pow[maxn]={1};

int get_hash_value(int l,int r,int hash_t[]){
    return (hash_t[r]-hash_t[l-1]*pow[r-l+1]+mod*mod)%mod;
}

bool check_in_m(int pos){
    int l=pos,r=pos+n-1;
    int res=0;

    while(l<=r){
        int mid=(l+r)>>1;
        int hash_value_1=get_hash_value(1,mid-pos+1,hash_n);
        int hash_value_2=get_hash_value(pos,mid,hash_m);
        if (hash_value_1==hash_value_2)
            res=mid,
            l=mid+1;
        else
            r=mid-1;
    }
    if (res==pos+n-1 || res==pos+n-2)
        return true;

    if (res==0)
        res=pos-1;    

    int hash_value_1=get_hash_value(res-pos+3,n,hash_n);
    int hash_value_2=get_hash_value(res+2,pos+n-1,hash_m);

    return hash_value_1==hash_value_2;
}

void solve(){
    cin>>n>>m;
    if (n>m)
        return cout<<-1,void();
    FOR(i,1,n)
        cin>>val,
        hash_n[i]=(hash_n[i-1]*base+val+40000)%mod;

    FOR(i,1,m)
        cin>>val,
        pow[i]=(pow[i-1]*base)%mod,
        hash_m[i]=(hash_m[i-1]*base+val+40000)%mod;
    
    for (int i=1;i+n-1<=m;i++)
        if (check_in_m(i))
            return cout<<i,void();
        
    cout<<-1<<endl;
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