#include "SodokuSolver.h"

int answer()
{
	return 6 * 7;
}

void SodokuSolverClass::m_boot()
{

}

void SodokuSolverClass::m_initSodokuGrid()
{
	for (int i = 0; i <= 8; i++)
	{
		m_sodoku_grid[0][i] = { 0 };
		m_sodoku_grid[1][i] = { 0 };
		m_sodoku_grid[2][i] = { 0 };
		m_sodoku_grid[3][i] = { 0 };
		m_sodoku_grid[4][i] = { 0 };
		m_sodoku_grid[5][i] = { 0 };
		m_sodoku_grid[6][i] = { 0 };
		m_sodoku_grid[7][i] = { 0 };
		m_sodoku_grid[8][i] = { 0 };
	}
}

void SodokuSolverClass::m_mock_read_csv(std::array<std::array<int, 9>, 9> mock_CSV)
{
	m_sodoku_grid = mock_CSV;
}

void SodokuSolverClass::m_init_or_reset_possible_number_array()
{
	for (int i = 0; i <= 8; i++)
	{
		m_possible_numbers[i] = i + 1;
	}
}