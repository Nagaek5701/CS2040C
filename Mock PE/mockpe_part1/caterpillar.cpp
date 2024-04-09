
#include <string>
using namespace std;

string caterpillar(int n)
{
	if (n == 0) {
		return "<6";
	}
	else if (n > 0) {
		string output = "<";
		while (n != 0) {
			output += "Q";
			n--;
		}
		return output + "6";
		
	}
}