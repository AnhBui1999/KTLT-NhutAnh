/*Tác giả: Nhựt Anh
phan công: viết hàm sách*/
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <sstream>
#include <iomanip>
#include "Admin.h"
#include "GiaoVien.h"
#include "SinhVien.h"
#include "PhieuMuon.h"
#include "Sach.h"
using namespace std;
int PhieuMuon::nTongPM = 0;
// nguyen mau ham con : 

bool kiemTraSach_DuTieuChuanMuon(list <Sach> L3, string sMS);
void inputData_Sach(list <Sach> &L3);
void outputData_Sach_ToScreen(list <Sach> L3);
void outputData_Sach_File(list <Sach> L3);
int dem_Tong_So_Sach_Hien_Co(list <Sach> L3);
void themSach(list <Sach> &L3);
void xoaSach(list <Sach> &L3);
void timKiem(list <Sach> L3);
int nDemSachChuaMuon(list <Sach> L3);
int nDemSachDaMuon(list <Sach> L3);
// dinh nghia ham con:
int nDemSachDaMuon(list <Sach> L3)
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
		if (p->getTinhTrang() != 0)
		{
			nDem++;
		}
		p++;
	}
	return nDem;
}
int nDemSachChuaMuon(list <Sach> L3)
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
		if (p->getTinhTrang() == 0)
		{
			nDem++;
		}
		p++;
	}
	return nDem;
}
void timKiem(list <Sach> L3)
{
	int flag = 0;
	textColor(4);
	
	cout << "\t\tNhap N de thoat!\n";
	textColor(7);
	string sTimKiem = "";
	dd:
	cout << "\t\tNhap ma sach can tim: ";
	fflush(stdin);
	getline(cin, sTimKiem);
	if (sTimKiem == "N")
	{
		textColor(10);
		cout << "\t\tBan da chon thoat! \n";
		textColor(7);
	}
	else 
	{
		list <Sach>::iterator p = L3.begin();
		while(p != L3.end())
		{
			if (sTimKiem == p->getMS())
			{
				flag = 0;
				cout << "\n\t\tTHONG TIN SACH\n";
				p->outputSach();
				cout << "*********************************************\n";
				break;
			}
			else
			{
				flag = 1;
			}
			p++;
		}
		if (flag == 1)
		{
			textColor(4);
			cout << "\t\tMa sach khong ton tai !\n";
			textColor(7);
			goto dd;
		}
	}

}
void xoaSach(list <Sach> &L3)
{
	cout << "\t\tNhap N de thoat! \n";
	string sSachCanXoa = "";
	dd:
	fflush(stdin);
	cout << "\t\tNhap ma so sach can xoa: ";
	getline(cin, sSachCanXoa);
	if (sSachCanXoa == "N")
	{
		textColor(10);
		cout << "\t\tBan da chon thoat! \n";
		textColor(7);
	}
	else 
	{
		int flag = 0;
		list <Sach>::iterator p = L3.begin();
		while(p != L3.end())
		{
			if (sSachCanXoa == p->getMS() && p->getTinhTrang() == 0)
			{
				flag = 0;
				textColor(10);
				cout << "\t\t\tXoa sach thanh cong!";
				textColor(7);
				L3.erase(p);
				outputData_Sach_File(L3);
				break;
			}
			else
			{
				flag = 1;
			}
			p++;
		}
		if (flag == 1)
		{
			textColor(4);
			cout << "\t\tMa so sach khong ton tai, hoac sach dang duoc muon!\n";
			textColor(7);
			goto dd;
		}
	}

}
void themSach(list <Sach> &L3)
{
	string sMS = "";
	string sTD = "";
	string sTG = "";
	string sNXB = "";
	float fTriGia = NULL;
	int nNPH = 0;
	int nST = 0;
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	int nTT = 0;
	dd:
	cout << "\t\tNhap ma so sach: ";
	fflush(stdin);
	getline(cin, sMS);
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
	
		if (sMS == p->getMS() || sMS == "")
		{
			textColor(4);
			cout << "\t\t\tMa so sach da ton tai hoac chua nhap ma so sach !!!\n";
			textColor(7);
			system("pause");
			goto dd;
		}
		p++;
	}
	td:
	cout << "\t\tNhap tua de sach: ";
	fflush(stdin);
	getline(cin, sTD);
	if (sTD == "")
	{
		textColor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		textColor(7);
		goto td;
	}
	tg:
	cout << "\t\tNhap ten tac gia: ";
	fflush(stdin);
	getline(cin, sTG);
		if (sTG == "")
	{
		textColor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		textColor(7);
		goto tg;
	}
	nxb:
	cout << "\t\tNhap nha xuat ban: ";
	fflush(stdin);
	getline(cin, sNXB);
	if (sNXB == "")
	{
		textColor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		textColor(7);
		goto nxb;
	}
	cout << "\t\tNhap gia cuon sach: ";
	cin >> fTriGia;
	cout << "\t\tNhap nam phat hanh: ";
	cin >> nNPH;
	cout << "\t\tNhap so trang: ";
	cin >> nST;
	cout << "\t\tNgay nhap kho: ";
	cout << "\n\t\t\t\tNhap ngay: ";
	cin >> nNgay;
	cout << "\t\t\t\tNhap thang: ";
	cin >> nThang;
	cout << "\t\t\t\tNhap nam: ";
	cin >> nNam;
	nTT = 0;
	Sach s(sMS, sTD, sTG, sNXB, fTriGia, nNPH, nST, nNgay, nThang, nNam, nTT);
	L3.push_back(s);
	textColor(10);
	cout << "\t\tthem sach thanh cong !\n";
	textColor(7);
}
void outputData_Sach_File(list <Sach> L3)
{
	ofstream File;
	File.open("Sach.txt");
	int nDem = 1;
	int nTongSoSach = dem_Tong_So_Sach_Hien_Co(L3);
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
		File << p->getMS() << "," << p->getTD() << "," << p->getTG() << "," << p->getNXB() << "," << p->getGia() << "," << p->getNPH() << "," << p->getST() << "," << p->getNgayNK() << "," << p->getThangNK() << "," << p->getNamNK() << "," << p->getTinhTrang();		
		if (nDem < nTongSoSach)
		{
			File << endl;
			nDem++;
		}	
		p++;
	}
	File.close();
}
void outputData_Sach_ToScreen(list <Sach> L3)
{
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		p->outputSach();
		p++;
	}
}
void inputData_Sach(list <Sach> &L3)
{
	string sMS = "";
	string sTD = "";
	string sTG = "";
	string sNXB = "";
	float fTriGia = 0.0;
	int nNPH = 0;
	int nST = 0;
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	int nTT = 0;
	ifstream File;
	File.open("Sach.txt");
	while(!File.eof())
	{
		getline(File, sMS, ',');
		getline(File, sTD, ',');
		getline(File, sTG, ',');
		getline(File, sNXB, ',');
		File >> fTriGia;
		File.ignore(1, ',');
		File >> nNPH;
		File.ignore(1, ',');
		File >> nST;
		File.ignore(1, ',');
		File >> nNgay;
		File.ignore(1, ',');
		File >> nThang;
		File.ignore(1, ',');
		File >> nNam;
		File.ignore(1, ',');
		File >> nTT;
		File.ignore(1, '\n');
		Sach s(sMS, sTD, sTG, sNXB, fTriGia, nNPH, nST, nNgay, nThang, nNam, nTT);
		L3.push_back(s);
	}
	File.close();
}
int dem_Tong_So_Sach_Hien_Co(list <Sach> L3)
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		nDem++;
		p++;
	}
	return nDem;
}
bool kiemTraSach_DuTieuChuanMuon(list <Sach> L3, string sMS)
{
	list <Sach> ::iterator p = L3.begin();
	while(p != L3.end())
	{
		if(sMS == p->getMS() && p->getTinhTrang() == 0)
		{
			return true;
		}
		p++;
	}
	return false;
}