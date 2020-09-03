#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
// http://soj.acmm.club/show_problem.php?pid=1004&cid=2803
/*
Rocking is a lazy boy. One day his little brother challenged him with a problem. His brother gave him an N*N matrix, and asked him to choose N numbers from the matrix with no two numbers in the same row or column. Certainly there're lots of ways to choose the N numbers. But his brother wanted to see whether Rocking can choose the numbers in a way that it can produce the largest sum by adding up all the N numbers.

Rocking doesn't want to lose, of course, to such a little kid. But also he doesn't like to make efforts on choosing numbers and calculating. So he asks for your help. Please write a program for him to produce the largest sum he could get with the provided matrix.
*/
int get_largest(vector<vector<int>>& matrix) {
  int N = matrix.size();
  vector<int> vec((1 << N), 0);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < vec.size(); ++k) {
        bitset<16> bs(k);
        if (bs.count() != i || bs.test(j)) continue; 
        bs.set(j);
        if (vec[k] + matrix[i][j] > vec[bs.to_ulong()]) vec[bs.to_ulong()] = vec[k] + matrix[i][j];
      }
    }
  }
  return vec[vec.size() - 1];
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N;
    scanf("%d", &N);
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%d", &matrix[i][j]);
      }
    }
    printf("%d\n", get_largest(matrix));
  }
}
