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
    int N,M;cin>>N>>M;
    string result;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 26; j++) {
            int remain = N-i;
            if (remain <= M-j && M-j <= remain*26) {
                result += 'A'+j-1;
                M-=j;
                break;
            }
        }
    }

    if (result.size() != N) result = "!";

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
