//====================================================
// Matt Kretchmar
// September 2022
// grid.cpp
// A program to illustrate working on connected grids
// with
// 1) flood fill
// 2) is Contiguous
// 3) region counting
//====================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int M = 10;

void	readGrid	( int G[M][M] );
void	printGrid	( int G[M][M] );
void 	floodFill	( int grid[M][M], int r, int c, int source, int target );
bool isConnected	( int grid[M][M], int r1, int c1, int r2, int c2);

//====================================================
// main
//====================================================
int main ( void )
{
	int grid[M][M];

	// read in and print grid
	readGrid(grid);
	printGrid(grid);
	floodFill(grid,0,0,1,2);
	printGrid(grid);

	int r1, r2, c1, c2;
	r1 = 7; c1 = 0;
	r2 = 6; c2 = 9;
	if ( isConnected(grid,r1,c1,r2,c2) )
		cout << r1 << "," << c2 << "connected to "
		<< r2 << ",";

	return 0;
}

//====================================================
// readGrid
// This function reads from standard input into
// an MxM 2D array of integers.
// PARAMETERS:
// G : a 2D array of integers of M rows and M cols
//     where M is a global constant
// RETURN VALUE:
// none but the values in G are changed
//====================================================
void readGrid ( int G[M][M] )
{
	for ( int i = 0; i < M; i++ )
		for ( int j = 0; j < M; j++ )
			cin >> G[i][j];
}
//====================================================
// printGrid
// This function prints a 2D array of integers as
// neat rows and columns to the screen.
// G : a 2D array of integers of M rows and M cols
//     where M is a global constant
// RETURN VALUE:
// none but this function prints to the screen
//====================================================
void printGrid ( int G[M][M] )
{
	for ( int i = 0; i < M; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			cout << setw(4) << G[i][j];
		}
		cout << endl;
	}
}


//====================================================
// floodFill
// This algorithm implements the classic floodfill by changing a connected
// region within the grid 2d array from the source color to the target color.
// PARAMS:
// grid: sn MxM 2d matrix of integers
// r, c: valid row and column indices of the box to change. Assume 0 <= r, c <=
// 		M-1
// source: (int) the color we are looking for
// target: (int) the color we want to change to
// RETURN:
// nothing, but this assignment changes the grid values.
//====================================================
void 	floodFill	( int grid[M][M], int r, int c, int source, int target ){

	assert(r>=0);
	assert(c>=0);
	assert(r<M);
	assert(c<M);

	if (grid[r][c] != source)
		return;
	grid[r][c] = target;
	// check up
	if (r>0)
		floodFill(grid, r-1, c, source, target);
	// check down
	if (r<M-1)
		floodFill(grid, r-1, c, source, target);
	// check left
	if (c>0)
		floodFill(grid, r, c-1, source, target);
	// check right
	if (c<M-1)
		floodFill(grid, r, c+1, source, target);
	return;
}
//====================================================
// isConnected
// Determines if two coordinates in the grid are part of the same region.
// PARAMS:
// grid: MxM 2d array of ints
// r1, c1: coordinates of the first box
// r2, c2: coordinates of the second box
// assume 0<= r1, c1, r2, c2
// RETURNS:
// True or false for if the two boxes are connected in the same region.
//====================================================
bool isConnected	(int grid[M][M], int r1, int r2, int c1, int c2){
	if ( grid[r1][c1] != grid[r2][c2] )
		return false;

	int source = grid[r1][c1];
	floodFill(grid,r1,c1,grid[r1][c1],99);

	bool result = grid[r2][c2] == 99;

	floodFill(grid,r1,c1,99,source);
	return result;
}

//====================================================
//====================================================
