#include "Luong.h"

int main()
{

	ThuNhap* tn1 = new ThuNhap(1000, 1000, 1500, 1200);
	cout << *tn1;

	tn1->sangThangTiepTheo();
	cout << *tn1;
	
	return 0;
}
