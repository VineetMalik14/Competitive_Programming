#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define mk make_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll binarySearch(vll a, ll l, ll r, ll x){
	ll mid;
	while(l<=r){
        	mid=l+(r-l)/2;
		if(a[mid]==x)		return mid;
		else if(a[mid]<x)	l=mid+1;
		else			r=mid-1;
	}
	return -1;
}
ll pw(ll x, ll y){ 
    	if(y==0)		return 1; 
    	else if(y%2==0) 	return pw(x,y/2)*pw(x,y/2); 
    	else			return x*pw(x,y/2)*pw(x,y/2); 
}


int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector< pair<ll,ll> > v;
	set < pair<ll,ll> > s;
	fol(i,0,3){
		ll x, y; cin>>x>>y;
		v.pb(mk(x,y));
	}
	sort(v.begin(), v.end());
	fol(i,v[0].ff,v[1].ff+1){
		s.insert(mk(i,v[0].ss));
	}
	fol(i, min(v[0].ss,v[1].ss), max(v[0].ss,v[1].ss)+1){
		s.insert(mk(v[1].ff,i));
	}
	fol(i,v[1].ff,v[2].ff+1){
		s.insert(mk(i,v[2].ss));
	}
	fol(i, min(v[1].ss,v[2].ss), max(v[1].ss,v[2].ss)+1){
		s.insert(mk(v[1].ff,i));
	}
	cout<<s.size()<<endl;
	set < pair <ll,ll> >  :: iterator it;
	for(it=s.begin(); it!=s.end(); it++){
		cout<<(*it).ff<<" "<<(*it).ss<<endl;
	}
	return 0;
}