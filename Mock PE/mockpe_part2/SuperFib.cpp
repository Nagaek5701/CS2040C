#include <iostream>
using namespace std;

int superFib(int n) {
	if (n < 0) {
		throw std::out_of_range("Input positive integer.");
	}

	//Base case:
	else if (n == 0) {
		return 1;
	}
	//Recursion:
	int output = 0;
	while (n != 0) {
			output += superFib(n - 1);
			n--;
		}
	return output;
}
