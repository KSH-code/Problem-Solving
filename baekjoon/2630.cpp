#include <iostream>

using namespace std;

int N;
int map[128][128];

int division(int x, int y, int r, int c)
{
  if (c == 1)
    return map[x][y] == r ? 1 : 0;

  int result = 0;
  for (int i = x; i < x + c; i++)
  {
    for (int j = y; j < y + c; j++)
    {
      if (map[i][j] != r)
      {
        return division(x, y, r, c / 2) + division(x + c / 2, y, r, c / 2) + division(x, y + c / 2, r, c / 2) + +division(x + c / 2, y + c / 2, r, c / 2);
      }
    }
  }
  return 1;
}

int main()
{
  scanf("%d", &N);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", &map[i][j]);

  printf("%d\n", division(0, 0, 0, N));
  printf("%d", division(0, 0, 1, N));
  return 0;
}
