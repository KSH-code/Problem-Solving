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
    int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
    int me = *min_element(arr, arr + N); for (int i = 0; i < N; i++) me = gcd(me, arr[i]);
    set<int> s;
    for (int i = 1; i * i <= me; i++) {
        if (me % i == 0) s.insert(i), s.insert(me / i);
    }
    for (auto r : s) cout << r << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    solve();
    return 0;
}
