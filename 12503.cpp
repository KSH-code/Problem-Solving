#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, PD,PG; cin >> N >> PD >> PG;
    if (PD && !PG) {
        cout << "Broken";
        return;
    }
    if (PD != 100 && PG==100) {
        cout << "Broken";
        return;
    }

    for (int D = 1; D<=N; D++) {
        if ((PD*D)%100==0){
            cout << "Possible";
            return;
        }
    }

    cout << "Broken";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    for (int i = 1; i <= T;i++) {
        cout << "Case #"<<i<<": ";
        solve();
        cout << '\n';
    }
    return 0;
}
