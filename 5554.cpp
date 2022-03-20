#include <iostream>
using namespace std;

typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int a, b, c, d; cin >> a >> b >> c >> d;
    a += b + c + d;
    cout << a / 60 << '\n' << a % 60;
    return 0;
}
