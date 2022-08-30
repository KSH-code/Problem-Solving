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
    // 2019년 1월 1일은 화요일이다.
    // 2월이 29일까지 존재하는 해를 윤년이라고 한다.
    // 일반적으로 1월부터 12월은 각각 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31일까지 있다. 윤년인 해에는, 2월이 28일까지가 아닌 29일까지 있다.
    // 400의 배수 연도는 윤년이다.
    // 400의 배수가 아니면서 100의 배수인 연도는 윤년이 아니다.
    // 100의 배수가 아니면서 4의 배수인 연도는 윤년이다.
    // 그 외의 연도는 윤년이 아니다.
    int N; cin >> N;
    int d = 1;
    int result = 0;
    for (int i = 2019; i <= N; i++) {
        int f[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int j = 1; j <= 12; j++) {
            if ((d + 12) % 7 == 4) result++;
            d += f[j-1];
            if ((i % 400 == 0 || i % 100) && i % 4 == 0) {
                if (j == 2) d++;
            }
            d %= 7;
        }
    }
    cout << result;
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
