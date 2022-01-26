#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    ll A, B;
    cin >> A >> B;
    if (A == B)
    {
        cout << 0;
        return 0;
    }
    ll MAX = max(A, B);
    ll MIN = min(A, B);
    cout << MAX - MIN - 1 << "\n";
    while (MIN < MAX - 1)
    {
        cout << ++MIN << " ";
    }
    return 0;
}