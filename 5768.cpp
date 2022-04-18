#include <iostream>
using namespace std;

bool solve(){
    int N, M; cin >> N >> M;
    if (N+M==0) return false;

    int divisors = 0;
    int result = 0;
    for (int i = N; i <= M; i++) {
        int t=0;
        for (int j = 1; j * j <= i; j++) {
            if (i%j==0) t+=2;
            if (j*j==i) t--;
        }
        if (divisors <= t) {
            divisors = t;
            result = i;
        }
    }

    cout << result << ' ' << divisors;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while(solve()) cout <<'\n';
    return 0;
}
