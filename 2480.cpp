#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
        cout << 10000 + 1000 * a;
    else if (a == b || b == c || a == c)
        cout << 1000 + (a == b ? a : b == c ? b
                                            : c) *
                           100;
    else
        cout << 100 * max(c, max(a, b));
    return 0;
}