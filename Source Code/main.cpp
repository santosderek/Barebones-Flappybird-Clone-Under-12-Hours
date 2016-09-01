#include <iostream>
#include "mainwindow.h"

int main()
{
	try
	{
		MainWindow mainwindow;
		mainwindow.run();
	}
	catch (std::exception& e)
	{
		std::cout << "Window had a problem.\n" << e.what();
	}

	return 0;

}
