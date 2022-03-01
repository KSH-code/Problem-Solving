#include <iostream>
using namespace std;
typedef long long ll;
ll N;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    ll l = 0, r = (ll)1e10, result = 0;
    while (l <= r)
    {
        ll count = 0;
        ll mid = (l + r) / 2;
        for (ll i = 1; i <= N; i++)
            if (mid % i)
                count += min(N, mid / i);
            else
                count += min(N, mid / i - 1);

        if (K <= count)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << r;

    return 0;
}