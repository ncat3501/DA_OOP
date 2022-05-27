#include "Luong.h"

vector<SoTietKiem*> stk;


ostream& operator<<(ostream& out, Date& date)
{
	out << date.month << "/" << date.year;

	return out;
}

ostream& operator<<(ostream& out, ThuNhap& thuNhap)
{
	out << "====================" << endl;
	out << "===== Thu Nhap =====" << endl;
	out << "==== Quy ====" << endl;
	out << "	Quy vo chong: " << thuNhap.getQuyVoChong() << endl;
	out << "	Quy chung: " << thuNhap.getQuyChung() << endl;
	out << "== Thu: " << endl;
	out << "	Luong vo: " << thuNhap.getLuongVo() << endl;
	out << "	Luong chong: " << thuNhap.getLuongChong() << endl;
	out << "	Luong chung: " << thuNhap.getLuongChung() << endl;
	out << "=== Chi:" << endl;
	out << "	Chi tieu: " << thuNhap.getChiTieu() << endl;
	out << "====================" << endl;

	return out;
}

istream& operator>>(istream& in, ThuNhap& thuNhap)
{
	cout << "Nhap tien luong vo: ";
	double tv;
	in >> tv;
	thuNhap.setLuongVo(tv);
	
	cout << "Nhap tien luong chong: ";
	double tc;
	in >> tc;
	thuNhap.setLuongChong(tc);

	cout << "Nhap tien luong chung: ";
	double tch;
	in >> tch;
	thuNhap.setLuongChung(tch);

	cout << "Nhap chi tieu: ";
	double ct;
	in >> ct;
	thuNhap.setChiTieu(ct);

	return in;
}



// Date class
void Date::sangThang()
{
	month++;
	if (month == 13) {
		year++;
		month = 1;
	}
}

bool Date::isEqual(Date& d)
{
	if (this->month == d.month && this->year == d.year)
		return true;
	return false;
}

Date& Date::operator=(const Date& date)
{
	this->month = date.month;
	this->year = date.year;

	return *this;
}

int Date::getYear()
{
	return this->year;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getMonth()
{
	return this->month;
}

void Date::setMonth(int month)
{
	this->month = month;
}

Date::Date()
{
	this->month = 1;
	this->year = 2022;
}

Date::Date(int year, int month)
{
	this->year = 2022;
	this->month = 1;
	// check year
	if (year <= 2000 || year > 2022) {
		cout << "Invalid year" << endl;
	}
	else {
		this->year = year;
	}
	// check month
	if (month <= 0 || month > 12) {
		cout << "Invalid month" << endl;
	}
	else
		this->month = month;
}

double SoTietKiem::tienGui = 0;
double SoTietKiem::laiSuat = 0;
Date SoTietKiem::ngayDaoHan;
SoTietKiem* SoTietKiem::chon(ThuNhap& thuNhap)
{
	SoTietKiem* s = new SoTietKiem;
	cout << "Ban dang co: " << thuNhap.getQuyVoChong() << endl;
	cout << "Ban muon gui bao nhieu tien? Hay nhap: ";
	cin >> s->tienGui;

	while (s->tienGui > thuNhap.getQuyVoChong()) {
		cout << "So tien khong hop le. Hay nhap lai: ";
		cin >> s->tienGui;
	}
	thuNhap.setQuyVoChong(thuNhap.getQuyVoChong() - s->tienGui);

	s->ngayDaoHan = thuNhap.getDate();

	int choose;
	cout << "Chon 6 thang hay 1 nam?" << endl;
	cout << "	1. 6 thang\n	2. 1 nam" << endl;
	cout << "Hay nhap: ";
	cin >> choose;

	while (choose != 1 && choose != 2) {
		cout << "Lua chon khong hop le. Hay nhap lai: ";
		cin >> choose;
	}

	switch (choose)
	{
	case 1:
		// gui 6 thang, lai suat 6%/nam ~= 0.4867%/thang
		s->laiSuat = 0.4867;

		for (int i = 0; i < 5; i++) {
			s->ngayDaoHan.sangThang();
			s->tienGui *= (1 + s->laiSuat / 100);
		}
		break;
	case 2:
		// gui 1 nam, lai suat 6.6%/nam ~= 0.5340%/thang
		s->laiSuat = 0.5340;
		for (int i = 0; i < 11; i++) {
			s->ngayDaoHan.sangThang();
			s->tienGui *= (1 + s->laiSuat / 100);
		}
		break;
	default:
		break;
	}

	return s;

}

void SoTietKiem::checkDaoHan(ThuNhap& thuNhap)
{
	if (thuNhap.getDate().isEqual(ngayDaoHan))
		thuNhap.setQuyVoChong(thuNhap.getQuyVoChong() + tienGui);
}

SoTietKiem::SoTietKiem()
{
}

double SoTietKiem::getTienGui() {
	return this->tienGui;
}

void SoTietKiem::setTienGui(double tienGui) {
	this->tienGui = tienGui;
}

double SoTietKiem::getLaiSuat() {
	return this->laiSuat;
}

void SoTietKiem::setLaiSuat(double laiSuat) {
	this->laiSuat = laiSuat;
}

Date SoTietKiem::getNgayDaoHan() {
	return ngayDaoHan;
}

void SoTietKiem::setNgayDaoHan(Date& ngayDaoHan) {
	this->ngayDaoHan = ngayDaoHan;
}

ostream& operator<<(ostream& out, const SoTietKiem& s) {
	out << "STK" << endl;
	out << "Tien gui: " << s.tienGui << endl;
	out << "Lai suat: " << s.laiSuat << endl;
	out << "Ngay dao han: " << s.ngayDaoHan << endl;

	return out;
}

void SoTietKiem::print() {
	cout << "STK" << endl;
	cout << "Tien gui: " << this->tienGui << endl;
	cout << "Lai suat: " << this->laiSuat << endl;
	cout << "Ngay dao han: " << this->ngayDaoHan << endl;

}



// ThuNhap class
ThuNhap* ThuNhap::_thuNhap = 0;
ThuNhap::ThuNhap()
{
	luongVo = 0;
	luongChong = 0;
	luongChung = 0;
	chiTieu = 0;
}


ThuNhap::~ThuNhap()
{
}

ThuNhap* ThuNhap::getInstance()
{
	if (_thuNhap == nullptr) {
		_thuNhap = new ThuNhap();
	}

	return _thuNhap;
}

double ThuNhap::getLuongVo()
{
	return this->luongVo;
}

void ThuNhap::setLuongVo(double luongVo)
{
	this->luongVo = luongVo;
}

double ThuNhap::getLuongChong()
{
	return this->luongChong;
}

void ThuNhap::setLuongChong(double luongChong)
{
	this->luongChong = luongChong;
}

double ThuNhap::getLuongChung()
{
	return this->luongChung;
}

void ThuNhap::setLuongChung(double luongChung)
{
	this->luongChung = luongChung;
}

double ThuNhap::getChiTieu()
{
	return this->chiTieu;
}

void ThuNhap::setChiTieu(double chiTieu)
{
	this->chiTieu = chiTieu;
}

double ThuNhap::getQuyVoChong()
{
	return this->quyVoChong;
}

void ThuNhap::setQuyVoChong(double quyVoChong)
{
	this->quyVoChong = quyVoChong;
}

double ThuNhap::getQuyChung()
{
	return this->quyChung;
}

void ThuNhap::setQuyChung(double quyChung)
{
	this->quyChung = quyChung;
}


void ThuNhap::guiTietKiem()
{
	cout << "gui tiet kiem" << endl;
	SoTietKiem* s = new SoTietKiem;
	s->chon(*this);
	//this->add(s);
	stk.push_back(s);
}

void ThuNhap::sangThangTiepTheo()
{
	quyVoChong += luongVo + luongChong;
	quyChung += luongChung;

	if (quyChung >= chiTieu) 
	{
		quyChung -= chiTieu;
	}
	else 
	{
		luongChung = 0;
		quyVoChong -= chiTieu - quyChung;
	}

	date.sangThang();
	if (stk.size() > 0) {
		for (int i = 0; i < stk.size(); i++) {
			stk[i]->checkDaoHan(*this);
		}
	}

	cout << "Da sang thang tiep theo." << endl;

}

Date ThuNhap::getDate()
{
	return Date(this->date.getYear(), this->date.getMonth());
}

void ThuNhap::Menu()
{
	int choose = -1;
	do {
		cout << "1. In ra thunhap" << endl;
		cout << "2. Gui tiet kiem" << endl;
		cout << "3. Sang thang" << endl;
		cout << "4. Thay doi luong" << endl;
		cout << "5. In ra STK" << endl;
		cout << "6. Ket thuc" << endl;
		cout << "Nhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "In ra thu nhap" << endl;
			cout << *this;
			break;
		case 2:
			cout << "Gui tiet kiem" << endl;
			this->guiTietKiem();
			break;
		case 3:
			cout << "Sang thang" << endl;
			this->sangThangTiepTheo();
			break;
		case 4:
			cout << "Thay doi luong" << endl;
			cin >> *this;
			break;
		case 5:
			for (int i = 0; i < stk.size(); i++) {
				stk[i]->print();
			}
			break;
		case 6:
			break;
		default:
			break;
		}
	}
	while (choose != 6);

}

void ThuNhap::setDate(Date& date)
{
	this->date.setYear(date.getYear());
	this->date.setMonth(date.getMonth());
}

