#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve(){
    int N, M, L; cin >> N >> M >> L;
    int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr,arr+N);
    int l = 0, r = L+1;
    while(l+1<r)  {
        int mid = (l+r)/2;
        int prev = 0;
        int count = 0;
        for (int i = 0; i < N; i++) {
            count += (arr[i] - prev - 1) / mid;
            prev = arr[i];
        }
        count += (L-prev-1) / mid;
        if (count <= M) r = mid;
        else l = mid;
    }
    cout << r;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
