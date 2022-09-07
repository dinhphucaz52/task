// https://codeforces.com/contest/1712/problem/C
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>


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

const int maxn= 1e6+5;
const int maxm=2e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    cin>>test;
}

int n;
int a[maxn];
int cnt[maxn];

void solve(){
    cin>>n;
    FOR(i,1,n)
        cin>>a[i],
        cnt[a[i]]=i;
    int target=0;
    for (int i=n-1;i>=1;i--)
        if (a[i]>a[i+1]){
            target=i;
            break;
        }
    if (target==0)
        return cout<<0<<endl,void();
    unordered_set<int> s;
    for (int i=1;i<=target;i++)
        s.insert(a[i]),
        target=max(target,cnt[a[i]]);
    cout<<sz(s)<<endl;
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