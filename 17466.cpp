#include <iostream>
using namespace std;

typedef long long ll;
void solve(){
    ll a,b; cin >> a>>b;
    ll z= 1;
    for (ll i = 2;i<=a;i++){
        z*=i;
        z%=b;
    }
    cout << z;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
