#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
// bai1
class Nhat
{
private:
	vector<int> v;// khai báo vector để chứa phần tử
	vector<int>::iterator x;
public:
	void input()
	{
		ifstream fi;//khai báo kiểu fi để đọc file
		int s;
		fi.open("E://data.txt");// mở file data.txt
		if (fi.is_open())// mở file
		{
			while (fi >> s)// vòng lặp nhập phân tử
			{
             // doc tung phan tu trong file vao vector
			v.push_back(s);
			}
			fi.close();
		}
		// in phần tử trong vec
		for (x = v.begin(); x != v.end(); x++)
		{
			cout << *x << "\t";
		}
	}
	bool ktrsnt(int n)
	{
		int dem = 0;
		if (n > 1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (n % i == 0)
				{
					dem++;
				}
			}
		}
		if (dem == 2)
		{
			return true;
		}
		return false;
	}
	void output()
	{
		ofstream of;
		of.open("E://output.txt");
		sort(v.begin(), v.end()); // sap sep tang theo thuat toan co san
		if (of.is_open())
		{
			// sap sep
			int sumchan = 0;
			int sumle = 0;
			of << "Sap sep tang: ";
			for (x = v.begin(); x != v.end(); x++)
			{
				of << *x << " ";
			}
			// tinh tong chan va le
			for (x = v.begin(); x != v.end(); x++)
			{
				if (*x % 2 == 0)
				{
					sumchan += *x;
				}
				else
				{
					sumle += *x;
				}
			}
			// in tong chan va le
			of << "\nTong chan la: " << sumchan << endl;;
			of << "Tong le la: " << sumle << endl;
			// so nguyen to
			of << "So nguyen to la: ";
			for (x = v.begin(); x != v.end(); x++)
			{
				if (ktrsnt(*x) == true)
				{
					of << *x << " ";
				}
			}
			of.close();
		}
		else
		{
			cout << "Don't have file! ";
		}
	}
};
// bai2
template<typename T>
void nhap(T& a, int& n)
{
	cout << "\nNhap" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i << " : ";
		cin >> a[i];
	}
}
template<typename T>
void xuat(T a, int n)
{
	cout << "\nXuat" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu thu " << i << " : ";
		cout << a[i] << " ";
	}
}
template<typename T>
void sapsep(T a, int n)
{
	cout << "\nSapSep" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
// bai 3
class Person
{
private:
	int  id;
	string name;
public:
	// phuong thuc ao
	virtual void input()
	{
		cout << "Nhap id: ";
		cin >> id;
		cin.ignore();
		cout << "Nhap name: ";
		getline(cin, name);
	}
	// phuong thuc ao
	virtual void output()
	{
		cout << "ID: " << id << " , NAME: " << name;
	}
	// phuong thuc thuan ao
	virtual float calculateBonus() = 0;
};
class Student : public Person
{
private:
	int studID;
	float avgMark;
public:
	void input()
	{
		Person::input();
		cout << "Nhap studID: ";
		cin >> this->studID;
		cout << "Nhap avgMark: ";
		cin >> this->avgMark;
	}
	void output()
	{
		Person::output();
		cout << " , STUDENT_ID: " << studID << " , AVGMARK: " << avgMark;
	}
	float calculateBonus()
	{
		if (avgMark > 8.0)
		{
			return 750.000;
		}
		else
		{
			return 0;
		}
	}
};
class Lecturer : public Person
{
private:
	int empID;
	float numberOfPapers;

public:
	void input()
	{
		Person::input();
		cout << "Enter employee ID: ";
		cin >> empID;
		cout << "Enter number of papers: ";
		cin >> numberOfPapers;
	}

	void output()
	{
		Person::output();
		cout << " , EMPLOYEE ID: " << empID << " , NUMBER OF PAPERS: " << numberOfPapers ;
	}

	float calculateBonus()
	{
		if (numberOfPapers > 3)
		{
			return 150.000;
		}
		else
		{
			return 0;
		}
	}
};
class ListOfPerSon
{
private:
	Person* ds[100];
	int n;
public:
	void nhap()
	{
		cout << "Nhap so luong nguoi de nhap: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int choice;
			cout << "1.Student&&2.Lecturer&&3.Exit and output" << endl;
			cin >> choice;
			if (choice == 1)
			{
				ds[i] = new Student();
			}
			else if (choice == 2)
			{
				ds[i] = new Lecturer;
			}
			else if (choice == 3)
			{
				break;
			}
			else
			{
				cout << "Not found!!!";
			}
			ds[i]->input();
		}
	}
	void xuat()
	{
		for (int i = 0; i < n; i++)
		{
			ds[i]->output();
			cout << " Bonus: " << setprecision(3) << ds[i]->calculateBonus() << endl;
		}
	}
	void sapsep()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (ds[i]->calculateBonus() < ds[j]->calculateBonus())
				{
					swap(ds[i], ds[j]);
				}
			}
		}
	}
	void clearmemory()
	{
		for (int i = 0; i < n; i++)
		{
			delete ds[i];
		}
	}
};
int main()
{
	int chon;
	cout << "1.ChayBai_1//2.ChayBai_2//3.ChayBai3//4.Exit " << endl;
	cout << "Chon 1||2||3||4: ";
	cin >> chon;
	switch (chon)
	{
	case 1:
	{
		Nhat lmao;
		lmao.input();
		lmao.output();
		cout << "Please open folder in drive E and name folder is DATA and OUTPUT ";
		break;
	}
	case 2:
	{
		int size;
		cout << "Nhap so luong phan tu: ";
		cin >> size;
		int* arr = new int[size];
		nhap(arr, size);
		xuat(arr, size);
		sapsep(arr, size);
		xuat(arr, size);
		delete[] arr;
		break;
	}
	case 3: {
		ListOfPerSon a;
		a.nhap();
		a.xuat();
		a.sapsep();
		cout << "\nSAU KHI SAP SEP GIAM DAN" << endl;
		a.xuat();
		a.clearmemory();
		break;
	}
	case 4: {
		exit(0);
		break;
	}
	default:
		cout << "Please enter 1 or 2 or 3" << endl;
		break;
	}
	return 0;
}
