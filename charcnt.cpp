// https://oj.vnoi.info/problem/fc133_charcnt
#include <iostream>
#include <map>

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
#define mci map<char,int> 

const int maxn=5e5+5;
const int maxm=1e3+5;
const int mod=1e9+7;

int n,q;
string a;
int st[4*maxn][30];


void build(int id,int l,int r){
    if (l==r)
        return st[id][a[l]-'a']++,void();
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    FOR(i,0,25)
        st[id][i]=st[id*2][i]+st[id*2+1][i];
}

void update(int id,int l,int r,int x,char val){
    if (x<l || x>r)
        return;
    if (l==r){
        st[id][a[x]-'a']--;
        st[id][val-'a']++;
        return;
    }
    int mid=(l+r)>>1;
    update(id*2,l,mid,x,val);
    update(id*2+1,mid+1,r,x,val);
    FOR(i,0,25)
        st[id][i]=st[id*2][i]+st[id*2+1][i];
}
bool check[30];

void query(int id,int l,int r,int u,int v){
    if (l>v || r<u)
        return;
    if (u<=l && r<=v){
        FOR(i,0,25)
            if (st[id][i]!=0)
                check[i]=true;
        return;
    }
    int mid=(l+r)>>1;
    query(id*2,l,mid,u,v);
    query(id*2+1,mid+1,r,u,v);
}
int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/
    // fileI("charcnt.inp");
    cin>>n>>a;
    a=' '+a;
    build(1,1,n);
    cin>>q;
    int type,u,v,x;
    char val;
    while(q--){
        cin>>type;
        if (type==1){
            cin>>x>>val;
            update(1,1,n,x,val);
            a[x]=val;
        }
        else{
            cin>>u>>v;
            int cnt=0;
            FOR(i,0,25)
                check[i]=false;
            query(1,1,n,u,v);
            FOR(i,0,25)
                if (check[i])
                    cnt++;
            cout<<cnt<<endl;
        }
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