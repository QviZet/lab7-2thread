#include "header.h"

int main(int argc, const char* argv[]) {
	const int len = 100;
	double* arr;
	arr = new double[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = (rand() % 10000) / 10.;
	}

	double* frstPart;
	frstPart = new double[len / 2];
	double* scndPart;
	scndPart = new double[len / 2];

	for (int i = 0; i < len / 2; i++)
	{
		frstPart[i] = arr[i];
		scndPart[i] = arr[i + (len / 2)];
	}

	std::thread thread1(sortPart, "thread1", frstPart, len / 2);
	std::thread thread2(sortPart, "thread2", scndPart, len / 2);
	thread1.join();
	thread2.join();

	std::thread thread3(sortArr, "thread3", arr, frstPart, scndPart, len);
	thread3.join();

	std::cout << "\nSorting completed\n";

	delete[] arr;
	delete[] frstPart;
	delete[] scndPart;
	return 0;
}