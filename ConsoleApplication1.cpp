#include<iostream>
#include<string>
#include <ctime>

using namespace std;
int main()
{
	int hour_in, min_in, jumper_hour{}, jumper_min{}, conv_hour, conv_min, conv_seconds;
	string command = ("shutdown -s -t "), command_string;
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);

	// set up variables with current time
	int hour = (tPtr->tm_hour);
	int min = (tPtr->tm_min);

	// input wanted time
	cout << "In which hour turn off pc: ";
	cin >> hour_in;
	cout << "in which min turn off pc: ";
	cin >> min_in;

	// hour loop
	for (int i = hour; i <= hour_in; i++) {
		if (hour != hour_in) {
			hour++;
			jumper_hour++;
		}
	}

	// minute loop
	for (int i = min; i <= min_in; i++) {
		if (min != min_in) {
			min++;
			jumper_min++;
		}
	}
	
	// converting to seconds
	conv_hour = jumper_hour * 3600;
	conv_min = jumper_min * 60;
	conv_seconds = conv_hour + conv_min;
	
	// converting int's to strings to write it to single command in cmd
	command_string = to_string(conv_seconds);
	command += command_string;
	system(command.c_str());
}