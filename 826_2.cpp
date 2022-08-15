#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
bool comp(const pi&a,const pi&b){
    return a.first * b.second > b.first * a.second;
}
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    ll n,m; cin>>n>>m;
    vector<pi>v;
    for(int i=1; i<=n; i++){
        int a,b; cin>>a>>b;
        v.emplace_back(pi(a,b));
    }
    sort(v.begin(),v.end(),comp);
    ll ans = 0;
    ll down = 1;
    ll up = 0;
    while(v.size() && m){
        pi p = v.back(); v.pop_back();
        if(p.first<m){
            m-=p.first;
            ans+=p.second;
            up = ans;
        }
        else{
            up = p.second * m + ans * p.first;
            down = p.first;
            ll g = gcd(up,down);
            up/=g;
            down/=g;
            break;
        }
    }
    cout<<up<<"/"<<down;
    return 0;
}
