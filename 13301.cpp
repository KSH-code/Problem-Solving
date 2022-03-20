#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // a -> b 01
    // b -> ba 11
    // ba -> bab 12
    // bab -> babba 23
    int N; cin >> N;
    pair<int,int> fibo[N + 10];
    fibo[1] = {0,1};
    fibo[2] = {1,1};
    for (int i = 3; i <= N; i++) fibo[i] = {fibo[i-2].first+fibo[i-1].first, fibo[i-2].second+fibo[i-1].second};

    cout << fibo[N].first << ' ' << fibo[N].second;
    return 0;
}
