#include <iostream>
using namespace std;
typedef long long ll;

void solve(){
    ll N; cin >> N;
    ll a = 1, b = 0, count=0;
    while (N > a && N > b) {
        for (ll i = 1<<10; i >= 1; i/=2) {
            while (a >= i && b+i*2<=N) {
                b+=i*2;
                count+=i;
                a-=i;
            }
        }
        if (b < N) {
            ll c = min(N-b,a);
            a-=c;
            count+=c;
            b+=c;
        }
        if (!a) a=b,b=0;
    }
    cout << count;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
