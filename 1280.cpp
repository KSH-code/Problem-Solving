#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 2e5;

using pii = pair<ll,ll>;

pii tree[MAX*4];

pii query(int s, int e, int node, int l, int r) {
    if (l > e || s > r) return {0,0};
    if (l <= s && e <= r) return tree[node];
    int m = (s+e)/2;
    auto [a,b] = query(s,m,node*2,l,r);
    auto [c,d] = query(m+1,e,node*2+1,l,r);
    return {a+c, b+d};
}

void update(int s, int e, int node, int index) {
    if (index > e || index < s) return;
    if (s == e) {
        auto &[a,b] = tree[node];
        a+=index;b++;
        return;
    }

    int m = (s+e)/2;
    update(s,m,node*2,index);
    update(m+1,e,node*2+1,index);


    auto [a,b] = tree[node*2];
    auto [c,d] = tree[node*2+1];
    tree[node] = {a+c, b+d};
}

const ll mod = 1e9+7;

void solve(){
    int N; cin >> N;
    int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
    ll result = 1;
    update(0,MAX,1,arr[0]);
    for (int i = 1; i < N; i++) {
        auto [a,b] = query(0,MAX,1,0,arr[i]-1);
        auto [c,d] = query(0,MAX,1,arr[i]+1,MAX);
        ll cur = (arr[i]*b-a + -arr[i]*d+c)%mod;
        result = (result * cur) % mod;
        update(0,MAX,1,arr[i]);
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
