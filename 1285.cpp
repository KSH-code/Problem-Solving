#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    int N; cin >> N;
    string str[N]; for (int i = 0; i < N; i++) cin >> str[i];

    int result = N*N;
    for (int i = 0; i < 1<<N; i++) {
        int tr = 0;
        string temp[N]; for (int j = 0; j < N; j++) temp[j] = str[j];

        for (int j = 0; j < N; j++) {
            if (1 << j & i) {
                for (int k = 0; k < N; k++) temp[j][k] = temp[j][k] == 'H' ? 'T' : 'H';
            }
        }

        for (int k = 0; k < N; k++) {
            int h=0,t=0;
            for (int kk = 0; kk < N; kk++) {
                if (temp[kk][k] == 'H') h++;
                else t++;
            }
            tr += min(h,t);
        }
        result = min(result, tr);
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
