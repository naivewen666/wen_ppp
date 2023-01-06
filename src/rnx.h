/*============================
* created by Wen Huang
* introduction:
*
* date:
*
*============================*/
#include <string>

using namespace std;
typedef struct rnxn_hd
{
	float ver;
	char  rnx_type[1];		// N/O/M...
	char  gnss_type;		// GNSS(multi-GNSS),GPS,Galileo,GLONASS,BEIDOU
	char  gnss_id;			// M,G,E,R,C
	float iona[4];			// ionosphere par. alpha
	float ionb[4];			// ionosphere par. beta
	float d_utc[4];		// almanac parameters(A0,A1,T,W) to compute time in UTC
	int leap_seconds;		// delta time due to leap seconds 
} rnxn_hd;

// rinex functions defined in rnx.cpp
rnxn_hd read_rnxn_hd(const string& fname);
