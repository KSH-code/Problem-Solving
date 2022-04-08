#include <iostream>
using namespace std;

void solve(){
    int N; cin >> N;
    for (int i = 2; i <= N; i++) {
        if (N%i) {
            cout << i << ' ';
            break;
        }
    }
    for (int i = N; i >= 0; i--) {
        if (N%i) {
            cout << i << ' ';
            break;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
