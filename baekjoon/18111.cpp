#include <iostream>

using namespace std;

int main()
{
  int N, M, B;
  scanf("%d%d%d", &N, &M, &B);

  int blocks[N][M];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      scanf("%d", &blocks[i][j]);
    }
  }

  int minimum_time = 99999999;
  int result_height = 0;
  for (int target_height = 0; target_height <= 256; target_height++)
  {
    int time = 0;
    int b = B;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if (blocks[i][j] < target_height)
        {
          time += target_height - blocks[i][j];
          b -= target_height - blocks[i][j];
        }
        else
        {
          time += (blocks[i][j] - target_height) * 2;
          b += blocks[i][j] - target_height;
        }
      }
    }
    if (b >= 0 && time <= minimum_time)
    {
      minimum_time = time;
      result_height = target_height;
    }
  }
  printf("%d %d", minimum_time, result_height);
  return 0;
}
