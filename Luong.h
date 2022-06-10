#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::fstream;

// constant variables
const string _FILE_NAME = "data.csv";

// class declarations
class Date {
private:
	int year;
	int month;
public:
	// constructor
	Date();
	Date(int year, int month);

	// getter setter
	int getYear();
	void setYear(int value);
	int getMonth();
	void setMonth(int value);

	// operators overloading
	friend ostream& operator<<(ostream& out, Date& date);
	Date& operator=(const Date& date);

	// methods
	bool isEqual(Date& d);
	void getDateFromString(string& str);
	void sangThang();
};

class ThuNhap {
private:

	// INPUT 
		// salaries
	double luongVo;
	double luongChong;
	double luongChung;
		// costs
	double sinhHoat;
	double chiPhiKhac;
	// SAVINGS 
	double quyVoChong = 0;
	double quyChung = 0;

	Date* date;

	// SINGLETON
	ThuNhap();
	static ThuNhap* _thuNhap;

public:
	// DESTRUCTOR
	~ThuNhap();

	// SINGLETON INITIALIZE METHOD
	static ThuNhap* getInstance();
	ThuNhap& operator=(const ThuNhap& thuNhap) = delete;


	// GETTER & SETTER 
		// salaries
	double getLuongVo();
	void setLuongVo(double value);
	double getLuongChong();
	void setLuongChong(double value);
	double getLuongChung();
	void setLuongChung(double value);
	double getSinhHoat();
	void setSinhHoat(double value);
	double getChiPhiKhac();
	void setChiPhiKhac(double value);
		// savings
	double getQuyVoChong();
	void setQuyVoChong(double value);
	double getQuyChung();
	void setQuyChung(double value);

	Date* getDate();
	void setDate(Date& value);


	// OPERATORS OVERLOADING
	friend ostream& operator<<(ostream& out, ThuNhap& thuNhap);
	friend istream& operator>>(istream& in, ThuNhap& thuNhap);

	// METHODS
	void guiTietKiem();
	void guiNoNganHang();
	void sangThangTiepTheo();
	void printToCSV(fstream& file);
	void duDoanTraNo();
	void initializeColumnName(fstream& file);
	void readInputFromCSV(fstream& file);

	void Menu(fstream& file);
};

class SoTietKiem {
private:
	double tienGui = 0;
	double laiSuat = 0;
	Date* ngayGui;
	Date* ngayDaoHan;
	static int soluong;
	int stt;
public:
	// constructor destructor
	SoTietKiem();
	~SoTietKiem();

	// getter setter
	double getTienGui();
	void setTienGui(double value);
	double getLaiSuat();
	void setLaiSuat(double value);
	Date* getNgayGui();
	void setNgayGui(Date& value);
	Date* getNgayDaoHan();
	void setNgayDaoHan(Date& value);

	// operators overloading
	friend ostream& operator<<(ostream& out, const SoTietKiem& s);

	// methods
	SoTietKiem* chon(ThuNhap& thuNhap);
	void checkDaoHan(ThuNhap& thuNhap);

};

class TienNo {
private:
	double tienNo = 0;
	double laiSuat = 0;
	int due;
	Date* ngayGui;
	Date* ngayDaoHan;
	static int soluong;
	int stt;
public:
	// constructor
	TienNo();
	~TienNo();

	// getter setter
	double getTienNo();
	void setTienNo(double value);
	double getLaiSuat();
	void setLaiSuat(double value);
	int getDue();
	void setDue(int value);
	Date* getNgayGui();
	void setNgayGui(Date& value);
	Date* getNgayDaoHan();
	void setNgayDaoHan(Date& value);
	int getSTT();

	// operators overloading
	friend ostream& operator<<(ostream& out, const TienNo& n);

	// methods
	TienNo* chon(ThuNhap& thuNhap);
	void checkDaoHan(ThuNhap& thuNhap);
	void thayLaiSuat(int stt);

};