#include <iostream>
using namespace std;



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

void InitMatrixFromFile(char* fileName)
{

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
		}
		break;
		case BAITAP4:
		{
			system("cls");
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