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
    int N; cin >> N;
    string str; cin >> str;
    if (str.size() <= 2) {
        cout << str[0];
        return;
    }
    int pi[N]; memset(pi, 0, sizeof pi);
	for (int i = 1, j = 0; i < N; i++) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
    string pal = "";
    for (int i = N-pi[N-1]-1; i >= 0 ; i--) pal += str[i];
    bool found = true;
    for (int i = 0; i < pal.size() / 2; i++) found &= pal[i] == pal[pal.size() - i - 1];
    if (!found) pal = str[N-pi[N-1]] + pal;
    cout << pal;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    cin >>T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
