// https://oj.vnoi.info/problem/poi10_kol
#include <iostream>
#include <vector>
#include <stack>

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
const int mod=1e9+7;

int test=1;

void solve(){
    stack<int> s1,s2;
    vector<int> res;
    int n,a[maxn];
    // fileI("railway.inp");
    cin>>n;
    FOR(i,1,n) 
        cin>>a[i];
    /*-------------*/
    int k=1;
    FOR(i,1,n){
        if (a[i]==k) {res.push_back(1); k++; continue;}
        if (s1.empty()){
            s1.push(a[i]);
            res.push_back(1);
            continue;
        }
        if (s2.empty()){
            s2.push(a[i]);
            res.push_back(2);
            continue;
        }
        if (s1.top()==k) {s1.pop(); k++; continue;}       
        if (s2.top()==k) {s2.pop(); k++; continue;}       
        if (a[i]<s1.top()) s1.push(a[i]),res.push_back(1);
        if (a[i]<s2.top()) s2.push(a[i]),res.push_back(2);
        cout<<"NIE";
        return;
    }
    cout<<"TAK"<<endl;
    for(int x:res)
        cout<<x<<" ";
    /*-------------*/
}


int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/


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