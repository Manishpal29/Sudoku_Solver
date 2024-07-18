//SUDOKU SOLVER
#include<iostream>
#include<math.h>
using namespace std;

int print(int board[][9], int n)
{
	for(int row=0; row<n; row++)
	{
		for(int col=0; col<n; col++)
		{
			cout<<board[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool isvalid(int board[][9],int row, int col, int num,int n)
{
	//row and column check
	for(int x=0; x<n; x++)
	{
		if(board[row][x]==num ||board[x][col]==num )
		{
			return false;
		}
	}
	
	//submatrix check
	int rn = sqrt(n);
	int si=row-row % rn;
	int sj=col-col % rn;
	
	for(int x=si; x<si+rn; x++)
	{
		for(int y=sj; y<sj+rn; y++)
		{
			if(board[x][y]==num)
			{
				return false;
			}
		}
	}
	
}
bool sudokusolver(int board[][9], int row, int col, int n)
{
	//base condition;
	if(row==n)
	{
		print(board,n);
		return true;
	}
	
	//if we are not inside the board;
	    if(col==n)
	{
		return sudokusolver(board,row+1,0,n);
	}
	
		//if cell already filled with an appropriaate number
    	if(board[row][col]!=0)
	{
		return sudokusolver(board,row,col+1,n);
	}

	//we will try to cell the with the appropriate number
		for(int num=1; num<=9; num++)
	{
		//check is num can be filled
		if(isvalid(board,row,col,num,n))
		{
			board[row][col]=num;
		    bool subans=sudokusolver(board,row,col+1,n);
		    if(subans)
		    {
		    	return true;
			}
		 	//backtracking..=> undo the change;
		 	board[row][col]=0;	 	
		}
	}
	return false;
}
int main()
{
	int n=9;
	int board[9][9]=
	{
		{0, 0, 7, 1, 0, 0, 0, 6, 0},
		{1, 0, 5, 2, 0, 8, 0, 0, 0},
		{6, 0, 0, 0, 0, 7, 1, 2, 0},
		{3, 1, 2, 4, 0, 5, 0, 0, 8},
		{0, 0, 0, 0, 9, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 3, 0, 0, 1},
		{0, 0, 1, 0, 0, 4, 9, 8, 6},
		{8, 0, 3, 9, 0, 6, 0, 0, 0},
		{0, 6, 0, 0, 8, 2, 7, 0, 3},
		
	};
	sudokusolver(board,0,0,n);
	
	return 0;
}
