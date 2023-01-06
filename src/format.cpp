#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

string D2e(string str){
	std::replace(str.begin(), str.end(), 'D', 'e');
	return (str);
}

double sci2double(string str) {
	if (str.find('D') != std::string::npos){
		str=D2e(str);
	}
	stringstream ss(str);
	double d = 0;
	ss >> d;

	if (ss.fail()) {
		string s = "Unable to format ";
		s += str;
		s += " as a number!";
		throw (s);
	}
	return (d);
}// https://www.oreilly.com/library/view/c-cookbook/0596007612/ch03s06.html

float sci2float(string str) {
	if (str.find('D') != std::string::npos){
		str=D2e(str);
	}
	stringstream ss(str);
	float d = 0;
	ss >> d;

	if (ss.fail()) {
		string s = "Unable to format ";
		s += str;
		s += " as a number!";
		throw (s);
	}
	return (d);
}// https://www.oreilly.com/library/view/c-cookbook/0596007612/ch03s06.html

// int main() {

//    try {
//       cout << sci2double("1.1180D-08") << endl;
//       cout << sci2double("6.02e-2") << endl;
//       cout << sci2double("asdf") << endl;
//    }
//    catch (string& e) {
//       cerr << "Whoops: " << e << endl;
//    }
// }