//(c) 2019 written by Jin3004

#pragma once
#include <vector>
#include <iostream>
using Matrix = std::vector<std::vector<int>>;//Matrix�^�̒�`

class Maze {
public:
  void Draw(Matrix& matrix) {//�񎟌��z��̕`��
	for (int y = 0; y < matrix.size(); y++) {
	  for (int x = 0; x < matrix[y].size(); x++) {
		std::cout << matrix[y][x];
	  }
	  std::cout << std::endl;
	}
  }
};