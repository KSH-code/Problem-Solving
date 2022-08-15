#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const ll mod = 1e9+7;

ll f(ll n) {
    ll f=1;
    if(n<=1)
        return 1;

    for(ll i=2; i<=n; i++)
        f*=i;
    return f;
}



ll solution(ll n) {
    return f(2*n) / f(n) / f(n+1);
}

void solve(){
    string str; cin >> str;
    ll check = 0;
    ll fuck = 0;
    ll pr = 0;
    ll result = 1;
    stack<int> st;
    for (auto c : str) {
        if (c >= 'a' && c <= 'z') continue;
        if (c == '?') {
            st.push(1);
            result = (result + (sol)) % mod;
            pr++;
        } else {
            st.pop();
        }
    }
    cout << result;
}

int main()
{
    solve();
    return 0;
}
