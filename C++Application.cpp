#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

enum Cell {
	EMPTY,
	M1,
	M2,
	M3,
	M4,
	M5,
	M6,
	M7,
	M8,
	M9,
	MINE,
};

void PrintMineField(const std::vector<std::vector<Cell>>& mineField) {
	for (const auto& row : mineField) {
		for (const Cell& cell : row) {
			switch (cell) {
			case EMPTY:
				std::cout << ".";
				break;
			case M1:
				std::cout << "1";
				break;
			case M2:
				std::cout << "2";
				break;
			case M3:
				std::cout << "3";
				break;
			case M4:
				std::cout << "4";
				break;
			case M5:
				std::cout << "5";
				break;
			case M6:
				std::cout << "6";
				break;
			case M7:
				std::cout << "7";
				break;
			case M8:
				std::cout << "8";
				break;
			case M9:
				std::cout << "9";
				break;
			case MINE:
				std::cout << "M";
				break;
			}
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<Cell>> GenerateMineField(int width, int height, int numMines) {
	std::vector<std::vector<Cell>> mineField(height, std::vector<Cell>(width, EMPTY));

	//Random Seed
	srand(static_cast<unsigned>(time(nullptr)));
	int minesPlaced = 0;

	// Place mines randomly
	while (minesPlaced < numMines) {
		int x = rand() % width;
		int y = rand() % height;

		if (mineField[y][x] != MINE) {
			mineField[y][x] = MINE;
			minesPlaced++;
		}
	}

	// Coordinates of neighboring cells
	int neighborOffsetsX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int neighborOffsetsY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	// Calculate the number of mines around each cell
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			if (mineField[row][col] != MINE) {
				int mineCount = 0;
				for (int direction = 0; direction < 8; ++direction) {
					int neighborX = col + neighborOffsetsX[direction];
					int neighborY = row + neighborOffsetsY[direction];
					if (neighborX >= 0 && neighborX < width && neighborY >= 0 && neighborY < height && mineField[neighborY][neighborX] == MINE) {
						mineCount++;
					}
				}
				mineField[row][col] = static_cast<Cell>(mineCount);
			}
		}
	}

	return mineField;
}

int main() {

	int width = 10;
	int height = 10;
	int numMines = 10;

	std::vector<std::vector<Cell>> mineField = GenerateMineField(width, height, numMines);

	PrintMineField(mineField);
}
