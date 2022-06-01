#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    int N; cin >> N;
    ll arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];

    bool found = *max_element(arr, arr+N) > max(1LL,accumulate(arr, arr+N, 0LL) / 2);
    cout << (found?"Unhappy":"Happy");
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
