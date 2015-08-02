// Rotates a nxn matrix 90 deg anti-clockwise

#include <iostream>
#define N 4
using namespace std;

void RotateMatrix(int a[][N], int n)
{
	for (int layer = 0; layer < n / 2; layer++)
	{
		for (int pos = layer; pos < n - layer - 1; pos++)
		{
			int l1 = layer;
			int p1 = pos;
			int temp2 = a[l1][p1];
			for (int k = 0; k < 4; k++)
			{
				int l2 = n - 1 - p1;
				int p2 = l1;
				int temp1 = a[l2][p2];
				a[l2][p2] = temp2;
				temp2 = temp1;
				l1 = l2;
				p1 = p2;
			}
		}
	}
}

int main()
{
	int n = N;
	int a[N][N] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	RotateMatrix(a, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

