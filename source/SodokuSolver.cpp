#include "SodokuSolver.h"

int answer()
{
	return 6 * 7;
}

void SodokuSolverClass::m_boot()
{
	m_initSodokuGrid();

	std::array<std::array<int, 9>, 9> example_CSV_file = { {
		{ 0, 0, 7, 0, 0, 1, 3, 0, 0 },
		{ 3, 0, 0, 0, 5, 0, 6, 0, 0 },
		{ 5, 0, 8, 0, 3, 0, 0, 0, 4 },
		{ 0, 8, 0, 0, 6, 0, 9, 0, 0 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 6 },
		{ 0, 0, 4, 0, 1, 0, 0, 7, 0 },
		{ 2, 0, 0, 0, 8, 0, 4, 0, 3 },
		{ 0, 0, 6, 0, 7, 0, 0, 0, 8 },
		{ 0, 0, 5, 9, 0, 0, 7, 0, 0 },
		} };

	m_initSodokuGrid();
	m_mock_read_csv(example_CSV_file);
	m_init_or_reset_possible_number_array();
	
	m_solve_grid();

	for (int i = 0; i <= 8; i++)
	{
		std::cout << "Sodoku Grid Row " << i << ": "; 

		for (int i2 = 0; i2 <= 8; i2++)
		{
			std::cout << m_sodoku_grid[i][i2] << "|";
		}

		std::cout << "\n";
	}
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

void SodokuSolverClass::m_remove_possible_numbers_by_row(int current_row)
{
	for (int i = 0; i <= 8; i++)
	{
		for (int i2 = 0; i2 <= 8; i2++)
		{
			if (m_sodoku_grid[current_row][i] == m_possible_numbers[i2])
			{
				m_possible_numbers[i2] = 0;
			}
		}
	}
}

void SodokuSolverClass::m_remove_possible_numbers_by_column(int current_column)
{
	for (int i = 0; i <= 8; i++)
	{
		for (int i2 = 0; i2 <= 8; i2++)
		{
			if (m_sodoku_grid[i][current_column] == m_possible_numbers[i2])
			{
				m_possible_numbers[i2] = 0;
			}
		}
	}
}

void SodokuSolverClass::m_remove_possible_numbers_by_grid(int current_row, int current_column)
{
	//Upgrade info: Expand if statement to support all 9 sub-grids on sodoku grid. Highly likely to cause bugs, upgrade carefully

	if ((current_row <= 2) && (current_column <= 2))
	{
		for (int row = 0; row <= 2; row++) //Controls which row and columns are being checked, hence smaller i limit
		{

			for (int column = 0; column <= 2; column++)
			{

				for (int i = 0; i <= 8; i++) //checks current location on grid for any number in m_possible_numbers
				{

					if (m_sodoku_grid[row][column] == m_possible_numbers[i])
					{
						m_possible_numbers[i] = 0;
					}

				}

			}

		}
	}
}

void SodokuSolverClass::m_add_first_possible_number(int row, int column)
{
	int i = 0;
	bool stop_loop = false;
	while ((stop_loop == false) && (i <= 8))
	{
		if ((m_possible_numbers[i] != 0) && (m_sodoku_grid[row][column] == 0))
		{
			m_sodoku_grid[row][column] = m_possible_numbers[i];
			stop_loop = true;
		}
		i += 1;
	}
}

void SodokuSolverClass::m_solve_grid()
{
	//Upgrade info: Change "<= 2" to "<= 8" to support entire sodoku grid

	for (int row = 0; row <= 2; row++)
	{
		for (int column = 0; column <= 2; column++)
		{
			m_init_or_reset_possible_number_array();
			m_remove_possible_numbers_by_row(row);
			m_remove_possible_numbers_by_column(column);
			m_remove_possible_numbers_by_grid(row, column);
			m_add_first_possible_number(row, column);
		}
	}
}