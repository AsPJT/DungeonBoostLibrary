#include "Maze.hpp"
#include <iostream>
#include <random>
#define debug(var) std::cout << #var << ": " << var << std::endl

int main() {

  Matrix matrix;//0 -> �ʘH 1 -> ��
  for (int y = 0; y < 24; y++)for (int x = 0; x < 32; x++) {
	if (x == 0 || x == 31 || y == 0 || y == 23) {
	  matrix[y][x] = 1;
	}
	else if (x % 2 == 0 && y % 2 == 0)matrix[y][x] = 1;
	else matrix[y][x] = 0;
  }//Step1

  int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };//4�̃x�N�g����p�ӂ��Ă���
  std::mt19937 mt{ std::random_device{}() };
  std::uniform_int_distribution<int> dist1(0, 3);//operator()��0 ~ 3�̗�����Ԃ�(1�s�ڗp)
  std::uniform_int_distribution<int> dist2(0, 2);//0 ~ 2�̗�����Ԃ�(2�s�ڈȍ~�p)
  
  for (int y = 2; y < 24; y += 2)for (int x = 2; x < 32; x += 2) {
	bool succeeded = false;//�_��|���̂ɐ����������ǂ���(�������ł�1�̂Ƃ���ɓ|�ꂽ��false)
	int cnt = 0;
	while (!succeeded) {//��������܂Ń��[�v����
	  int direction = -1;
	  if (y == 2)direction = dist1(mt);
	  else direction = dist2(mt);
	  if (matrix[y + dy[direction]][x + dx[direction]] == 0) {
		succeeded = true;
		matrix[y + dy[direction]][x + dx[direction]] = 1;
	  }
	  cnt++;
	  if (cnt == 4)break;//4�����T�����đS���ǂ�������break����
	}
  }

  Maze maze;
  maze.Draw(matrix);

  return 0;
}