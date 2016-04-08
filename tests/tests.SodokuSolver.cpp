#include "..\source\SodokuSolver.h"
#include "gtest/gtest.h"
#include <cassert>
#include <iostream>

TEST(testHiker, answer_test)
{
	EXPECT_EQ(42, answer());
}

TEST(testSodokuSolver, initalise_a_9x9_2d_vector)
{
	SodokuSolverClass initaliseVectorInstance;
	initaliseVectorInstance.m_initSodokuGrid();

	std::array<std::array<int, 9>, 9> example_array = { {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		} };

	EXPECT_EQ(example_array, initaliseVectorInstance.m_sodoku_grid);
}

TEST(testSodokuSolver, set_m_sodoku_grid_to_mock_CSV_file)
{
	SodokuSolverClass readMockCSV;

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

	readMockCSV.m_mock_read_csv(example_CSV_file);

	EXPECT_EQ(example_CSV_file, readMockCSV.m_sodoku_grid);
}

TEST(testSodokuSolver, initalise_or_reset_values_of_possible_number_array)
{
	SodokuSolverClass initOrResetPossibleNumberArray;
	initOrResetPossibleNumberArray.m_init_or_reset_possible_number_array();

	std::vector<int> expected_possible_numbers_array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	EXPECT_EQ(expected_possible_numbers_array, initOrResetPossibleNumberArray.m_possible_numbers);
}

TEST(testSodokuSolver, remove_numbers_from_array_based_on_first_row_of_m_sodoku_grid_after_copying_CSV_values)
{
	SodokuSolverClass removeNumbers;

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

	std::vector<int> expected_possible_numbers_array = { 2, 4, 5, 6, 8, 9 };

	removeNumbers.m_initSodokuGrid();
	removeNumbers.m_mock_read_csv(example_CSV_file);
	removeNumbers.m_init_or_reset_possible_number_array();
	removeNumbers.m_remove_possible_numbers_by_row(0);

	EXPECT_EQ(expected_possible_numbers_array, removeNumbers.m_possible_numbers);
}

TEST(testSodokuSolver, remove_numbers_from_array_based_on_first_column_of_m_sodoku_grid_after_copying_CSV_values)
{
	SodokuSolverClass removeNumbers;

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

	std::vector<int> expected_possible_numbers_array = { 1, 4, 6, 8, 9 };

	removeNumbers.m_initSodokuGrid();
	removeNumbers.m_mock_read_csv(example_CSV_file);
	removeNumbers.m_init_or_reset_possible_number_array();

	removeNumbers.m_remove_possible_numbers_by_column(0);

	EXPECT_EQ(expected_possible_numbers_array, removeNumbers.m_possible_numbers);
}

TEST(testSodokuSolver, remove_numbers_from_array_based_on_first_row_and_column_of_sodoku_grid)
{
	SodokuSolverClass removeNumbers;

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

	std::vector<int> expected_possible_numbers_array = { 4, 6, 8, 9 };

	removeNumbers.m_initSodokuGrid();
	removeNumbers.m_mock_read_csv(example_CSV_file);
	removeNumbers.m_init_or_reset_possible_number_array();

	removeNumbers.m_remove_possible_numbers_by_row(0);
	removeNumbers.m_remove_possible_numbers_by_column(0);

	EXPECT_EQ(expected_possible_numbers_array, removeNumbers.m_possible_numbers);
}

TEST(testSodokuSolver, remove_possible_numbers_based_on_3x3_grids_in_sodoku_grid)
{
	SodokuSolverClass removeNumbers;

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

	std::vector<int> expected_possible_numbers_array = { 4, 6, 9 };

	removeNumbers.m_initSodokuGrid();
	removeNumbers.m_mock_read_csv(example_CSV_file);
	removeNumbers.m_init_or_reset_possible_number_array();

	removeNumbers.m_remove_possible_numbers_by_row(0);
	removeNumbers.m_remove_possible_numbers_by_column(0);
	removeNumbers.m_remove_possible_numbers_by_grid(0, 0);

	EXPECT_EQ(expected_possible_numbers_array, removeNumbers.m_possible_numbers);
}

TEST(testSodokuSolver, add_first_non_zero_possible_number_to_grid)
{
	SodokuSolverClass addFirstPossible;

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

	std::array<std::array<int, 9>, 9> expected_sodoku_grid = example_CSV_file;
	expected_sodoku_grid[0][0] = 4;

	int row = 0;
	int column = 0;

	addFirstPossible.m_initSodokuGrid();
	addFirstPossible.m_mock_read_csv(example_CSV_file);
	addFirstPossible.m_init_or_reset_possible_number_array();

	addFirstPossible.m_remove_possible_numbers_by_row(row);
	addFirstPossible.m_remove_possible_numbers_by_column(column);
	addFirstPossible.m_remove_possible_numbers_by_grid(row, column);

	addFirstPossible.m_add_first_possible_number(row, column);

	EXPECT_EQ(expected_sodoku_grid, addFirstPossible.m_sodoku_grid);
}

TEST(testSodokuSolver, solve_3x3_grid_in_top_left_corner)
{
	SodokuSolverClass solveFirstGrid;

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

	std::array<std::array<int, 9>, 9> expected_sodoku_grid = { {
		{ 4, 2, 7, 0, 0, 1, 3, 0, 0 },
		{ 3, 1, 9, 0, 5, 0, 6, 0, 0 },
		{ 5, 6, 8, 0, 3, 0, 0, 0, 4 },

		{ 0, 8, 0, 0, 6, 0, 9, 0, 0 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 6 },
		{ 0, 0, 4, 0, 1, 0, 0, 7, 0 },

		{ 2, 0, 0, 0, 8, 0, 4, 0, 3 },
		{ 0, 0, 6, 0, 7, 0, 0, 0, 8 },
		{ 0, 0, 5, 9, 0, 0, 7, 0, 0 },
		} };

	solveFirstGrid.m_initSodokuGrid();
	solveFirstGrid.m_mock_read_csv(example_CSV_file);
	solveFirstGrid.m_init_or_reset_possible_number_array();

	solveFirstGrid.m_solve_grid(2, 2);

	EXPECT_EQ(expected_sodoku_grid, solveFirstGrid.m_sodoku_grid);
}

TEST(testSodokuSolver, solve_entire_grid)
{
	SodokuSolverClass solve_grid;

	std::array<std::array<int, 9>, 9> example_CSV_file = { {
		{ 1, 0, 0, /**/ 0, 0, 7, /**/ 0, 9, 0 },
		{ 0, 3, 0, /**/ 0, 2, 0, /**/ 0, 0, 8 },
		{ 0, 0, 9, /**/ 6, 0, 0, /**/ 5, 0, 0 },

		{ 0, 0, 5, /**/ 3, 0, 0, /**/ 9, 0, 0 },
		{ 0, 1, 0, /**/ 0, 8, 0, /**/ 0, 0, 0 },
		{ 6, 0, 0, /**/ 0, 0, 4, /**/ 0, 0, 2 },

		{ 3, 0, 0, /**/ 0, 0, 0, /**/ 0, 1, 0 },
		{ 0, 4, 0, /**/ 0, 0, 0, /**/ 0, 0, 0 },
		{ 0, 0, 7, /**/ 0, 0, 0, /**/ 3, 0, 7 },
		} };

	std::array<std::array<int, 9>, 9> expected_sodoku_grid = { {
		{ 1, 6, 2, /**/ 8, 5, 7, /**/ 4, 9, 3 },
		{ 5, 3, 4, /**/ 1, 2, 9, /**/ 6, 7, 8 },
		{ 7, 8, 9, /**/ 6, 4, 3, /**/ 5, 2, 1 },

		{ 4, 7, 5, /**/ 3, 1, 2, /**/ 9, 8, 6 },
		{ 9, 1, 3, /**/ 5, 8, 6, /**/ 7, 4, 2 },
		{ 6, 2, 8, /**/ 7, 9, 4, /**/ 1, 3, 5 },

		{ 3, 5, 6, /**/ 4, 7, 8, /**/ 2, 1, 9 },
		{ 2, 4, 1, /**/ 9, 3, 5, /**/ 8, 6, 7 },
		{ 8, 9, 7, /**/ 2, 6, 1, /**/ 3, 5, 4 },
		} };

	solve_grid.m_boot(true, example_CSV_file, true);
	EXPECT_EQ(expected_sodoku_grid, solve_grid.m_sodoku_grid);
}