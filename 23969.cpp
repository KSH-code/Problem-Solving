#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, K; cin >> N >> K;
    int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = N-1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                K--;
                if (K==0) {
                    for (int k = 0; k < N; k++) cout << arr[k] << ' ';
                    return;
                }
            }
        }
    }
    cout << -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
