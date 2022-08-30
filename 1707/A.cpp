#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

int arr[100000];
int N, Q;
bool check(int m) {
    int q = Q;
    for (int i = m; i < N; i++) {
        if (arr[i] > q) q--;
    }
    return q < 0;
}

void solve(){
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int l = -1, r = N, m;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    for (int i = 0; i < r; i++) cout << (arr[i] <= Q);
    for (int i = r; i < N; i++) cout << 1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
