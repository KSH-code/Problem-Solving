#include <iostream>
using namespace std;

typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll N,M,K; cin >> N >> M >> K;
    cout << K / M << ' ' <<  K % M;
    return 0;
}
