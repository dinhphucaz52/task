// https://oj.vnoi.info/problem/voi18bonus
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

const int maxn=1e6+5;
const int maxm=2e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

struct rec{
    int x,y,u,v;
}hcn[6];

int n,k,r,p;
int x,y,u,v;
int val,pre[maxm][maxm];

rec giao(rec a,rec b){
    x=max(a.x,b.x); y=max(a.y,b.y);
    u=min(a.u,b.u); v=min(a.v,b.v);
    if (u-x<0 || v-y<0)
        return {0,0,0,0};
    return {x,y,u,v};
}

int get(rec a){
    x=a.x; y=a.y; u=a.u; v=a.v;  
    if (!x || !y || !u || !v)
        return 0;
    u=min(u,n); v=min(v,n);
    return pre[u][v]-pre[x-1][v]
           -pre[u][y-1]+pre[x-1][y-1];
}


int f(rec a,rec b,rec c){
    return get(a)+get(b)+get(c)
           -get(giao(a,b))-get(giao(a,c))-get(giao(b,c))
           +get(giao(giao(a,b),c)); 
}

int g(rec a,rec b,rec c,rec d){
    return get(a)+get(b)+get(c)+get(d)
            -get(giao(a,b))-get(giao(a,c))-get(giao(a,d))
            -get(giao(b,c))-get(giao(b,d))-get(giao(c,d))
            +get(giao(giao(a,b),c))+get(giao(giao(a,b),d))
            +get(giao(giao(a,d),c))+get(giao(giao(b,d),c))
            -get(giao(giao(a,b),giao(c,d)));
}

rec giao3(rec a,rec b,rec c){
    return giao(giao(a,b),c);
}

rec giao4(rec a,rec b,rec c,rec d){
    return giao(giao3(a,b,c),d);
}

int t(rec a,rec b,rec c,rec d,rec e){
    return
    get(a)+get(b)+get(c)+get(d)+get(e)
    -get(giao(a,b))-get(giao(a,c))-get(giao(a,d))-get(giao(a,e))
    -get(giao(b,c))-get(giao(b,d))-get(giao(b,e))-get(giao(c,d))
    -get(giao(c,e))-get(giao(d,e))
    +get(giao3(a,b,c))+get(giao3(a,b,d))+get(giao3(a,b,e))+get(giao3(a,c,d))+get(giao3(a,c,e))
    +get(giao3(a,d,e))+get(giao3(b,c,d))+get(giao3(b,c,e))+get(giao3(b,d,e))+get(giao3(c,d,e))
    -get(giao4(a,b,c,d))-get(giao4(a,b,c,e))-get(giao4(a,b,d,e))-get(giao4(a,c,d,e))-get(giao4(b,c,d,e))
    +get(giao(giao4(a,b,c,d),e));
}

void solve(){
    // fileI("voi_18_bai_4.txt");
    cin>>n>>k>>r>>p; r--;
    FOR(i,1,n)
        FOR(j,1,n)
            cin>>val,
            pre[i][j]=pre[i-1][j]+pre[i][j-1]
                      -pre[i-1][j-1]+val;
    int res=0;
    while(k--){
        FOR(i,1,p)
            cin>>x>>y,hcn[i]={x,y,x+r,y+r};
        if (p==1)
            res=max(res,get(hcn[1]));
        else if (p==2)
            res=max(res,get(hcn[1])+get(hcn[2])-get(giao(hcn[1],hcn[2])));
        else if (p==3)
            res=max(res,f(hcn[1],hcn[2],hcn[3]));
        else if (p==4)
            res=max(res,g(hcn[1],hcn[2],hcn[3],hcn[4]));
        else 
            res=max(res,t(hcn[1],hcn[2],hcn[3],hcn[4],hcn[5]));
    }    
    cout<<res;
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