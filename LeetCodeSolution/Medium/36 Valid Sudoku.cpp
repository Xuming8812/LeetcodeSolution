#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/


//used used1 to store whether num is in ith row, used2 for col, used3 for sub-box
bool isValidSudoku(vector<vector<char> > &board)
{
	int used1[9][9] = { 0 }, used2[9][9] = { 0 }, used3[9][9] = { 0 };

	for (int i = 0; i < board.size(); ++i)
		for (int j = 0; j < board[i].size(); ++j)
			if (board[i][j] != '.')
			{
				int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
				if (used1[i][num] || used2[j][num] || used3[k][num])
					return false;
				used1[i][num] = used2[j][num] = used3[k][num] = 1;
			}

	return true;
}