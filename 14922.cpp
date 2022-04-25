#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    ll arr[N]; for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    long double r = 1e11;
    int result = 0;
    for (int i = 0; i < N; i++) {
        long double s = arr[i];
        for (int j = i + 1; j < N; j++) {
            s += arr[j];
            if (s/(j-i+1) < r) {
                r=s/(j-i+1);
                result = i;
            } else break;
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
