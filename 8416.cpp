#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a,b; cin >> a>>b;
    assert(a>=1 && b>=1);
    a%=10;
    b=b%4?b%4:4;
    a=pow(a,b);
    cout << a%10;
}

int main()
{
    solve();
    return 0;
}
