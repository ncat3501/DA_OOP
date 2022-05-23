#pragma once

#include <iostream>
using namespace std;


struct Date {
	int year;
};

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

	//// singleton
	//static ThuNhap* thuNhap;
	//ThuNhap();
	//ThuNhap& operator=(const ThuNhap& thuNhap);
public:
	// constructors
	ThuNhap();
	ThuNhap(double luongVo, double luongChong, double luongChung, double chiTieu);
	ThuNhap(const ThuNhap& thuNhap);
	~ThuNhap();

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

	// operators overloading
	friend ostream& operator<<(ostream& out, ThuNhap& thuNhap);
	friend istream& operator>>(istream& in, ThuNhap& thuNhap);

	// methods
	void guiTietKiem();
	void sangThangTiepTheo();

	static void Menu();
};


class SoTietKiem {
private:
	double tienGui;
public:
	static void choose(ThuNhap& tn);
};


class Menu {
public:
	static void Create();
};