#include "Luong.h"

int main()
{
	fstream myfile;
	myfile.open(_FILE_NAME, std::ios::in | std::ios::out);

	ThuNhap* tn1 = ThuNhap::getInstance();

	try 
	{
		tn1->Menu(myfile);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << endl;
		return -1;
	}

	myfile.close();

	return 0;
}
