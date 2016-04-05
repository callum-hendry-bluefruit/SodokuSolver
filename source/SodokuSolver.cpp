#include "SodokuSolver.h"

int answer()
{
	return 6 * 7;
}

void SodokuSolverClass::m_boot(bool use_mock_file, std::array<std::array<int, 9>, 9> example_CSV_file)
{
	m_initSodokuGrid();

	if (use_mock_file == true)
	{
		m_mock_read_csv(example_CSV_file);
	}
	else
	{
		//READ REAL CSV HERE
	}

	m_init_or_reset_possible_number_array();
	m_solve_grid(8,8);

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

	if ((current_row <= 2) && (current_column <= 2)) //Top-left
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
	else if ((current_row <= 2) && (current_column >= 3) && (current_column <= 5)) //Top-middle
	{
		for (int row = 0; row <= 2; row++) //Controls which row and columns are being checked, hence smaller i limit
		{
			for (int column = 0; column <= 2; column++)
			{
				for (int i = 0; i <= 8; i++) //checks current location on grid for any number in m_possible_numbers
				{
					if (m_sodoku_grid[row][(column + 3)] == m_possible_numbers[i])
					{
						m_possible_numbers[i] = 0;
					}
				}
			}
		}
	}
	else if ((current_row <= 2) && (current_column > 5)) //Top-right
	{
		for (int row = 0; row <= 2; row++) //Controls which row and columns are being checked, hence smaller i limit
		{
			for (int column = 0; column <= 2; column++)
			{
				for (int i = 0; i <= 8; i++) //checks current location on grid for any number in m_possible_numbers
				{
					if (m_sodoku_grid[row][(column + 6)] == m_possible_numbers[i])
					{
						m_possible_numbers[i] = 0;
					}
				}
			}
		}
	}
	else if ((current_row >= 3) && (current_row <= 5) && (current_column <= 2)) //Middle-left
	{
		for (int row = 0; row <= 2; row++) //Controls which row and columns are being checked, hence smaller i limit
		{
			for (int column = 0; column <= 2; column++)
			{
				for (int i = 0; i <= 8; i++) //checks current location on grid for any number in m_possible_numbers
				{
					if (m_sodoku_grid[(row + 3)][column] == m_possible_numbers[i])
					{
						m_possible_numbers[i] = 0;
					}
				}
			}
		}
	}
	else if ((current_row >= 3) && (current_row <= 5) && (current_column >= 3) && (current_column <= 5)) //Middle-middle
	{
		for (int row = 0; row <= 2; row++) //Controls which row and columns are being checked, hence smaller i limit
		{
			for (int column = 0; column <= 2; column++)
			{
				for (int i = 0; i <= 8; i++) //checks current location on grid for any number in m_possible_numbers
				{
					if (m_sodoku_grid[(row + 3)][(column + 3)] == m_possible_numbers[i])
					{
						m_possible_numbers[i] = 0;
					}
				}
			}
		}
	}
	else if ((current_row >= 3) && (current_row <= 5) && (current_column > 5)) //Middle-right
	{
		for (int row = 0; row <= 2; row++) //Controls which row and columns are being checked, hence smaller i limit
		{
			for (int column = 0; column <= 2; column++)
			{
				for (int i = 0; i <= 8; i++) //checks current location on grid for any number in m_possible_numbers
				{
					if (m_sodoku_grid[row][(column + 6)] == m_possible_numbers[i])
					{
						m_possible_numbers[i] = 0;
					}
				}
			}
		}
	}
	else if ((current_row >= 6) && (current_column <= 2)) //Bottom-left
	{
		for (int row = 0; row <= 2; row++) //Controls which row and columns are being checked, hence smaller i limit
		{
			for (int column = 0; column <= 2; column++)
			{
				for (int i = 0; i <= 8; i++) //checks current location on grid for any number in m_possible_numbers
				{
					if (m_sodoku_grid[(row + 6)][column] == m_possible_numbers[i])
					{
						m_possible_numbers[i] = 0;
					}
				}
			}
		}
	}
	else if ((current_row >= 6) && (current_column >= 3) && (current_column <= 5)) //Bottom-middle
	{
		for (int row = 0; row <= 2; row++) //Controls which row and columns are being checked, hence smaller i limit
		{
			for (int column = 0; column <= 2; column++)
			{
				for (int i = 0; i <= 8; i++) //checks current location on grid for any number in m_possible_numbers
				{
					if (m_sodoku_grid[(row + 6)][(column + 3)] == m_possible_numbers[i])
					{
						m_possible_numbers[i] = 0;
					}
				}
			}
		}
	}
	else if ((current_row >= 6) && (current_column > 5)) //Bottom-right
	{
		for (int row = 0; row <= 2; row++) //Controls which row and columns are being checked, hence smaller i limit
		{
			for (int column = 0; column <= 2; column++)
			{
				for (int i = 0; i <= 8; i++) //checks current location on grid for any number in m_possible_numbers
				{
					if (m_sodoku_grid[(row + 6)][(column + 6)] == m_possible_numbers[i])
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

void SodokuSolverClass::m_solve_grid(int num_of_rows, int num_of_columns)
{
	//Upgrade info: Change "<= 2" to "<= 8" to support entire sodoku grid

	for (int row = 0; row <= num_of_rows; row++)
	{
		for (int column = 0; column <= num_of_columns; column++)
		{
			m_init_or_reset_possible_number_array();
			m_remove_possible_numbers_by_row(row);
			m_remove_possible_numbers_by_column(column);
			m_remove_possible_numbers_by_grid(row, column);
			m_add_first_possible_number(row, column);
		}
	}
}