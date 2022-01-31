#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

  int N, M;
  cin >> N >> M;

  int A[N][M];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
      cin >> A[i][j];
  }

  int K;
  cin >> M >> K;

  int B[M][K];
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < K; j++)
      cin >> B[i][j];
  }

  int C[N][K];

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < K; j++)
    {
      int result = 0;
      for (int k = 0; k < M; k++)
      {
        result += A[i][k] * B[k][j];
      }
      C[i][j] = result;
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < K; j++)
    {
      cout << C[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
