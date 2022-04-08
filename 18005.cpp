#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    // If the sum must be even, write 2. If the sum must be odd, write 1. If the sum could be even or could be odd, write 0.
    bool e = N / 2 % 2 == 0;
    if (N % 2) cout << 0;
    else cout << (e ? 2 : 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
