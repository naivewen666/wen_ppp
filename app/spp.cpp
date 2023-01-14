/*============================
* created by Wen Huang
* introduction: main function of single point positioning
*
* date: 02.01.2023
*
*============================*/
#include <iostream>
#include <string> 
#include "rnx.h"

using namespace std;
int main()
{
	string path_rnxn="../test/30400920.05n";
	rnxn_hd rnxhd;
	rnxhd=read_rnxn_hd(path_rnxn);
	cout << rnxhd.ver << endl;
	cout << rnxhd.rnx_type << endl;
	for ( int i=0;i<4;i++ ) cout << rnxhd.iona[i] << " " ;
	cout <<endl ; 
	for ( int i=0;i<4;i++ ) cout << rnxhd.ionb[i] << " " ;
	cout <<endl ; 
	for ( int i=0;i<4;i++ ) cout << rnxhd.d_utc[i] << " " ;
	cout <<endl ; 
	cout << rnxhd.leap_seconds << endl;
	return 0;
}