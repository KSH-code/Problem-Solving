#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    ll N, K, M;
    cin >> N >> K >> M;
    ll arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    ll l = 1;
    ll r = 1e9;

    ll result = -1;
    while (l < r)
    {
        ll m = (l + r) / 2;

        ll cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] <= K)
                continue;
            ll remains = arr[i] < 2 * K ? arr[i] - K : arr[i] - 2 * K;

            cnt += remains / m;
        }

        if (cnt >= M)
            l = m + 1;
        else
            r = m;

        if (cnt >= M)
            result = max(result, m);
    }
    cout << result;
    return 0;
}