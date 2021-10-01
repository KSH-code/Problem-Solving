#include <iostream>

int main()
{
  int x, y;
  scanf("%d%d", &x, &y);

  int result = 0;
  if (x > 0)
  {
    result = y > 0 ? 1 : 4;
  }
  else
  {
    result = y > 0 ? 2 : 3;
  }
  printf("%d", result);
  return 0;
}
