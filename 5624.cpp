#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

void solve(){
    int N; cin >> N;
    int arr[N]; for (auto &a : arr) cin >> a;
    set<int> s[2];
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) if(s[1].count(arr[i]-arr[j])) {
            result++;
            break;
        }
        s[0].insert(arr[i]);
        for (auto a : s[0]) s[1].insert(a+arr[i]);
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
