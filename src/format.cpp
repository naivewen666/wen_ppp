/*============================
* created by Wen Huang
* introduction: formating functions
*
* date: 04.01.2023
*
*============================*/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <cctype>
#include <locale>

using namespace std;

string D2e(string str){
	replace(str.begin(), str.end(), 'D', 'e');
	return (str);
}

// scientific notation string to double
// https://www.oreilly.com/library/view/c-cookbook/0596007612/ch03s06.html
double sci2double(string str) {
	if (str.find('D') != string::npos){
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
}
// scientific notation string to double
float sci2float(string str) {
	if (str.find('D') != string::npos){
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
}

// some trim functions copy from
//https://www.oreilly.com/library/view/c-cookbook/0596007612/ch03s06.html
// trim from start (in place)
void ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
}

// trim from end (in place)
void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void trim(string &s) {
    rtrim(s);
    ltrim(s);
}

// trim from start (copying)
string ltrim_copy(string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
string rtrim_copy(string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
string trim_copy(string s) {
    trim(s);
    return s;
}