#include <iostream>

using namespace std;
typedef long long ll;
void solve(){
    ll N; cin >> N;
    ll l = 1, r = 1e9+1;
    while (l+1 < r){
        ll m = (l+r)/2;
        if (m*m<=N) l = m;
        else r = m;
    }
    cout << (l*l==N);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N; while(N--) {
        solve(); cout << ' ';
    }
    return 0;
}
