#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
     long double x=0, y=0;
     long double a=0, b=0;
     for (int i = 0; i < 2; i++) {
         cin >> a >> b; x += (a+b)/2;
     }
     for (int i = 0; i < 2; i++) {
         cin >> a >> b; y += (a+b)/2;
     }

    cout << (x > y ? "Gunnar" : x<y ? "Emma" : "Tie");
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
