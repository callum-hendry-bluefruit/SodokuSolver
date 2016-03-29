#include "SodokuSolver.h"

int answer()
{
	return 6 * 7;
}

void SodokuSolverClass::initSodokuGrid()
{
	for (int i = 0; i <= 8; i++)
	{
		
		sodoku_grid[0][i] = { 0 };
		sodoku_grid[1][i] = { 0 };
		sodoku_grid[2][i] = { 0 };
		sodoku_grid[3][i] = { 0 };
		sodoku_grid[4][i] = { 0 };
		sodoku_grid[5][i] = { 0 };
		sodoku_grid[6][i] = { 0 };
		sodoku_grid[7][i] = { 0 };
		sodoku_grid[8][i] = { 0 };
		
	}
}