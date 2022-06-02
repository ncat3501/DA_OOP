#include "Luong.h"

// USED TO STORE SAVINGS AND DEBTS
vector<SoTietKiem*> stk;
vector<TienNo*> no;

// PRE-DEFINED VARIABLES
const int STARTING_MONTH = 5;
const int STARTING_YEAR = 2022;






// CLASS DATE
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

void Date::setYear(int value)
{
	this->year = value;
}

int Date::getMonth()
{
	return this->month;
}

void Date::setMonth(int value)
{
	this->month = value;
}

Date::Date()
{
	this->month = STARTING_MONTH;
	this->year = STARTING_YEAR;
}

Date::Date(int year, int month)
{
	this->year = STARTING_YEAR;
	this->month = STARTING_MONTH;
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

ostream& operator<<(ostream& out, Date& date)
{
	out << date.month << "/" << date.year;

	return out;
}


// CLASS THUNHAP
ThuNhap* ThuNhap::_thuNhap = 0;
ThuNhap::ThuNhap()
{
	luongVo = 0;
	luongChong = 0;
	luongChung = 0;
	sinhHoat = 0;
	chiPhiKhac = 0;
	date = new Date();
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

void ThuNhap::setLuongVo(double value)
{
	this->luongVo = value;
}

double ThuNhap::getLuongChong()
{
	return this->luongChong;
}

void ThuNhap::setLuongChong(double value)
{
	this->luongChong = value;
}

double ThuNhap::getLuongChung()
{
	return this->luongChung;
}

void ThuNhap::setLuongChung(double value)
{
	this->luongChung = value;
}

double ThuNhap::getSinhHoat()
{
	return this->sinhHoat;
}

void ThuNhap::setSinhHoat(double value)
{
	this->sinhHoat = value;
}

double ThuNhap::getChiPhiKhac()
{
	return this->chiPhiKhac;
}

void ThuNhap::setChiPhiKhac(double value)
{
	this->chiPhiKhac = value;
}

double ThuNhap::getQuyVoChong()
{
	return this->quyVoChong;
}

void ThuNhap::setQuyVoChong(double value)
{
	this->quyVoChong = value;
}

double ThuNhap::getQuyChung()
{
	return this->quyChung;
}

void ThuNhap::setQuyChung(double value)
{
	this->quyChung = value;
}

void ThuNhap::setDate(Date& value)
{
	this->date->setYear(value.getYear());
	this->date->setMonth(value.getMonth());
}

ostream& operator<<(ostream& out, ThuNhap& thuNhap)
{
	out << "====================" << endl;
	out << "===== Thu Nhap =====" << endl;
	out << "==== Tien quy ====" << endl;
	out << "	Quy vo chong: " << thuNhap.getQuyVoChong() << endl;
	out << "	Quy chung: " << thuNhap.getQuyChung() << endl;
	out << "==== Tien luong: " << endl;
	out << "	Luong chong: " << thuNhap.getLuongChong() << endl;
	out << "	Luong vo: " << thuNhap.getLuongVo() << endl;
	out << "	Luong chung: " << thuNhap.getLuongChung() << endl;
	out << "==== Chi tieu:" << endl;
	out << "	Phi sinh hoat: " << thuNhap.getSinhHoat() << endl;
	out << "	Phi khac: " << thuNhap.getChiPhiKhac() << endl;
	out << "====================" << endl;

	return out;
}

istream& operator>>(istream& in, ThuNhap& thuNhap)
{

	cout << "	Nhap tien luong chong: ";
	double tc;
	in >> tc;
	thuNhap.setLuongChong(tc);

	cout << "	Nhap tien luong vo: ";
	double tv;
	in >> tv;
	thuNhap.setLuongVo(tv);

	cout << "	Nhap tien luong chung: ";
	double tch;
	in >> tch;
	thuNhap.setLuongChung(tch);

	cout << "	Nhap phi sinh hoat: ";
	double psh;
	in >> psh;
	thuNhap.setSinhHoat(psh);

	cout << "	Nhap chi phi khac: ";
	double pk;
	in >> pk;
	thuNhap.setChiPhiKhac(pk);

	return in;
}

void ThuNhap::guiTietKiem()
{
	SoTietKiem* s = new SoTietKiem;
	s->chon(*this);
	stk.push_back(s);
}

void ThuNhap::sangThangTiepTheo()
{
	quyVoChong += luongVo + luongChong;
	quyChung += luongChung;

	if (quyChung >= (sinhHoat + chiPhiKhac)) 
	{
		quyChung -= (sinhHoat + chiPhiKhac);
	}
	else 
	{
		quyChung = 0;
		quyVoChong -= (sinhHoat + chiPhiKhac) - quyChung;
	}

	if (quyVoChong < 0)
		throw invalid_argument("==============\nWARNING: Quy bi am. Ban da pha san.\n==============");

	date->sangThang();
	if (stk.size() > 0) {
		for (size_t i = 0; i < stk.size(); i++) {
			stk[i]->checkDaoHan(*this);
		}
	}

}

void ThuNhap::printToCSV(ofstream& file)
{
	double thuchi = 
		this->luongChong 
		+ this->luongVo 
		+ this->luongChung 
		- (this->sinhHoat + this->chiPhiKhac);
	file <<
		*(this->date) << "," <<
		this->luongChong << "," <<
		this->luongVo << "," <<
		this->luongChung << "," <<
		this->sinhHoat << "," <<
		this->chiPhiKhac << "," <<
		this->quyVoChong << "," <<
		this->quyChung << "," <<
		thuchi;
}

void ThuNhap::duDoanTraNo()
{
	double thuchi =
		this->luongChong
		+ this->luongVo
		+ this->luongChung
		- (this->sinhHoat + this->chiPhiKhac);

	double quyDuKien = this->quyVoChong + this->quyChung;

	// phan tich chi tiet doi voi tung khoan no NH khac nhau
	for (size_t i = 0; i < no.size(); i++) {
		// xac dinh quy du kien ma nguoi dung se co duoc o thang can dong tien 
		double quyDuKien_i = quyDuKien + thuchi * no[i]->getDue();
		double soTienNo_i = no[i]->getTienNo() * (1 + no[i]->getLaiSuat() / 100 * no[i]->getDue() / 12);
		// tim xem co nhung khoan no NH nao dao han som hon khong, neu co thi phai tru di
		for (size_t j = 0; j < no.size(); j++) {
			if (no[j]->getSTT() != no[i]->getSTT() && no[j]->getDue() <= no[i]->getDue()) {
				// cong thuc: Tien no * (1 + Lai suat/100 * Thang gui/12)
				quyDuKien_i -= no[j]->getTienNo() * (1 + no[j]->getLaiSuat() / 100 * no[j]->getDue() / 12);
			}
		}

		// phan tich chi tiet doi voi khoan no i
		if (quyDuKien_i >= soTienNo_i) {
			cout << "*** Ve khoan no " << no[i]->getSTT() << " ***" << endl;
			cout << "Ban se co kha nang thanh toan khoan no nay vao thoi diem dao han" << endl;
			cout << "neu ban co the tiep tuc duy tri so tien thu chi nhu the nay." << endl;
		}
		else {
			cout << "*** Ve khoan no " << no[i]->getSTT() << " ***" << endl;
			cout << "Ban se khong co kha nang thanh toan khoan no nay vao thoi diem dao han" << endl;
			cout << "neu ban cu tiep tuc duy tri so tien thu chi nhu the nay." << endl;
			cout << "Hay can doi lai luong thu va chi phi neu ban muon tra duoc khoan no nay vao thoi diem dao han." << endl;
		}
	}


}

void ThuNhap::guiNoNganHang()
{
	TienNo* n = new TienNo;
	n->chon(*this);
	no.push_back(n);
}

Date* ThuNhap::getDate()
{
	return new Date(this->date->getYear(), this->date->getMonth());
}

void ThuNhap::Menu(ofstream& file)
{
	// Initializes columns titles
	file <<
		"THANG,LUONG CHONG,LUONG VO,LUONG CHUNG,PHI SINH HOAT,CHI PHI KHAC,QUY VO CHONG,QUY CHUNG,TINH HINH THU/CHI THANG NAY,\n";

	// Creates a loop menu in CMD for user
	int choose = -1;
	do {
		cout << "=======================================================" << endl;
		cout << "1. In ra man hinh chi tiet thu nhap." << endl;
		cout << "2. Thay doi luong." << endl;
		cout << "3. Quan ly so tiet kiem." << endl;
		cout << "4. Quan ly khoan no NH." << endl;
		cout << "5. Nhap so lieu vao File .CSV va sang thang tiep theo." << endl;
		cout << "0. Ket thuc chuong trinh." << endl;
		cout << "Nhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Da chon in ra man hinh chi tiet thu nhap." << endl;
			cout << *this;
			break;
		case 2:
			cout << "Da chon thay doi luong." << endl;
			cin >> *this;
			break;

		case 3:
			cout << "Da chon quan ly so tiet kiem." << endl;
			cout << "	1. Gui tiet kiem." << endl;
			cout << "	2. In ra man hinh danh sach STK." << endl;
			cout << "	Nhap lua chon: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "Da chon gui tiet kiem." << endl;
				this->guiTietKiem();
				break;
			case 2:
				cout << "Da chon in ra man hinh danh sach STK." << endl;
				for (size_t i = 0; i < stk.size(); i++) {
					cout << *stk[i];
				}
				break;
			default:
				break;
			}
			break;
		case 4:
			cout << "Da chon quan ly no NH." << endl;
			cout << "	1. Nhap no NH." << endl;
			cout << "	2. Thay doi lai suat no NH." << endl;
			cout << "	3. In ra man hinh danh sach no NH." << endl;
			cout << "	4. Du toan tinh hinh tra no cua nguoi dung ";
				cout << "(can cu theo tinh hinh thu/chi thang hien tai)." << endl;
			cout << "	Moi nhap: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "Da chon nhap no NH." << endl;
				this->guiNoNganHang();
				break;
			case 2:
				cout << "Da chon thay doi lai suat no NH." << endl;
				cout << "Nhap STT cua khoan no ma ban muon thay doi: ";
				int stt;
				cin >> stt;
				for (size_t i = 0; i < no.size(); i++) {
					no[i]->thayLaiSuat(stt);
				}
			case 3:
				cout << "Da chon in ra man hinh danh sach no NH." << endl;
				for (size_t i = 0; i < no.size(); i++) {
					cout << *no[i];
				}
				break;
			case 4:
				this->duDoanTraNo();
				break;
			default:
				break;
			}
			break;
		case 5:
			this->printToCSV(file);
			file << "\n";

			this->sangThangTiepTheo();
			cout << "Da sang thang tiep theo." << endl;
			break;
		case 0:
			// ends menu function
			for (size_t i = 0; i < stk.size(); i++) {
				stk.erase(stk.begin() + i);
			}
			for (size_t i = 0; i < no.size(); i++) {
				no.erase(no.begin() + i);
			}

			cout << "Da ket thuc chuong trinh.";
			break;
		default:
			break;
		}
	}
	while (choose != 0);

}


// CLASS SOTIETKIEM
int SoTietKiem::soluong = 0;
SoTietKiem* SoTietKiem::chon(ThuNhap& thuNhap)
{
	SoTietKiem* s = new SoTietKiem;
	cout << "Ban dang co: " << thuNhap.getQuyVoChong() << endl;
	cout << "Ban muon gui bao nhieu tien? Hay nhap: ";
	double tg;
	cin >> tg;

	while (s->tienGui > thuNhap.getQuyVoChong()) {
		cout << "So tien khong hop le. Hay nhap lai: ";
		cin >> tg;
	}
	thuNhap.setQuyVoChong(thuNhap.getQuyVoChong() - tg);

	this->setTienGui(tg);
	s->ngayGui = thuNhap.getDate();
	s->ngayDaoHan = thuNhap.getDate();

	cout << "Chon 6 thang hay 1 nam?" << endl;
	cout << "	1. 6 thang, lai suat 6%/nam" << endl;
	cout << "	2. 1 nam, lai suat 6.6%/nam" << endl;
	cout << "Hay chon: ";
	int choose;
	cin >> choose;

	while (choose != 1 && choose != 2) {
		cout << "Lua chon khong hop le. Hay chon lai: ";
		cin >> choose;
	}

	int due;
	switch (choose)
	{
	case 1:
		this->setLaiSuat(6 / 2);
		due = 6;
		break;
	case 2:
		this->setLaiSuat(6.6);
		due = 12;
		break;
	}

	Date* temp = this->getNgayDaoHan();
	for (int i = 0; i < due; i++) {
		temp->sangThang();
		this->setNgayDaoHan(*temp);
	}

	this->setTienGui(this->tienGui * (1 + this->getLaiSuat() / 100));

	return s;
}

void SoTietKiem::checkDaoHan(ThuNhap& thuNhap)
{
	if (thuNhap.getDate()->isEqual(*ngayDaoHan)) {
		thuNhap.setQuyVoChong(thuNhap.getQuyVoChong() + this->tienGui);
		for (size_t i = 0; i < stk.size(); i++) {
			if (stk[i] == this) stk.erase(stk.begin() + i);
		}
	}

}

SoTietKiem::SoTietKiem()
{
	ngayGui = new Date;
	ngayDaoHan = new Date;
	soluong++;
	stt = soluong;
}

SoTietKiem::~SoTietKiem()
{
	SoTietKiem::soluong--;
}

double SoTietKiem::getTienGui() {
	return this->tienGui;
}

void SoTietKiem::setNgayGui(Date& value)
{
	*this->ngayGui = value;
}

void SoTietKiem::setTienGui(double value) {
	this->tienGui = value;
}

double SoTietKiem::getLaiSuat() {
	return this->laiSuat;
}

void SoTietKiem::setLaiSuat(double value) {
	this->laiSuat = value;
}

Date* SoTietKiem::getNgayGui()
{
	return this->ngayGui;
}

Date* SoTietKiem::getNgayDaoHan() {
	return this->ngayDaoHan;
}

void SoTietKiem::setNgayDaoHan(Date& value) {
	*this->ngayDaoHan = value;
}

ostream& operator<<(ostream& out, const SoTietKiem& s) {
	out << "STK " << s.stt << endl;
	out << "	Tien se nhan duoc vao ngay dao han: " << s.tienGui << endl;
	out << "	Lai suat: " << s.laiSuat << endl;
	out << "	Ngay gui: " << *s.ngayGui << endl;
	out << "	Ngay dao han: " << *s.ngayDaoHan << endl;

	return out;
}


// CLASS TIENNO
int TienNo::soluong = 0;
TienNo::TienNo()
{
	ngayGui = new Date;
	ngayDaoHan = new Date;
	this->soluong++;
	stt = soluong;
	due = 0;
}

TienNo::~TienNo()
{
	TienNo::soluong--;
}

double TienNo::getTienNo()
{
	return this->tienNo;
}

void TienNo::setTienNo(double value)
{
	this->tienNo = value;
}

double TienNo::getLaiSuat()
{
	return this->laiSuat;
}

void TienNo::setLaiSuat(double value)
{
	this->laiSuat = value;
}

int TienNo::getDue()
{
	return this->due;
}

void TienNo::setDue(int value)
{
	this->due = value;
}

Date* TienNo::getNgayGui()
{
	return this->ngayGui;
}

void TienNo::setNgayGui(Date& value)
{
	*(this->ngayGui) = value;
}

Date* TienNo::getNgayDaoHan() {
	return this->ngayDaoHan;
}

void TienNo::setNgayDaoHan(Date& value) {
	*(this->ngayDaoHan) = value;
}

int TienNo::getSTT()
{
	return this->stt;
}

ostream& operator<<(ostream& out, const TienNo& n) {
	out << "Khoan no " << n.stt << endl;
	out << "	So tien du kien phai tra vao ngay dao han: " << n.tienNo * (1 + n.laiSuat / 100 * n.due / 12) << endl;
	out << "	Lai suat NH: " << n.laiSuat << endl;
	out << "	Ngay bat dau: " << *n.ngayGui << endl;
	out << "	Ngay dao han: " << *n.ngayDaoHan << endl;

	return out;
}

TienNo* TienNo::chon(ThuNhap& thuNhap)
{
	TienNo* n = new TienNo;
	cout << "Ban co khoan no NH bao nhieu tien? Hay nhap: ";
	double tno;
	cin >> tno;
	this->setTienNo(tno);

	cout << "Lai suat NH cua khoan no nay la bao nhieu % 1 nam? Hay nhap: ";
	double ls;
	cin >> ls;
	this->setLaiSuat(ls);

	n->ngayGui = thuNhap.getDate();
	n->ngayDaoHan = thuNhap.getDate();

	int due;
	cout << "Khoan no cua ban co han bao nhieu thang? Hay nhap: ";
	cin >> due;

	while (due <= 0) {
		cout << "Lua chon khong hop le. Hay nhap lai: ";
		cin >> due;
	}
	this->setDue(due);

	Date* temp = this->getNgayDaoHan();
	for (int i = 0; i < due; i++) {
		temp->sangThang();
		this->setNgayDaoHan(*temp);
	}

	return n;
}

void TienNo::checkDaoHan(ThuNhap& thuNhap)
{
	if (thuNhap.getDate()->isEqual(*this->ngayDaoHan)) {
		// khi tra no NH, se tra theo quy tac tra quy chung truoc
		// neu quy chung khong du thi lay quy vo chong ra tra
		double tienPhaiTra = this->tienNo * (1 + this->laiSuat / 100 * this->due / 12);
		// so sanh no NH voi tien quy chung
		if (tienPhaiTra > thuNhap.getQuyChung()) {
			// set quy chung = 0, lay quy vo chong thanh toan
			tienPhaiTra -= thuNhap.getQuyChung();
			thuNhap.setQuyChung(0);
			thuNhap.setQuyVoChong(thuNhap.getQuyVoChong() - tienPhaiTra);
		}
		// no NH < quy chung, lay quy chung tra
		else thuNhap.setQuyChung(thuNhap.getQuyChung() - tienPhaiTra);
		for (size_t i = 0; i < no.size(); i++) {
			if (no[i] == this) no.erase(no.begin() + i);
		}
	}
}

void TienNo::thayLaiSuat(int stt) {
	if (this->stt = stt) {
		cout << "Nhap lai suat NH ma ban muon thay doi: ";
		double ls;
		cin >> ls;
		this->setLaiSuat(ls);
	}
}
