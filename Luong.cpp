#include "Luong.h"


ostream& operator<<(ostream& out, ThuNhap& thuNhap)
{
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

	return out;
}

istream& operator>>(istream& in, ThuNhap& thuNhap)
{
	cout << "Nhap tien luong vo:\n	";
	double tv;
	in >> tv;
	thuNhap.setLuongVo(tv);
	
	cout << "Nhap tien luong chong:\n	";
	double tc;
	in >> tc;
	thuNhap.setLuongChong(tc);

	cout << "Nhap tien luong chung:\n	";
	double tch;
	in >> tch;
	thuNhap.setLuongChung(tch);

	cout << "Nhap chi tieu:\n	";
	double ct;
	in >> ct;
	thuNhap.setChiTieu(ct);

	return in;
}


ThuNhap::ThuNhap()
{
	luongVo = 0;
	luongChong = 0;
	luongChung = 0;
	chiTieu = 0;
}

ThuNhap::ThuNhap(double luongVo, double luongChong, double luongChung, double chiTieu)
{
	// input
	this->luongVo = luongVo;
	this->luongChong = luongChong;
	this->luongChung = luongChung;
	this->chiTieu = chiTieu;

	// data
	this->quyVoChong = this->luongVo + this->luongChong;
	this->quyChung = this->luongChung;
}

ThuNhap::ThuNhap(const ThuNhap& thuNhap)
{
	// input
	this->luongVo = thuNhap.luongVo;
	this->luongChong = thuNhap.luongChong;
	this->luongChung = thuNhap.luongChung;
	this->chiTieu = thuNhap.chiTieu;

	// data
	this->quyVoChong = thuNhap.quyVoChong;
	this->quyChung = thuNhap.quyChung;
}

ThuNhap::~ThuNhap()
{
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

ThuNhap& ThuNhap::operator=(const ThuNhap& thuNhap)
{
	// TODO: insert return statement here
	this->luongVo = thuNhap.luongVo;
	this->luongChong = thuNhap.luongChong;
	this->luongChung = thuNhap.luongChung;
	this->chiTieu = thuNhap.chiTieu;

	this->quyVoChong = thuNhap.quyVoChong;
	this->quyChung = thuNhap.quyChung;
}

void ThuNhap::guiTietKiem()
{
	/*SoTietKiem* stk = new SoTietKiem;
	stk->choose(*this);*/
}

void ThuNhap::sangThangTiepTheo()
{
	
	if (quyChung >= chiTieu) 
	{
		quyChung -= chiTieu;
	}
	else 
	{
		luongChung = 0;
		quyVoChong -= chiTieu - quyChung;
	}

	quyVoChong += luongVo + luongChong;
	quyChung += luongChung;

	cout << "Sang thang tiep theo." << endl;

}

void SoTietKiem::choose(ThuNhap& tn)
{
	//tn.settienVo(3333);
}

void Menu::Create()
{
	ThuNhap tn;
	cout << "Quan ly tien" << endl;
	cout << "Luong vo: " << tn.getLuongVo() << endl;
	cout << "Luong chong: " << tn.getLuongChong() << endl;
	cout << "Luong chung: " << tn.getLuongChung() << endl;
	cout << "Chi tieu: " << tn.getChiTieu() << endl;

	int n = 0;
	do {
		int choose;
		cout << "1. Thay doi luong" << endl;
		cout << "2. Ngan hang" << endl;
		cout << "3. Xuat chi tiet so du" << endl;
		cout << "4. Sang thang tiep theo" << endl;
		//
		cout << "Choose option: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			// thay doi luong
			break;
		case 2:
			// ngan hang
			break;
		case 3:
			// xuat chi tiet
			break;
		case 4:
			// sang thang
			break;
		default:
			break;
		}
		//
		n++;
	} while (n < 10);

}
