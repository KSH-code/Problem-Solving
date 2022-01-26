#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    ll i = 1;
    for (; i * i <= N; i++)
        continue;
    cout << i - 1;
    return 0;
}