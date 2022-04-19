#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N,PD,PG; cin >> N >> PD >> PG;
    if ((PG && !PD) || (PG != 100 && PD == 100)) {
        cout << "Broken";
        return;
    }
    if (!PG) {
        cout << "Possible";
        return;
    }
    for (int G = 1; G<= 1000; G++) {
        for (int won = 0; won <= G; won++) {
            if (10000/G*won==PG*100) {
                if (G*PD/100==G-N) {
                    cout << "Possible";
                    return;
                }
            }
        }
    }
    cout << "Broken";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    for (int i = 1; i <= T;i++) {
        cout << "Case #"<<T<<": ";
        solve();
        cout << '\n';
    }
    return 0;
}
