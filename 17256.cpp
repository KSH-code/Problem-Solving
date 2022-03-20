#include <iostream>
using namespace std;

typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll a,b,c; cin >> a >> b>>c;
    ll d,e,f; cin >> d >> e>>f;
    // (a.z + b.x, a.y × b.y, a.x + b.z)
    cout << d-c  << ' ' << e/b << ' ' << f-a;
    return 0;
}
