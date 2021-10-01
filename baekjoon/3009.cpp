#include <iostream>

int main()
{
  int x[3], y[3];
  for (int i = 0; i < 3; i++)
    scanf("%d%d", &x[i], &y[i]);

  int nx = 0;
  for (int i = 0; i < 3; i++)
  {
    bool f = false;
    for (int j = 0; j < 3; j++)
    {
      if (i == j)
        continue;
      f = f || x[j] == x[i];
    }
    if (!f)
      nx = x[i];
  }

  int ny = 0;
  for (int i = 0; i < 3; i++)
  {
    bool f = false;
    for (int j = 0; j < 3; j++)
    {
      if (i == j)
        continue;
      f = f || y[j] == y[i];
    }
    if (!f)
      ny = y[i];
  }

  printf("%d %d", nx, ny);

  return 0;
}
