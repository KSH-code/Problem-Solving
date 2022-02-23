#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n[21]; n[0] = n[1] = 0;
    n[2] = 1;
    for (int i = 3; i<=20;i++) n[i] = (n[i-1] + n[i-2]) * (i-1);
    ll T; cin >> T;
    while (T--) {
        ll N; cin >> N;
        cout << n[N] << '\n';
    }
    return 0;
}
