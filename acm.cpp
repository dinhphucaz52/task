// https://oj.vnoi.info/problem/acmnb
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORR(i,a,b) for (int i=a;i<b;i++)
#define DOWN(i,a,b) for (int i=a;i>=b;i--)
#define DOWNN(i,a,b) for (int i=a;i>b;i--)
#define fileI(st) freopen(st,"r",stdin)
#define fileO(st) freopen(st,"w",stdout)
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define X first
#define Y second
#define endl "\n"

const int maxn=2e5+5;
const int maxm=1e3+5;
const int mod=1e9+7;

int test=1;

void testt(){
    // cin>>test;
}

vector<iii> v;
void solve(){
    int n,a,b;
    // fileI("acm.inp");
    cin>>n;
    n*=2;
    FOR(i,1,n){
        cin>>a>>b;
        v.push_back({a-b,{a,b}});
    }
    sort(v.begin(),v.end());
    int res=0;
    n=n/2;
    FORR(i,0,n){
        res+=v[i].Y.X;
    }
    FORR(i,n,2*n)
        res+=v[i].Y.Y;
    cout<<res;
}


signed main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/

    while(test--){
        solve();
    }


    /*-------------*/
    return 0;
}
/*
//                   _oo0oo_
//                  o8888888o
//                  88" . "88
//                  (| -_- |)
//                  0\  =  /0
//                ___/`---'\___
//              .' \|     |// '.
//             / \|||  :  |||// \
//            / _||||| -:- |||||- \
//           |   | \  -  /// |   |
//           | \_|  ''\---/''  |_/ |
//           \  .-\__  '-'  ___/-. /
//         ___'. .'  /--.--\  `. .'___
//      ."" '<  `.___\_<|>_/___.' >' "".
//     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//     \  \ `_.   \_ __\ /__ _/   .-` /  /
// =====`-.____`.___ \_____/___.-`___.-'=====
//                   `=---='
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/