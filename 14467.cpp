#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    int arr[11]; for (int i = 1; i <= 10; i++) arr[i] = 2;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int a,b;
        cin >> a>>b;
        if (arr[a] == 2) arr[a] = b;
        else if (arr[a] != b) {
            count++;
            arr[a]=b;
        }
    }
    cout << count;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
