// https://oj.vnoi.info/problem/hsgso20_baba
#include <iostream>
#include <vector>
#include <map>


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

string s;
int type,pre11,pre3;
ii res={0,0};
map<int,int> a[3];

ii get(ii a,ii b){
    if (a.se-a.fi>b.se-b.fi)
        return a;
    else if (a.se-a.fi<b.se-b.fi)
        return b;
    int n=a.se-a.fi;
    FOR(i,0,n)
        if (s[a.fi+i]>s[b.fi+i])
            return a;
        else if (s[a.fi+i]<s[b.fi+i])
            return b;
    return a;
}

void solve(){
    cin>>s>>type; int n=len(s); s=" "+s; 
    FOR(i,1,n){
        pre3=(pre3+(s[i]-'0'))%3;
        if ((i&1)==1)
            pre11+=(s[i]-'0');
        else
            pre11-=(s[i]-'0');
        auto it=a[pre3].find(pre11);
        if (it==a[pre3].end())
            a[pre3][pre11]=i;
        else
            res=get(res,{it->se,i});
    }   
    for(int i=res.fi+1;i<=res.se;i++)
        cout<<s[i];
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