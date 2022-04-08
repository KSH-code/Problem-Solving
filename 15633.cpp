#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int N; cin >> N;
    ll result = 1;
    for (int i = 2; i <= N; i++) {
        if(N%i==0) result += i;
    }
    cout << result * 5 - 24;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    solve();
    return 0;
}
