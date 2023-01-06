/*============================
* created by Wen Huang
* introduction:
*
* date:
*
*============================*/
#include <stdio.h>
#include <string> 
#include <fstream>
#include <sstream>
// #include <iostream>
#include "rnx.h"
#include "format.h"

using namespace std;

rnxn_hd read_rnxn_hd(const string& fname)
{	
	rnxn_hd rnxhd;
	ifstream f_rnxn(fname);
	string line;

	while (getline(f_rnxn, line))
    {
		if (line.find("RINEX VERSION / TYPE") != string::npos) {
			rnxhd.ver=stof(line.substr(0,9));
			strcpy(rnxhd.rnx_type,line.substr(20,1).c_str());
		}
		else if (line.find("ION ALPHA") != string::npos) {
			rnxhd.iona[0]=sci2float(line.substr(2,12));
			rnxhd.iona[1]=sci2float(line.substr(14,12));
			rnxhd.iona[2]=sci2float(line.substr(26,12));
			rnxhd.iona[3]=sci2float(line.substr(38,12));
		}
		else if (line.find("ION BETA") != string::npos) {
			rnxhd.ionb[0]=sci2float(line.substr(2,12));
			rnxhd.ionb[1]=sci2float(line.substr(14,12));
			rnxhd.ionb[2]=sci2float(line.substr(26,12));
			rnxhd.ionb[3]=sci2float(line.substr(38,12));
		}
		else if (line.find("DELTA-UTC: A0,A1,T,W") != string::npos) {
			rnxhd.d_utc[0]=sci2float(line.substr(3,19));
			rnxhd.d_utc[1]=sci2float(line.substr(22,19));
			rnxhd.d_utc[2]=sci2float(line.substr(41,9));
			rnxhd.d_utc[3]=sci2float(line.substr(50,9));
		}
		else if (line.find("LEAP SECONDS") != string::npos) {
			rnxhd.leap_seconds=stoi(line.substr(0,6));
		}
		else if (line.find("END OF HEADER") != string::npos) {
			break;
		}
		// cout << line << "\n"; //print the data of the string
    }
	f_rnxn.close();
	// char str[255];
	// int a;
	// FILE *fp=NULL;
	// char subtext[14];
	// fp=fopen(fname,"r");
	// if (fp==NULL)
	// {
	// 	printf("can't load file");
	// 	exit(0);
	// }
	// do
	// {	
	// 	fgets(str,255,(FILE*)fp);
	// 	printf("%s",str);
	// 	memcpy(subtext,&str[60],13);
	// 	a=strcmp(subtext,"END OF HEADER");
	// }while(!feof(fp)&&a!=0);
	// fclose(fp);
	
	return rnxhd;
}