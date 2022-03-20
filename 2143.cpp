#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll K; int N; cin >> K >> N;
    ll A[N]; for (int i = 0; i < N; i++) cin >> A[i];
    map<ll, int> count;
    for (int i = 0; i < N; i++) {
        ll sum = 0;
        for (int j = i; j < N; j++) {
            count[sum += A[j]]++;
        }
    }

    int M; cin >> M; ll B[M]; for (int i = 0; i < M; i++) cin >> B[i];

    ll result = 0;
    for (int i = 0; i < M; i++) {
        ll sum = 0;
        for (int j = i; j < M; j++) {
            sum += B[j];
            if (count.find(K - sum) != count.end()) result += count[K - sum];
        }
    }

    cout << result;

    return 0;
}
