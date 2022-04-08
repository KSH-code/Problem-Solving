#include <iostream>
using namespace std;
bool solve(){
    int N;cin>>N;
    if (!N) return false;

    int s = 0;
    for (int i = 1; i < N; i++) {
        if (N%i==0) s += i;
    }
// 15 DEFICIENT
// 28 PERFECT
// 6 PERFECT
// 56 ABUNDANT
// 60000 ABUNDANT
// 22 DEFICIENT
// 496 PERFECT
    cout << N << ' ';
    if (s == N) cout << "PERFECT";
    else if (s < N) cout << "DEFICIENT";
    else cout << "ABUNDANT";

    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while(solve()) cout << '\n';
    return 0;
}
