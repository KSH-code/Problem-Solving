#include <iostream>
using namespace std;

void solve(){
    int N, K; cin >> N >> K;
    int result = N;
    for (int i = 1; i <= N; i++) {
        int t= i;
        for (int j = 2; j<=K; j++) {
            if (t % j) continue;
            while (t%j==0) t/=j;
        }
        if (t > K) result--;
    }
    cout << result;
}

int main()
{cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
