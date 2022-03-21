#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    ll N, M; cin >> N >> M;
    ll arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];

    ll result = 0;
    for (int i = 1; i < (1 << N); i++)
    {
        int bc = 0;
        ll mul = 1;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                mul *= arr[j];
                bc++;
            }
        }
        if (bc & 1) {
            result += M / mul;
        } else {
            result -= M / mul;
        }
    }

    cout << result;
    return 0;
}
