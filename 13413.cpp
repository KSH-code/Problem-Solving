#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    string A; cin >> A;
    string B; cin >> B;

    int count = 0;
    int ab = 0, aw = 0;
    int bb = 0, bw = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == B[i]) continue;

        if (A[i] == 'B') ab++;
        else aw++;

        if (B[i] == 'B') bb++;
        else bw++;
    }

    while (ab && aw && bw && bb) {
        aw--;ab--;
        bw--;bb--;
        count++;
    }
    cout << count + (ab+aw);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
    return 0;
}
