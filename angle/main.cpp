/*
calcuate angle of two hands of clock given time
*/
#include<iostream>
using namespace std;
float Angle( int hour, int minute );
int main(void){
	int hour, minute;
	cout<<"Hour:Minute"<<endl;
	cin>>hour>>minute;
	cout<<"Your time is:"<<hour<<":"<<minute<<endl;
	float angle = Angle(hour, minute);
	cout<<"Angle:"<<angle<<endl;
	return 0;
}
float Angle( int nHour, int nMinute ){
	float fAngle, fAngleHour, fAngleMinute;
	if(nHour==12)
		nHour = 0;
	fAngleHour = 30*nHour + nMinute*(0.5);
	fAngleMinute = nMinute*6;
	fAngle = fAngleMinute - fAngleHour;
	if(fAngle<0)
		fAngle = -fAngle;
	if(fAngle>180)
		fAngle -= 180;
	return fAngle;
}
