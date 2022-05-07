#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, M; cin >> N >> M;
    int t = N*M;
    vector<int> arr;
    arr.push_back(-180);

    int spans[3] = {18,3,3};
    int g = 0;

    vector<int> result;
    for (int i = 0; i <= N; i++) {
        while (arr.back()+spans[g%3]*60+(g==3?M:0) < (i+1) * 1440) {
            arr.push_back(arr.back()+spans[g%3]*60+(g==3?M:0));
            g%=3;

            if (1440*N <= arr.back() && 1440*(N+1) > arr.back()) {
                result.push_back(arr.back());
            }
            g++;
        }
    }

    cout << result.size() << '\n';
    for (auto r : result) {
        r %= 1440;
        printf("%02d:%02d\n", r/60, r%60);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
