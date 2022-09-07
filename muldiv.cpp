// https://oj.vnoi.info/problem/bedao_g02_muldiv
#include <iostream>
#include <vector>
#include <math.h>

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
const int mod=998244353;

int test=1;

void testt(){
    cin>>test;
}

int npow(int a,int b){
    if (b==1)
        return a%mod;
    int res=npow(a,b>>1);
    res=(res*res)%mod;
    if(b&1==1)
        res=(res*a)%mod;
    return res;
}

void solve(){
    int n,i=2,cnt=1,n2;
    cin>>n;
    n2=n;
    while(i*i<=n){
        int tmp=0;
        while(n%i==0){
            tmp++;
            n/=i;
        }
        cnt*=(tmp+1);
        i++;
    }
    if (n!=1)
        cnt*=2;
    int res=sqrt(n2);
    if (cnt%2==0)
        res=1;
    res=res*npow(n2,(int)(cnt/2))%mod;
    cout<<res<<endl;
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