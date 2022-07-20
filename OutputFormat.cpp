#include <iostream>
#include <math.h>

#define PI 3.14159

using namespace std;

void printPI() {
	cout.precision(3);
	cout.width(10);
	cout.fill('#');
	cout<<PI<<endl;	
}

float distance(float x1, float y1, float x2, float y2) {
	float del_x = abs(x2-x1);
	float del_y = abs(y2-y1);
	float d_tmp = pow(del_x,2)+pow(del_y,2);
	return sqrt(d_tmp);
}

int main() {
	float x1,x2,y1,y2;
	cout<<"Enter x1:";
	cin>>x1;
	cout<<"Enter y1:";
	cin>>y1;
	cout<<"Enter x2:";
	cin>>x2;
	cout<<"Enter y2:";
	cin>>y2;
	cout<<"Distance:"<<distance(x1,y1,x2,y2);

	return 0;
}
