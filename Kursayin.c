#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

#define N 4
#define START_X  10
#define START_Y  5
#define TAB 4

void timeout() {
	for (double k = 1; k < 1e+7; k++);
}

bool isZero(int *arr, int i) {
	return arr[i] == 0 || arr[N - i - 1] == 0;
}

int moveX(int num, int to, COORD pos, HANDLE* hConsole) {
	int step = TAB / 2;
	step = pos.X < to ? step : step * -1;
	while (pos.X != to) {
		pos.X += step;
		SetConsoleCursorPosition(hConsole, pos);
		printf("%d", num);
		timeout();
		SetConsoleCursorPosition(hConsole, pos);
		printf("   ");
	}

	return pos.X;
}

int moveY(int num, int to, COORD pos, HANDLE* hConsole) {
	int step = 1;
	step = pos.Y < to ? step : step * -1;
	while (pos.Y != to) {
		pos.Y += step;
		SetConsoleCursorPosition(hConsole, pos);
		printf("%d", num);
		timeout();
		SetConsoleCursorPosition(hConsole, pos);
		printf("   ");
	}

	return pos.Y;
}


int main()
{
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int matrix[N][N] = {
		{1, 2, 3, 4},
		{5, 6, 0, 8},
		{9, 10, 7, 12},
		{0, 14, 15, 16}
	};

	int vector[N * N];
	int m = 0;

	pos.X = START_X;
	pos.Y = START_Y;
	SetConsoleCursorPosition(hConsole, pos);

	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++) {
			SetConsoleCursorPosition(hConsole, pos);
			//printf("%d", matrix[i][j]);
			printf("%d", matrix[i][j]);
			pos.X += 2 * TAB;
			timeout();
		}
		pos.X = START_X;
		pos.Y += TAB;
	}

	for (int i = 0; i < N; i++) {
		if (!isZero(&matrix[i], i)) {
			continue;
		}

		for (int j = 0; j < N; j++) {
			pos.X = START_X + TAB * 2 * j;
			pos.Y = START_Y + TAB * i;
			SetConsoleCursorPosition(hConsole, pos);
			pos.Y = moveY(matrix[i][j], pos.Y - 2, pos, hConsole);
			pos.X = moveX(matrix[i][j], START_X - TAB, pos, hConsole);
			pos.Y = moveY(matrix[i][j], pos.Y + (N - i) * TAB, pos, hConsole);
			pos.X = moveX(matrix[i][j], START_X + (TAB * 2 * m), pos, hConsole);
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