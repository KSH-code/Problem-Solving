#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    int arr[1002]; memset(arr, 0, sizeof(arr));
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr[x]++;
    }

    int b=-2;
    while(N--) {
        int x = 9999;
        for (int i = 1000; i >= 0; i--) {
            bool found = false;
            for (int j = 0; j <i;j++) found |= arr[j] > 0;
            for (int j = i+2; j <=1000;j++) found |= arr[j] > 0;
            if (arr[i] && (!arr[i+1] || found) && i!=b+1) x=i;
        }
        assert(x!=9999);
        arr[b=x]--;
        cout << x << ' ';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
