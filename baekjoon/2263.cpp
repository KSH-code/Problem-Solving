#include <iostream>

using namespace std;

#define MAX 100001
int in_order[MAX], post_order[MAX], indices[MAX];

void traverse(int l, int r, int ll, int rr)
{
  if (l > r || ll > rr)
    return;

  int result = post_order[rr];
  printf("%d ", result);

  int in_index = indices[result];
  int left_count = in_index - l;

  traverse(l, in_index - 1, ll, ll + left_count - 1);
  traverse(in_index + 1, r, ll + left_count, rr - 1);
}

int main()
{
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &in_order[i]);
    indices[in_order[i]] = i;
  }
  for (int i = 0; i < N; i++)
    scanf("%d", &post_order[i]);

  traverse(0, N - 1, 0, N - 1);
  return 0;
}
