#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N;cin>>N;
    ll A[N],B[N],C[N],D[N];
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    unordered_map<ll,ll> ab;
    ll result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ab[A[i] + B[j]]++;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ll s = C[i] + D[j];
            if (ab.find(s * -1) != ab.end()) result += ab[s * -1];
        }
    }
    cout << result;
    return 0;
}
