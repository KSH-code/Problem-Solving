#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, K; cin >> N >> K;
    int arr[N]; for (auto &a : arr) cin >> a;

    if (K == 1) {
        cout << (N-1)/2;
        return;
    }

    int result = 0;
    for (int i = 1; i < N - 1; i++) {
        if (arr[i] > arr[i-1] + arr[i+1]) result++;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
