#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    int arr[1001];
    for (int i = 0; i <= 1000; i++) arr[i] = 0;

    int max_height = 0;
    int max_index = 0;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        arr[a]=b;
        if (max_height < b) {
            max_height = b;
            max_index = a;
        }
    }

    stack<pair<int,int>> st;
    for (int i = 1; i < max_index; i++) {
        if (!arr[i]) continue;
        int height=arr[i];

        if (st.empty() || st.top().second < height) st.push({i, height});
    }

    int result = max_height;
    int r = max_index;
    while (st.size()) {
        auto [x,y] = st.top(); st.pop();
        result += (r-x)*y;
        r = x;
    }

    st.push({max_index, max_height});
    for (int i = max_index+1; i <= 1000; i++) {
        if (!arr[i]) continue;
        int height = arr[i];
        while (st.size() && st.top().second < height) st.pop();
        st.push({i, height});
    }

    auto [x,y] = st.top(); st.pop();
    while (st.size()) {
        auto [ax,ay] = st.top(); st.pop();
        result += (x-ax)*y;
        x=ax;y=ay;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
