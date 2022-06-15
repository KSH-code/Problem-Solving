#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N;cin>>N;
    string A,B; cin >>A>>B;
    int a=0,b=0,c=0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 'a') a=max(a,i);
        else if (A[i] == 'a') b=max(b,i);
        else if (A[i] == 'c') c=max(c,i);

        if (A[i]==B[i]) continue;

        if (B[i]== 'b' && A[i] == 'a') {
            int j = max(i+1, a);
            while (j < N && A[j] == 'a') j++;
            a = j;
            if (j < N && A[j] == 'b') swap(A[i], A[j]);
        } else if (B[i]== 'c' && A[i] == 'b') {
            int j = max(i+1, b);
            while (j < N && A[j] == 'b') j++;
            b = j;
            if (j < N && A[j] == 'c') swap(A[i], A[j]);
        }
    }

    cout << (A==B?"YES":"NO");
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
