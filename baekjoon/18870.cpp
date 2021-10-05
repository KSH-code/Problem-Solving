#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  int arr[N];
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);

  vector<int> unique_sorted(arr, arr + N);
  sort(unique_sorted.begin(), unique_sorted.end());
  unique_sorted.erase(unique(unique_sorted.begin(), unique_sorted.end()), unique_sorted.end());

  for (int i = 0; i < N; i++)
  {
    int lower_size;
    lower_size = upper_bound(unique_sorted.begin(), unique_sorted.end(), arr[i]) - unique_sorted.begin() - 1;
    printf("%d ", lower_size);
  }
  return 0;
}
