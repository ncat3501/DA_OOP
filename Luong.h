#pragma once

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class Date {
private:
	int year;
	int month;
public:
	Date();
	Date(int year, int month);

	int getYear();
	void setYear(int year);
	int getMonth();
	void setMonth(int month);

	friend ostream& operator<<(ostream& out, Date& date);
	Date& operator=(const Date& date);

	bool isEqual(Date& d);
	void sangThang();
};

class SoTietKiem;

class ThuNhap {
private:
	// input
	double luongVo;
	double luongChong;
	double luongChung;
	double chiTieu;
	// data
	double quyVoChong = 0;
	double quyChung = 0;
	Date date;

	// singleton
	ThuNhap();
	static ThuNhap* _thuNhap;

public:
	// constructors
	~ThuNhap();

	static ThuNhap* getInstance();
	ThuNhap& operator=(const ThuNhap& thuNhap) = delete;


	// getter setter
	double getLuongVo();
	void setLuongVo(double luongVo);
	double getLuongChong();
	void setLuongChong(double luongChong);
	double getLuongChung();
	void setLuongChung(double luongChung);
	double getChiTieu();
	void setChiTieu(double chiTieu);

	double getQuyVoChong();
	void setQuyVoChong(double quyVoChong);
	double getQuyChung();
	void setQuyChung(double quyChung);
	Date getDate();
	void setDate(Date& date);


	// operators overloading
	friend ostream& operator<<(ostream& out, ThuNhap& thuNhap);
	friend istream& operator>>(istream& in, ThuNhap& thuNhap);

	// methods
	void guiTietKiem();
	void guiNoNganHang();
	void sangThangTiepTheo();

	void Menu();
};


class SoTietKiem {
private:
	static double tienGui;
	static double laiSuat;
	static Date ngayGui;
	static Date ngayDaoHan;
	static int soluong;
	int stt;
public:
	SoTietKiem();

	double getTienGui();
	void setTienGui(double tienGui);
	double getLaiSuat();
	void setLaiSuat(double laiSuat);
	Date getNgayGui();
	void setNgayGui(Date& ngayGui);
	Date getNgayDaoHan();
	void setNgayDaoHan(Date& ngayDaoHan);

	friend ostream& operator<<(ostream& out, const SoTietKiem& s);

	static SoTietKiem* chon(ThuNhap& thuNhap);
	void checkDaoHan(ThuNhap& thuNhap);

};

class TienNo {
private:
	static double tienNo;
	static double laiSuat;
	static Date ngayGui;
	static Date ngayDaoHan;
	static int soluong;
	int stt;
public:
	TienNo();

	double getTienNo();
	void setTienNo(double tienNo);
	double getLaiSuat();
	void setLaiSuat(double laiSuat);
	Date getNgayGui();
	void setNgayGui(Date& ngayGui);
	Date getNgayDaoHan();
	void setNgayDaoHan(Date& ngayDaoHan);

	friend ostream& operator<<(ostream& out, const TienNo& n);

	static TienNo* chon(ThuNhap& thuNhap);
	void checkDaoHan(ThuNhap& thuNhap);
	void thayLaiSuat(int stt);

};