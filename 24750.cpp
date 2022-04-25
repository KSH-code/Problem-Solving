#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    int Me = 0;
    int Ve = 0;
    int trucks = 0;
    int boats = 0;
    while (Ve<C) {
        while (Me<B) {
            Me += A;
            trucks++;
        }
        Ve+=B;
        Me-=B;
        boats++;
    }
    if (Me<D) {
        Me+=A;
        trucks++;
    }
    if (Me==D) {
        cout << "We need";
        if (trucks == 1) cout << " 1 truck";
        else cout << " "<<trucks<<" trucks";

        if (boats == 1) cout << " and 1 boat.";
        else cout << "and "<<boats<<" boats.";
    } else {
        cout << "No solution.";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
