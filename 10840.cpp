#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

const ll m=1001;

typedef pair<ll,ll> pll;

ll pow(ll b) {
    if (!b) return 1;

    ll t = 1;
    if (b & 1) t *= m;

    auto z = pow(b/2);
    return t*z*z;
}

void solve(){
    string A, B; cin >> A >> B;

    vector<ll> v;
    for (int i = 0; i < A.size(); i++) {
        ll f = 0;
        for (int j = i; j < A.size(); j++) {
            f += pow(A[j]-'a');
            v.push_back(f);
        }
    }

    sort(v.begin(), v.end());

    int result = 0;
    for (int i = 0; i < B.size(); i++) {
        ll f = 0;
        for (int j = i; j < B.size(); j++) {
            f += pow(B[j]-'a');
            if (binary_search(v.begin(), v.end(), f)) {
                result = max(result, j-i+1);
            }
        }
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
