#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long   ll;
typedef long double ld;
#define mod         ll(1000000007)
#define mod1        ll(998244353)
#define mox         ll(200005)
#define inf         ll(1e18)
#define fol(i,a,b)  for(ll i=a; i<b; i++)
#define vll         vector<ll>
#define pll         pair<ll,ll>
#define mk          make_pair
#define pb          push_back
#define po          pop_back
#define ff          first
#define ss          second
#define bb          begin()
#define ee          end()
#define nn          '\n'
#define dbg(x)      cout << #x << " = " << x << '\n'
#define deci_pre(n) cout<<fixed<<setprecision(n)

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll grand(ll x) { // [0, x-1]
    return uniform_int_distribution<ll>(0, x-1)(rng);
}

ll gcd(ll a, ll b){
    ll mi=min(a, b), mx=max(a, b);
    while(mi!=0){
        ll temp=mi;
        mi=mx%mi;
        mx=temp;
    }
    return mx;
}

ll pw(ll x, ll n){
    if(x==0){
        return 0;
    }
    ll ans=1;
    while(n!=0){
        if(n&1ll){
            ans*=x;
        }
        x*=x;
        n>>=1ll;
    }
    return ans;
}


int main()
{
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
    set<ll> sty;
    map<ll, ll> mpx;
    map<ll, set<ll> > mpy;
    oset stx;
	fol(i,0,n){
		ll x, y; cin>>x>>y;
		mpx[x]++;
        mpy[y].insert(x);
		stx.insert(x);
        sty.insert(y);
	}
    ll sz=mpx.size();
    ll ans=(sz*(sz+1))/2;
    for(auto i : sty){
        set<ll> cl;
        ll pre=0;
        for(auto j : mpy[i]){
            mpx[j]--;
            if(mpx[j]==0){
                cl.insert(j);
            }
            ll k=stx.order_of_key(j);
            k-=pre;
            ans-=(k*(k+1))/2;
            pre+=k+1;
        }
        pre=stx.size()-pre;
        ans-=(pre*(pre+1))/2;
        for(auto j : cl){
            stx.erase(j);
            mpx.erase(j);
        }
        sz=mpx.size();
        ans+=(sz*(sz+1))/2;
    }
    cout<<ans<<nn;
	return 0;
}