#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, M; cin >> N >> M;
    ll data[N]; for (int i = 0; i < N; i++) cin >> data[i];
    ll customers[M]; for (int i = 0; i < M; i++) cin >> customers[i];

    sort(data, data+N);
    sort(customers, customers+M);

    ll result = 0;
    int product = N-1;
    for (int i = 0; i < M; i++) {
        if (product < 0) break;
        if (customers[i] >= data[product]) break;
        result += data[product--] - customers[i];
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
