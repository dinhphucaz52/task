// https://oj.vnoi.info/problem/dhbb21_easytask
#include <iostream>


using namespace std;

#define ll long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORR(i,a,b) for (int i=a;i<b;i++)
#define DOWN(i,a,b) for (int i=a;i>=b;i--)
#define DOWNN(i,a,b) for (int i=a;i>b;i--)
#define fileI(st) freopen(st,"r",stdin)
#define fileO(st) freopen(st,"w",stdout)
#define ii pair<int,int>
#define vii vector<ii>
#define len(st) st.length()
#define sz(a) a.size()
#define fi first
#define se second

const int maxn=1e6+10;
const int mod=1e9+9;

int n,val; ll sum;
bool f[maxn];
bool kt(int n){
    int i=2;
    while(i*i<=n){
        if (n%i==0)
            return false;
        i++;
    }
    return true;   
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/
    ll l=1e18,r=-1e18;
    cin>>n; 
    FOR(i,1,166667){
        if (kt(i*6-1))
            f[i*6-1]=true;
        if (kt(i*6+1))
            f[i*6+1]=true;
    }
    f[2]=f[3]=true;
    FOR(i,1,n){
        cin>>val; 
        if (f[i]==true ){
            l=min(l,sum);
            sum+=val;
            r=max(r,sum-l);
        }
        else
            sum+=val;
    }      
    cout<<r;
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
//               |   | \\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
