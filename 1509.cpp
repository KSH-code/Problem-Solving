#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

string str;
int pal[2555][2555];

int dfs(int s, int e){
    if (s > e) return 1;

    if (pal[s][e]) return pal[s][e];
    if (str[s]==str[e]) return pal[s][e] = dfs(s+1, e-1);
    return pal[s][e] = -1;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin >> str; str = '#' + str;
    int N = str.size();
    int dp2[N]; dp2[0] = 0;
    for (int i = 1; i < N; i++) {
        dp2[i] = dp2[i-1] + 1;

        for (int j = 1; j < i; j++) {
            if (dfs(j, i) == 1) dp2[i] = min(dp2[j - 1] + 1, dp2[i]);
        }
    }
    cout << dp2[N - 1];
    return 0;
}
