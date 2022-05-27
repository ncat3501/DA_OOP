#include "Luong.h"



int main()
{

	ThuNhap* tn1 = ThuNhap::getInstance();
	cin >> *tn1;
	cout << *tn1;

	tn1->Menu();
	
	return 0;
}
