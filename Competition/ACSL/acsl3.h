#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>
#define N 4 
#define UNASSIGNED 0

bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num);
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}

bool SolveSudoku(int grid[N][N])
{
    int row, col;
 
    if (!FindUnassignedLocation(grid, row, col))
       return true; // success!
 
    for (int num = 1; num < 4; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
 
            if (SolveSudoku(grid))
                return true;
 
            grid[row][col] = UNASSIGNED;
        }
    }
    return false; 
}
int GRID[N][N] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0,0,0,0}, {0, 0, 0, 0}};

void addBlock(int num){
	int row = (num - 6) / 6;
	int col = (num - 2) % 6; 
	GRID[row][col] = 5; 
}

void addValue2Row(int val, int row, bool l2r){ // r2l = 0 Left, 1 Right 
	int pos = 0;
	bool added = false; 
	while(pos != 4 && !added && !UsedInRow(GRID, row, val)){
		if(l2r){
			if(GRID[row][pos] == 0){
				GRID[row][pos] = val;
				added = true;
			} else {
				pos ++; 
			}
		} else {
			if(GRID[row][abs(3 - pos)] == 0){
				GRID[row][abs(3 - pos)] = val;
				added = true; 
			} else {
				pos ++;
			}
		}
	}
}

void addValue2Col(int val, int col, bool l2r){ // r2l = 0 Up, 1 Down 
	int pos = 0;
	bool added = false; 
	while(pos != 4 && !added && !UsedInCol(GRID, col, val)){
		if(l2r){
			if(GRID[pos][col] == 0){
				GRID[pos][col] = val;
				added = true;
			} else {
				pos ++; 
			}
		} else {
			if(GRID[abs(3 - pos)][col] == 0){
				GRID[abs(3 - pos)][col] = val;
				added = true; 
			} else {
				pos ++;
			}
		}
	}
}

void addPoint(int num, int val){
	switch(num){
		case 2: addValue2Col(val, 0, true); break;
		case 3: addValue2Col(val, 1, true); break;
		case 4: addValue2Col(val, 2, true); break;
		case 5: addValue2Col(val, 3, true); break;
		case 32: addValue2Col(val, 0, false); break;
		case 33: addValue2Col(val, 1, false); break;
		case 34: addValue2Col(val, 2, false); break;
		case 35: addValue2Col(val, 3, false); break;
		case 7: addValue2Row(val, 0, true); break;
		case 13: addValue2Row(val, 1, true); break;
		case 19: addValue2Row(val, 2, true); break;
		case 25: addValue2Row(val, 3, true); break;
		case 12: addValue2Row(val, 0, false); break;
		case 18: addValue2Row(val, 1, false); break;
		case 24: addValue2Row(val, 2, false); break;
		case 30: addValue2Row(val, 3, false); break;
		default:
		 break;
	}
}

int main()
{
    std::map<char, int> dict; 
    std::string dict_str = " ABC"; 

	dict['A'] = 1; 
	dict['B'] = 2;
	dict['C'] = 3; 
    // 0 means unassigned cells
    // int grid[N][N] = { {2, 0, 0, 0}, {5, 0, 0, 0}, {0, 0, 0, 5}, {3, 0, 5, 1}};
    for(int i = 0; i < 4; i++){
        int b;
        std::cin >> b; 
        addBlock(b);
    }
	int M;
	std::cin >> M;
	for(int i = 0; i < M; i++){
		int num; char val;
		std::cin >> val >> num;
		addPoint(num, dict[val]);
	}
	printGrid(GRID);
	std::string prt_str = "";
    if (SolveSudoku(GRID) == true){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j <4; j++){
                if(GRID[i][j] < 4)
                    prt_str += dict_str[GRID[i][j]];
            }
        }
        std::cout << prt_str << std::endl;
    }
    else{
         printf("No solution exists");
    }
    return 0;
}
