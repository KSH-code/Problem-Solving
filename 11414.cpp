#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

void solve()
{
    ll a,b;cin>>a>>b;
    set<ll> as;
    for (ll i = 2; i <= a; ++i)
    {
        if(a%i==0)
        {
            as.insert(i);
            while(a%i==0)a/=i;
        }
    }
    for (ll i = 2; i <= b; ++i)
    {
        if(b%i==0)
        {
            as.insert(i);
            while(b%i==0)b/=i;
        }
    }
    ll r = 1;
    for (ll c : as) r*=c;
    cout << r;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
