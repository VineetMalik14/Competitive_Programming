#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll n; cin>>n;
        ll s; cin>>s;
        vll a(n);
        fol(i,0,n){
                cin>>a[i];
        }
        ll ans=0;
        sort(a.begin(), a.end());
        fol(i,0,n){
                if(i>n/2){
                        if(a[i]<s)
                        ans+=s-a[i];
                }
                else if(i==n/2){
                        ans+=abs(a[i]-s);
                }
                else{
                        if(a[i]>s){
                                ans+=a[i]-s;
                        }
                }
        }
        cout<<ans<<endl;
    	return 0;
}