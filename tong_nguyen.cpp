// http://ntucoder.net/Problem/Details/5637
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

vii res;
int n;

void check(int k,int n){
	n*=2;
	if (n%k!=0)
		return;
	n/=k;
	//l+r=n
	//r-l+1=k
	if ((n+k-1)%2==1)
		return;
	int r=(n+k-1)/2;
	int l=r-k+1;

	res.push_back({l,r});	
}

void solve(){
	cin>>n;
	int tmp=sqrt(n*2);
	FOR(i,2,tmp)
		if (n*2%i==0)
			check(i,n);
	cout<<sz(res)<<endl;
	for(ii x:res)
		cout<<x.X<<" "<<x.Y<<endl;
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