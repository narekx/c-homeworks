#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

#define N 4
#define START_X  10
#define START_Y  5
#define TAB 4

// Timeout
void timeout() {
	for (double k = 1; k < 1e+7; k++);
}

// Check array diagonal element is zero
bool isZero(int* arr, int i) {
	return arr[i] == 0 || arr[N - i - 1] == 0;
}

// Move by x
int moveX(int num, int to, COORD pos, HANDLE* hConsole) {
	int step = TAB;
	step = pos.X < to ? step : step * -1;
	while (pos.X != to) {
		pos.X += step;
		SetConsoleCursorPosition(hConsole, pos);
		printf("%d", num);
		timeout();
		SetConsoleCursorPosition(hConsole, pos);
		printf("    ");
	}

	return pos.X;
}

// Move by y
int moveY(int num, int to, COORD pos, HANDLE* hConsole) {
	int step = 1;
	step = pos.Y < to ? step : step * -1;
	while (pos.Y != to) {
		pos.Y += step;
		SetConsoleCursorPosition(hConsole, pos);
		printf("%d", num);
		timeout();
		SetConsoleCursorPosition(hConsole, pos);
		printf("    ");
	}

	return pos.Y;
}


int main()
{
	// Get coords
	COORD pos;

	// Get console
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Matrix initialize
	int matrix[N][N] = {
		{1, -281, 3, 0},
		{5, 6, 0, 8},
		{9, 10, 0, 12},
		{0, 144, 15, 16}
	};

	// Vector
	int vector[N * N];

	// Vector length
	int m = 0;

	// Initialize start position
	pos.X = START_X;
	pos.Y = START_Y;
	SetConsoleCursorPosition(hConsole, pos);

	// Print matrix
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			SetConsoleCursorPosition(hConsole, pos);
			printf("%d", matrix[i][j]);
			pos.X += 4 * TAB;
			timeout();
		}
		pos.X = START_X;
		pos.Y += TAB;
	}

	// Set color to green
	SetConsoleTextAttribute(hConsole, 2);

	// Create vector
	for (int i = 0; i < N; i++) {
		if (!isZero(&matrix[i], i)) {
			continue;
		}

		for (int j = 0; j < N; j++) {
			pos.X = START_X + TAB * 4 * j;
			pos.Y = START_Y + TAB * i;
			
			int toX = START_X + TAB * 2 * m;

			pos.X = moveX(matrix[i][j], pos.X >= toX ? pos.X - TAB * 2 : pos.X + TAB * 2, pos, hConsole);
			pos.Y = moveY(matrix[i][j], START_Y + N * TAB, pos, hConsole);
			pos.X = moveX(matrix[i][j], toX, pos, hConsole);
			pos.Y = moveY(matrix[i][j], pos.Y + TAB / 2, pos, hConsole);
			SetConsoleCursorPosition(hConsole, pos);
			printf("%d", matrix[i][j]);
			vector[m] = matrix[i][j];
			m++;
		}
	}

	pos.X = START_X + TAB * N;
	pos.Y += START_Y + TAB * N;
	SetConsoleCursorPosition(hConsole, pos);

	return 0;
}
