#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(200005)
#define inf ll(1e18)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define vll vector<ll>
#define mk make_pair
#define pb push_back
#define po pop_back
#define ff first
#define ss second
#define bb begin()
#define ee end()


ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return r*r; 
    	else		return x*r*r; 
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	vll a(n);
	map <ll,ll> mp;
	fol(i,0,n){
		cin>>a[i];
		mp[a[i]]=i+1;
	}
	sort(a.bb, a.ee);
	if(a.size()==2){
		cout<<mp[a[0]]<<"\n";
		return 0;
	}
	ll ok=1;
	ll d1=a[2]-a[1];
	fol(i,3,n){
		if(a[i]-a[i-1]!=d1){
			ok=0;
			break;
		}
	}
	if(ok){
		cout<<mp[a[0]]<<"\n";
		return 0;
	}
	ok=1;
	d1=a[2]-a[0];
	fol(i,3,n){
		if(a[i]-a[i-1]!=d1){
			ok=0;
			break;
		}
	}
	if(ok){
		cout<<mp[a[1]]<<"\n";
		return 0;
	}
	ok=1;
	d1=a[1]-a[0];
	ll pos=-mod;
	fol(i,2,n){
		if(a[i]-a[i-1]!=d1){
			if(pos==-mod){
				pos=a[i];
				a[i]=a[i-1];
			}
			else{
				pos=mod;
			}
		}
	}
	if(pos==-mod){
		cout<<mp[a[n-1]]<<"\n";
		return 0;
	}
	if(pos==mod){
		cout<<-1<<"\n";
	}
	else{
		cout<<mp[pos]<<"\n";
	}
	
	return 0;
}