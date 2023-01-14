/*============================
* created by Wen Huang
* introduction: h file for rinex related type and functions
*
* date: 02.01.2023
*
*============================*/
#include <string>
#include <com.h>
using namespace std;

typedef struct rnxn_hd
{
	float ver;
	char  rnx_type[1];		// N/O/M...
	char  gnss_type;		// GNSS(multi-GNSS),GPS,Galileo,GLONASS,BEIDOU
	char  gnss_id;			// M,G,E,R,C
	float iona[4];			// ionosphere par. alpha
	float ionb[4];			// ionosphere par. beta
	float d_utc[4];			// almanac parameters(A0,A1,T,W) to compute time in UTC
	int leap_seconds;		// delta time due to leap seconds 
} rnxn_hd;

typedef struct rnxn_data
{
	float prn;				// PRN of satellite
	t_time toc;				// time of clk
	double bias_clk;		// SV clock bias (sec)
	double dft_clk;			// SV clock drift (sec/sec)
	double dft_rate_clk;	// SV clock drift rate (sec/sec^2)
	double iode;			// issue of data
	double crs;				// Crs (m)
	double d_n;				// delta n (radian/sec)
	double m0;				// (radian)
	double cuc;				// Cuc (radian)
	double e;				// Eccentricity
	double cus;				// Cus (radians)
	double sqrta;			// sqrt(m)
	double toe;				// Time of Ephemeris (sec of GPS week)
	double cic;				// radians
	double OMEGA;			// radians
	double cis;				// radians
	double i0;				// radians
	double crc;				// meters
	double omega;			// radians
	double OMEGA_dot;		// radians/sec
	double idot;			// radians/sec
	double code_l2;	
	double gpsweek;			// to go with TOE
	double l2p_flag;		
	double accuracy;		// meters
	double health;			// bits 17-22 w 3 sf 1	
	double tgd;				// second
	double iodc;			// Issue of Data, Clock
	double trans_time;		// Transmission time of message (sec of GPS week, derived e.g. from Z-count in Hand Over Word (HOW))
	double fit_int;			// Fit interval (hours) zero if not known
} rnxn_data;

// rinex functions defined in rnx.cpp
rnxn_hd read_rnxn_hd(const string& fname);
rnxn_data read_rnxn_data(const string& fname);
