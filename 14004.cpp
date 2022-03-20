#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    cout << (C + D) / (A - B);
    return 0;
}
