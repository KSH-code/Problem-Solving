#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    long double arr[N+1]; memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i <= j) arr[i] += 1/6.0;
            else arr[i] += (arr[i-j]+1)/6;
        }
    }
    printf("%.10Lf", arr[N]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
