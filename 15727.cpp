#include <iostream>
using namespace std;

typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll a; cin >> a;
    cout << a/5 + (a % 5 > 0);
    return 0;
}
