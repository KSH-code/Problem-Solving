#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    int arr[N];
    for (int i = 1; i < N; i++) {
        cout << "? " << i << ' ' <<  i + 1 << '\n';
        fflush(stdout);
        cin >> arr[i-1];
    }
    cout << "? " << 1 << ' ' <<  3 << '\n';
    fflush(stdout);
    cin >> arr[N-1];

    int a = arr[0] - arr[1] + arr[N-1];
    a/=2;
    cout << "! " << a << ' ';
    for (int i = 1; i < N; i++) {
        a = arr[i - 1] - a;
        cout << a << ' ';
    }
    cout << '\n';
    fflush(stdout);
}

int main()
{
    solve();
    return 0;
}
