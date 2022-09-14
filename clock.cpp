//=========================
// Grant Gutterman
// 09-02-2022
// clock.cpp
// A program to add two clocks together.
//=========================

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main ( void )
{
	string time1, time2;
	
	// prompt user for times
	cout << "Enter time1 (HH:MM:SS): ";
	cin >> time1;
	cout << "Enter time2 (HH:MM:SS): ";
	cin >> time2;
	
	string hhs = time1.substr(0,2);
	string mms = time1.substr(3,2);
	string sss = time1.substr(6,2);
	int hh1 = stoi(hhs), mm1 = stoi(mms), ss1 = stoi(sss);
	
	int hh2 = stoi(time2.substr(0,2));
	int mm2 = stoi(time2.substr(3,2));
	int ss2 = stoi(time2.substr(6,2));
	
	
	cout << "time1: " << time1 << endl;
	cout << "hour1: " << hh1 << endl;
	cout << "minute1: " << mm1 << endl;
	cout << "second1: " << ss1 << endl;
	cout << "time2: " << time2 << endl;
	cout << "hour2: " << hh2 << endl;
	cout << "minute2: " << mm2 << endl;
	cout << "second2: " << ss2 << endl;
	
	// addition problem
	
	int hh3, mm3, ss3;
	
	int total_seconds = ss1 + ss2;
	ss3 = total_seconds % 60;
	
	int total_minutes = mm1 + mm2 + (total_seconds / 60);
	mm3 = total_minutes % 60;
	
	int total_hours = hh1 +hh2 + (total_minutes / 60);
	hh3 = total_hours % 24;
	
	/*
	cout << "hour3: " << hh3 << endl;
	cout << "minute3: " << mm3 << endl;
	cout << "second3: " << ss3 << endl;
	*/
	
	/ iomanip
	/ setw
	/ setfill
	
	
	
	return 0;

}
