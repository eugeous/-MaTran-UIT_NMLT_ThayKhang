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
void Nhap(float[][500], int&, int&, string);
void Xuat(float[][500], int, int, string);
void Xuat(float[][500], int, int);
float TichDong(float[][500], int, int, int);
void ThemCot(float[][500], int, int&);

int main()
{
	float b[500][500];
	int k;
	int l;


	for (int i = 1; i <= 1; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(b, k, l, FileName);

		cout << "\n" << FileName << endl;
		Xuat(b, k, l);

		ThemCot(b, k, l);
		cout << "\n Mang sau khi them: ";
		cout << '\n';
		cout << setw(8) << setprecision(5);
		Xuat(b, k, l);
		FileName = getOutputFileName(i);
		Xuat(b, k, l, FileName);
	}
	return 1;
}

void Xuat(float a[][500], int m, int n)
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


void Nhap(float a[][500], int& m, int& n, string filename)
{
	ifstream fi(filename);
	fi >> m;
	fi >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][500], int m, int n, string filename)
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

float TichDong(float a[][500], int m, int n, int d)
{
	float sum_d = 1;
	for (int j = 0; j < n - 1; j++)
		sum_d *= a[d][j];
	return sum_d;
}

void ThemCot(float a[][500], int m, int& n)
{
	n = n + 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = n - 1; j <= n - 1; j++)
		{
			a[i][j] = TichDong(a, m, n, i);
		}
	}
}