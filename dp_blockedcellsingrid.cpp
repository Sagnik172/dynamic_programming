#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(long long i=a;i<=b;i++)
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define N 50005


void solve()
{
ll n,m,k;
cin>>n>>m>>k;

set<pair<ll,ll>> v;
f(i,0,k-1)
{ll a,b;
   cin>>a>>b;
  v.emplace(a,b);

}

vector<vector<ll>> dp(2,vector<ll> (m+1,0));

// f(x,0,k-1)
//       {
         
//             ll a=v[x][0];
//             ll b=v[x][1];
               
//                dp[a][b]=-1;
               
//                }
 dp[1][m]=1;
//  for(ll i=n-1;i>=1;i--)
// {
//  for(ll j=m-1;j>=1;j--)
//  {
//      if(dp[i][j]==-1)
//          dp[i][j]=0;
        
//  }
// }
 for(ll i=m-1;i>=1;i--)
 {pair<ll,ll> p(n,i);
        if(v.find(p)!=v.end())
            dp[1][i]=0;
        else
            dp[1][i]=(dp[1][i+1])%MOD;

 }
         
    ll flag=0;       
for(ll i=n-1;i>=1;i--)
{pair<ll,ll> p(i,m);
        if(v.find(p)!=v.end())
            dp[flag][m]=0;
        else
            dp[flag][m]=dp[1-flag][m];
    for(ll j=m-1;j>=1;j--)
    {pair<ll,ll> p(i,j);
        if(v.find(p)!=v.end())
            dp[flag][j]=0;
        else
        dp[flag][j]=(dp[flag][j+1]%MOD +dp[1-flag][j]%MOD)%MOD;

    
    }
    flag=1-flag;
    
}
pair<ll,ll> p(n,m);
if(v.find(p)!=v.end())
cout<<0;
else

 cout<<dp[1-flag][1];
cout<<nline;


}
 
int main() {
#ifndef ONLINE_JUDGE
   freopen("Error.txt", "w", stderr);
#endif
   fastio();
   ll t;
   cin>>t;
   while(t--)
   
     solve();
   
return 0;
  
 
    
}