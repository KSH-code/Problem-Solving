#include <iostream>
#include <algorithm>

using namespace std;

void solve(){
    int N; cin >> N;int count=0;
    for (int i = 3; i <=N; i++) {
        if (i%2==0 || i%5==0) continue;

    }cout <<N-2;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
