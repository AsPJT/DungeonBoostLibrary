#pragma once
#include <array>
#include <iostream>
using Matrix = std::array<std::array<int, 32>, 24>;//Matrix�^�̒�`

class Maze {
public:
  void Draw(Matrix& matrix) {//�񎟌��z��̕`��
	for (int y = 0; y < 24; y++) {
	  for (int x = 0; x < 32; x++) {
		std::cout << matrix[y][x];
	  }
	  std::cout << std::endl;
	}
  }
};