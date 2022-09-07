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

int k=1;
int a[maxm][maxm];

void f(int id,int m,int n){
    if (m==1){
        FOR(i,id,id+n-1)
            a[id][i]=k,k++;
        return;
    }
    if (n==1){
        FOR(i,id,id+m-1)
            a[i][id]=k,k++;
        return;
    }
    FOR(i,id,id+n-1)
        a[id][i]=k,k++;
    FOR(i,id+1,id+m-1)
        a[i][id+n-1]=k,k++;
    DOWN(i,id+n-2,id)
        a[id+m-1][i]=k,k++;
    DOWN(i,id+m-2,id+1)
        a[i][id]=k,k++;
}


void solve(){
    int m,n,id=1;
    cin>>m>>n;
    int M=m,N=n,gh=m*n;
    while(free){
        f(id,m,n);
        if (k>gh)
            break;
        id++,m-=2,n-=2;
    }
    fileO("ma_tran_xoan_oc.out");
    FOR(i,1,M){
        FOR(j,1,N)  
            cout<<a[i][j]<<" ";
        cout<<endl;
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