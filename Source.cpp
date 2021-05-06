#include <iostream>
#include <fstream>
using namespace std;
void table(char arr[][10], int row, int col);
bool player1turn(char arr[][10], int row, int col);
bool player2turn(char arr[][10], int row, int col);
void filesave(char arr[][10], int row, int col);
int fileload(char arr[][10], int &row, int &col);
int main()
{
	bool flag = 0;
	int x = 0;
	char ch;
	int row, col, y;
	char arr[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = '-';
		}
	}
	cout << "Load previous game or a new game ? \npress 1 for load game\npress 0 for new game\n";
	cin >> ch;
	if (ch == '1')
		x = fileload(arr, row, col);
	else
	{
		cout << "NEW GAME\n";
		cout << "Enter the size of board (example(3)(4)) > ";
		cin >> row;
	}
	col = row;
	y = row * col;
	table(arr, row, col);
	while ((flag != 1) && (x < y))
	{
		cout << "Player 1 (X) turn\n";
		flag = player1turn(arr, row, col);
		x++;
		table(arr, row, col);
		if (flag == 1)
		{
			cout << "\nPLAYER 1 ( X ) WINS";
		}
		if (flag != 1 && x < y)
		{
			cout << "player 2 (O) turn\n";
			flag = player2turn(arr, row, col);
			x++;
			table(arr, row, col);
			if (flag == 1)
				cout << "\nPLAYER 2 ( O ) WINS";
		}
	}
	if (flag != 1)
		cout << "\nThe game is a DRAW";
	system("PAUSE");
}
void table(char arr[][10], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << arr[i][j];
			if (j != (col - 1))
				cout << "|";
		}
		cout << endl;
		for (int y = 0; y < (2 * col); y++)
		{
			if (i != (row - 1))
				cout << "_";
		}
		cout << endl;
	}
	filesave(arr, row, col);
}
bool player1turn(char arr[][10], int row, int col)
{
	bool flag = 0;
	int x = 0;
	int y, z;
	y = 0;
	z = 0;
	cout << "Enter row and column number\n";
	while (x < 1)
	{
		cin >> y >> z;
		if (arr[y][z] != 'X' && arr[y][z] != 'O' && y < row && z < col)
		{
			arr[y][z] = 'X';
			x++;
		}
		else
			cout << "Already marked or wrong input, Enter again\n";
	}
	filesave(arr, row, col);
	int a, b, c;
	a = 0;
	b = 0;
	c = 0;
	for (b = 0; b < col; b++)
	{
		for (a = 0; a < row; a++)
		{
			if (arr[a][b] == 'X')
				c++;
			else
				c = 0;
			if (c == row)
			{
				flag = 1;
				return flag;
			}
		}
		c = 0;
	}

	c = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
		{
			if (arr[a][b] == 'X')
				c++;
			else
				c = 0;
			if (c == col)
			{
				flag = 1;
				return flag;
			}
		}
		c = 0;
	}
	b = 0;
	c = 0;
	for (a = 0; a < row; a++)
	{
		if (arr[a][b] == 'X')
		{
			c++;
		}
		else
		{
			c = 0;
		}
		b++;
		if (c == col)
		{
			flag = 1;
			return flag;
		}
	}
	b = col - 1;
	c = 0;
	for (a = 0; a < row; a++)
	{
		if (arr[a][b] == 'X')
		{
			c++;
		}
		else
		{
			c = 0;
		}
		b--;
		if (c == row)
		{
			flag = 1;
			cout << "minor wise " << endl;
			return flag;
		}
	}
	return 0;
}
bool player2turn(char arr[][10], int row, int col)
{
	bool flag = 0;
	int x = 0;
	int y, z, t;
	cout << "Enter row and column number\n";
	while (x < 1)
	{
		cin >> y >> z;
		if (arr[y][z] != 'X' && arr[y][z] != 'O' && y < row && z < col)
		{
			arr[y][z] = 'O';
			x++;
		}
		else
			cout << "Already marked or wrong input, Enter again\n";
	}
	filesave(arr, row, col);
	int a, b, c;
	a = 0;
	b = 0;
	c = 0;
	for (b = 0; b < col; b++)
	{
		for (a = 0; a < row; a++)
		{
			if (arr[a][b] == 'O')
				c++;
			else
				c = 0;
			if (c == row)
			{
				flag = 1;
				return flag;
			}
		}
		c = 0;
	}
	c = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
		{
			if (arr[a][b] == 'O')
				c++;
			else
				c = 0;
			if (c == col)
			{
				flag = 1;
				return flag;
			}
		}
		c = 0;
	}
	b = 0;
	c = 0;
	for (a = 0; a < row; a++)
	{
		if (arr[a][b] == 'O')
			c++;
		else
			c = 0;
		b++;
		if (c == col)
		{
			flag = 1;
			return flag;
		}
	}
	b = col - 1;
	c = 0;
	for (a = 0; a < row; a++)
	{
		if (arr[a][b] == 'O')
			c++;
		else
			c = 0;
		b--;
		if (c == row)
		{
			flag = 1;
			return flag;
		}
	}
	return 0;
}
void filesave(char arr[][10], int row, int col)
{
	char ch = ' ';
	ofstream fout;
	fout.open("tictac.txt");
	int i, j;
	fout << row;
	fout << endl;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			fout << arr[i][j];
		}
		fout << endl;
		fout << endl;
	}
	fout.close();

}
int fileload(char arr[][10], int &row, int &col)
{
	char ch;
	int t = 0;
	ifstream fin;
	fin.open("tictac.txt");
	int i, j;
	fin >> row;
	col = row;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			fin >> ch;
			arr[i][j] = ch;
			if (ch == 'X' || ch == 'O')
				t++;
		}
	}
	fin.close();
	return t;
}