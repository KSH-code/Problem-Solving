#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    // If the sum must be even, output 'Even'.  If the sum must be odd, output 'Odd'.  If the sum could be even or could be odd, output 'Either'.
    bool e = N / 2 % 2 == 0;
    if (N % 2) cout << "Either";
    else cout << (e ? "Even" : "Odd");
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
