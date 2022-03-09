#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int r = 0;
bool solve()
{
    r++;
    ll x, y, z;
    cin >> x >> y >> z;
    if (x + y + z == 0)
        return false;

    cout << "Case " << r << ": " << (z / y * x + min(z % y, x)) << '\n';

    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while (solve())
        ;
    return 0;
}