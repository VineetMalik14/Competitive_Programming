#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define for(i,a,b) for(ll i=a; i<b; i++)
#define mk mkae_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll n, k; cin>>n>>k;
        string t; cin>>t;
        ll pos=n;
        for(i,1,n){
                if(t.substr(i,n-i)==t.substr(0,n-i)){
                        pos=i;
                        break;
                }
        }
        cout<<t;
        for(i,1,k){
                cout<<t.substr(n-pos,pos);
        }
    	return 0;
}