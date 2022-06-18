#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, K; cin >> N >> K;
    ll arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
    int prefix[N]; memset(prefix, 0, sizeof prefix);
    int result = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] * 2 > arr[i-1]) {
            prefix[i] = prefix[i-1]+1;
        } else prefix[i]=0;
        if (K <= prefix[i]) result++;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >>N;
    while (N--) {
        solve();
        cout << '\n';
    }
    return 0;
}
