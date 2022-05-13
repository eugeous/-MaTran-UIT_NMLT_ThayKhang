#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string getInputFileName(int);
string getOutputFileName(int);
void Nhap(float[][100], int&, int&, string);
void Xuat(float[][100], int, int, string);
void Xuat(float[][100], int, int);
void ThemCot(float a[][100], int, int&, int);
void ThemCot(float[][100], int&, int);
float LonNhatDong(float[][100], int, int);

int main()
{
	float b[100][100];
	int k;
	int l;


	for (int i = 1; i <= 13; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(b, k, l, FileName);

		cout << "\n" << FileName << endl;
		Xuat(b, k, l);
		cout << '\n' << '\n';
		ThemCot(b, k, l);
		cout << "\nMang sau khi them  cot max vao cuoi la: ";
		Xuat(b, k, l);

		FileName = getOutputFileName(i);
		Xuat(b, k, l, FileName);
	}
	return 1;
}

void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(3);
			cout << a[i][j];
		}
		cout << "\n";
	}
}

string getInputFileName(int n)
{
	string fileName = string("floatmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".inp";
	else
		fileName += to_string(n) + ".inp";
	return fileName;
}

string getOutputFileName(int n)
{
	string fileName = string("floatmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".out";
	else
		fileName += to_string(n) + ".out";
	return fileName;
}


void Nhap(float a[][100], int& m, int& n, string filename)
{
	ifstream fi(filename);
	fi >> m;
	fi >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][100], int m, int n, string filename)
{
	ofstream fo(filename);
	fo << setw(8) << n;
	fo << setw(8) << m;
	fo << "\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fo << setw(8) << a[i][j];
		fo << "\n";
	}
}

float LonNhatDong(float a[][100], int m, int n)
{
	int i = 0;
	float max = a[i][0];
	for (int j = 0; j <= n; j++)
		for (; i < n; i++)
			if (a[i][j] > max)
				a[i][j] = max;
	return max;
}

void ThemCot(float a[][100], int m, int& n, int c)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = n; j >= c + 1; j--)
			a[i][j] = a[i][j - 1];
		a[i][c] = 0;
	}
	n++;
}

void ThemCot(float a[][100], int& m, int n)
{
	for (int i = 0; i <= m; i++)
		for (int j = 0; j < n; j++)
			if (LonNhatDong(a, m, n))
				ThemCot(a, m, n, i);

}
