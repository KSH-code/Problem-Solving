#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const ll mod = 1e9;

const int MAX = 1e7;
map<ll, ll> dp;
ll fibo(ll n) {
    if (n == 1 || n == 2) return 1;
    if (dp.count(n)) return dp[n];
    ll result =0;
    if (n % 2) {
        ll k = (n+1)/2;
        ll c = fibo(k);
        ll d = fibo(k-1);
        result= (c* c + d*d)%mod;
    } else {
        ll k = n/2;
        ll c = fibo(k);
        ll d = fibo(k-1);
        result= ((2*d + c)*c)%mod;
    }
    return dp[n]=result;
}

void solve(){
    ll a,b; cin >> a>> b;
    cout << (fibo(b+2)+mod-fibo(a+1))%mod;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
