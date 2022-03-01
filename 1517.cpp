#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int tree[500000 * 4];

void update(int start, int end, int node, int index)
{
    if (start > index || index > end)
        return;
    tree[node]++;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index);
    update(mid + 1, end, node * 2 + 1, index);
}

ll query(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;
    pair<int, int> arr[N];
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        arr[i] = {t, i};
    }

    sort(arr, arr + N);

    ll result = 0;
    for (int i = 0; i < N; i++)
    {
        int index = arr[i].second;
        update(0, N - 1, 1, index);
        result += query(0, N - 1, 1, index + 1, N - 1);
    }
    cout << result;

    return 0;
}