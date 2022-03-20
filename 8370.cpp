#include <iostream>
using namespace std;

typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll a,b; cin >> a >> b;
    ll r=a*b;cin >> a >> b; r+= a*b;
    cout << r;
    return 0;
}
