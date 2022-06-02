#include "Luong.h"

int main()
{
	ofstream myfile;
	//// insert mode
		//myfile.open("data.csv", std::ios::out | std::ios::app);
	
	// overwrite mode
		myfile.open("data.csv");

	ThuNhap* tn1 = ThuNhap::getInstance();

	try 
	{
		tn1->Menu(myfile);
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << endl;
		return -1;
	}

	myfile.close();

	return 0;
}
