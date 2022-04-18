#include <iostream>
#include <memory.h>

using namespace std;

void solve(){
    int N; cin >> N;
    int count = 0;
    bool prime[N+1]; memset(prime, true, sizeof(prime));
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) continue;
        for (int j = i+i; j<= N; j+=i) prime[j]=false;
        if (i == 2 || i == 5) continue;

        int s = 1;
        for (int j = 0; j < i/2-1; j++) {
            s = (s*100+1)%i;
            if (s == 0 && j != i/2-2) {
                s = -1;
                break;
            }
        }
        if (s==0) count++;
    }
    cout << count;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
