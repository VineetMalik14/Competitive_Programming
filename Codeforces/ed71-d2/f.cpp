#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef long double ld;
#define mod         ll(1000000007)
#define mod1        ll(998244353)
#define mox         ll(500001)
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
#define dbg(x)      cout << #x << " = " << x << '\n';
#define deci_pre(n)     cout<<fixed<<setprecision(n);


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


    vll a(mox);
    ll sq=sqrt(mox);
    vector< vll > tot(sq, vll(sq));
    ll q; cin>>q;
    while(q--){
        ll ty, x, y; cin>>ty>>x>>y;
        if(ty==1){
            a[x]+=y;
            fol(i,1,sq){
                tot[i][x%i]+=y;
            }
        }
        else{
            ll r=0;
            if(x>=sq){
                ll i=y;
                while(i<=mox){
                    r+=a[i];
                    i+=x;
                }
            }
            else{
                r=tot[x][y];
            }
            cout<<r<<nn;
        }
    }
	return 0;
}