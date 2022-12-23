#include <iostream>

using namespace std;
int main10() {
	double f = 12343.1415912321;

	cout.setf(ios::right);
	cout.fill('|');
	cout.precision(5);
	cout.width(100);
	cout << f << '\n';
	cout.setf(ios::left);
	cout << f << '\n';

	cout.precision(10);
	cout << f << '\n';

	return 0;
}