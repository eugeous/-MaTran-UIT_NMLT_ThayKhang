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
void Nhap(int[][100], int&, int&, string);
void Xuat(int[][100], int, int, string);
void Xuat(int[][100], int, int);
void XoaDong(int[][100], int&, int, int);
int ktDong(int[][100], int, int, int);
void XoaDong(int[][100], int&, int);


int main()
{
	int b[100][100];
	int k;
	int l;

	for (int i = 1; i <= 13; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(b, k, l, FileName);

		cout << "\n" << FileName << endl;
		Xuat(b, k, l);
		cout << '\n' << '\n';
		XoaDong(b, k, l);
		cout << "\nMang sau khi xoa dong co so toan le la: ";
		Xuat(b, k, l);

		FileName = getOutputFileName(i);
		Xuat(b, k, l, FileName);
	}
	return 1;
}

void Xuat(int a[][100], int m, int n)
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
	string fileName = string("intmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".inp";
	else
		fileName += to_string(n) + ".inp";
	return fileName;
}

string getOutputFileName(int n)
{
	string fileName = string("intmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".out";
	else
		fileName += to_string(n) + ".out";
	return fileName;
}


void Nhap(int a[][100], int& m, int& n, string filename)
{
	ifstream fi(filename);
	fi >> m;
	fi >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(int a[][100], int m, int n, string filename)
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

void XoaDong(int a[][100], int& m, int n, int d)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = d; i <= m - 2; i++)
			a[i][j] = a[i + 1][j];
	}
	m--;

}

int ktDong(int a[][100], int m, int n, int d)
{
	int flag1 = 0;
	for (int j = 0; j < n; j++)
	{
		if (a[d][j] < 0)
			flag1 = 1;
	}
	return flag1;
}

void XoaDong(int a[][100], int& m, int n)
{
	for (int i = m - 1; i >= 0; i--)
		if (ktDong(a, m, n, i))
			XoaDong(a, m, n, i);
}