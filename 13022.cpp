#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


void solve(){
    string str; cin >> str;
    bool found = 1;
    for (int i = 0; i < str.size(); i++) {
        int c = 1;
        while (i + c < str.size() && str[i + c] == 'w') c++;
        for (int j = 0; j < c; j++) found &= i + c + j < str.size() && str[i + c + j] == 'o';
        for (int j = 0; j < c; j++) found &= i + c * 2 + j < str.size() && str[i + c * 2 + j] == 'l';
        for (int j = 0; j < c; j++) found &= i + c * 3 + j < str.size() && str[i + c * 3 + j] == 'f';
        i = i + c * 4 - 1;
    }
    cout << found;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
