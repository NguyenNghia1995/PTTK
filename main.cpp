#include <iostream>
using namespace std;

#include <fstream>
#define FILENAME "Graph.txt"
#define null NULL
#define NEIGHBOR 1

//Bai 1:

enum BaiTap
{
	BAITAP1 = 1,
	BAITAP2 = 2,
	BAITAP3 = 3,
	BAITAP4 = 4,
	EXIT = 8
};

void PrintOutput(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << "\n";
}

void Ex1(int i, int n, int *a, int &number)
{
	for (int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if (i < n - 1)
			Ex1(i + 1, n, a, number);
		else
		{
			number++;
			PrintOutput(a, n);
		}
	}
}

void InitCheck(bool *check, int n)
{
	for (int i = 0; i < n; i++)
	{
		check[i] = false;
	}
}

void Ex2(int i, int n, int *a, bool *check, int &count)
{
	for (int j = 1; j <= n; j++)
	{
		if (!check[j - 1])
		{
			a[i] = j;
			check[j - 1] = true;
		}
		else
			continue;

		if (i < n - 1)
		{
			Ex2(i + 1, n, a, check, count);
		}

		else
		{
			PrintOutput(a, n);
			count++;
		}
		check[j - 1] = false;
	}
}

void PrintMatrix(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void InitMatrixFromFile(int **&a, int &n, char* fileName)
{
	fstream f;
	int v1, v2;
	f.open(fileName, std::ios::in);
	if (!f.is_open())
		cout << "Khong the mo file" << endl;
	else
	{
		f >> n;
		a = new int*[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = new int[n];
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					a[i][j] = 1;
				else
				a[i][j] = 0;
			}
		}
		
		while (!f.eof())
		{
			f >> v1;
			f >> v2;
			a[v1 - 1][v2 - 1] = a[v2 - 1][v1 - 1] = 1;
		}
	}

	
}

void Ex4(int source, int destination, int **a, int n, bool *check)
{
	for (int j = 1; j <= n; j++)
	{
		if (a[source - 1][j - 1] == NEIGHBOR && check[j-1] == false)
		{
			if ()
		}
	}
}

void PrintOutput(bool *s, int n, int *a)
{
	cout << "(";
	for (int i = 0; i < n; i++)
	{
		if (s[i] == true)
			cout << a[i] << ", ";
	}
	cout << "\t)" << endl;
}

void Ex3(int i, int &sum, bool *s, int M, int *a, int n)
{
	for (int j = i; j < n; j++) //khả năng có thể chọn
	{
		s[i] = true;
		sum += a[i];	//tính sum tạm thời
		if (sum > M)
		{
			s[i] = false;
		}
		if (sum < M)
			Ex3(i + 1, sum, s, M, a, n);
		else
			if (sum == M)
				PrintOutput(s, n, a);

		s[i] = false;

	}
}

void Menu()
{
	
	while (true)
	{
		cout << "PHAN TICH-THIET KE THUAT TOAN" << endl;
		cout << "1. Bai tap 1" << endl;
		cout << "2. Bai tap 2" << endl;
		cout << "3. Bai tap 3" << endl;
		cout << "4. Bai tap 4" << endl;
		cout << "Ban muon gia bai tap nao, 1 hay 2 hay 3 hay 4" << endl;
		cout << "Nhap so 1 de giai bai 1" << endl;
		cout << "Nhap so 2 de giai bai 2" << endl;
		cout << "Nhap so 3 de giai bai 3" << endl;
		cout << "Nhap so 4 de giai bai 4" << endl;
		cout << "Nhan phim 8 de THOAT khoi chuong trinh" << endl;
		
		
		int baitap = 0;
		
		
		cin >> baitap;
		switch (baitap)
		{
		case BAITAP1:
		{
			system("cls");
			int n = 0; 
			cout << "Nhap n: = ";
			cin >> n;
			int count = 0;
			int *a = new int[n];
			Ex1(0, n, a, count);
			cout << count << "\n";
		}
		break;
		case BAITAP2:
		{
			system("cls");

			int n = 0;
			cout << "Nhap n: = ";
			cin >> n;
			int count = 0;
			int *a = new int[n];
			
			bool *check = new bool[n];
			InitCheck(check, n);
			Ex2(0, n, a, check, count);
			cout << count << "\n";
		}
		break;
		case BAITAP3:
		{
			system("cls");


			int sum = 0, n = 6, M = 11;
			//bool *s = new bool[n];
			//int *a = new int[n] = {1,2,3,3,5};
			int a[6] = { 7, 1, 4, 3, 5, 6 };
			bool s[6] = { false, false, false, false, false, false };

			Ex3(1, sum, s, M, a, n);
		}
		break;
		case BAITAP4:
		{
			system("cls");

			int **a = null;
			int n = 0;
			InitMatrixFromFile(a, n, FILENAME);
			PrintMatrix(a, n);
			bool *check = new bool[n];
			int source = 1;
			int destination = 6;
			Ex4(source, destination, a, n, check);
		}
		break;
		case EXIT:
		{
			return;
		}
		break;
		default:
		{
			cout << "Phim khong hop le" << endl;
		}
			break;
		}

		cout << "Nhan phim 5 de quay lai Menu" << endl;
		int back = 0;
		cin >> back;
		if (back == 5)
		{
			system("cls");
		}
	}
}

int main()
{
	Menu();
	return 0;
}