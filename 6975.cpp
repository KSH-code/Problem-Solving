#include <iostream>
using namespace std;
bool solve(){
    int N;cin>>N;
    if (!N) return false;

    int s = 0;
    for (int i = 1; i < N; i++) {
        if (N%i==0) s += i;
    }

//     4 is a deficient number.

// 6 is a perfect number.

// 12 is an abundant number.
    cout << N << " is";
    if (s == N) cout << " a perfect number.";
    else if (s < N) cout << " a deficient number.";
    else cout << " an abundant number.";

    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        solve();
        cout << "\n\n";
    }
    return 0;
}
