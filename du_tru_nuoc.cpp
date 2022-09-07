// https://oj.vnoi.info/problem/olp_kc20_buildcol
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

int n,m,a[maxn],best=-INF,block;

bool check(int a[],int n,int up,int target){
    int tmp,new_tmp,res,sum; res=sum=0;
    tmp=max(up,a[1]); 
    for(int i=2;i<=block;i++){
        new_tmp=max(up,a[i]);
        if (new_tmp>=tmp) 
            tmp=new_tmp; 
        else 
            res+=tmp-max(up,new_tmp);
    } 
    tmp=max(up,a[n]); 
    for(int i=n-1;i>=block;i--){
        new_tmp=max(up,a[i]);
        if (new_tmp>=tmp) 
            tmp=new_tmp; 
        else 
            res+=tmp-max(up,new_tmp);
    } 
    if (res<target)
        return false;
    return true;
}

void solve(){
    // fileI("test.txt");
    cin>>n>>m; 
    FOR(i,1,n){
        cin>>a[i];
        if (a[i]>best)
            best=a[i],
            block=i;
    }
    int ans=-1;
    int l=1,r=INF;
    while(l<=r){
        int mid=(l+r)>>1;
        if (check(a,n,mid,m)==true)
            l=mid+1,
            ans=mid;
        else
            r=mid-1;
    }    
    cout<<ans;
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