#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void send_string(vector<string>);
vector<string> parse_string(string);

int main(){
	string input;
	cout << "input text" << endl;
	getline(cin, input);
	send_string(parse_string(input));
	return 0;
}

void send_string(vector<string> words){

	for(vector<string>::iterator it = words.begin(); it != words.end(); ++it){

		string send = "adb shell input text " + *it;
		system(send.c_str());
		if((it + 1) != words.end()) //Check if it is the last word
			system("adb shell input keyevent 62"); //Send space key
	}
	system("adb shell input keyevent 66"); //Send enter key
	
}

vector<string> parse_string(string phrase){

	vector<string> tokens;

	istringstream phrase_stream(phrase);
	string segment;
	while (getline(phrase_stream, segment, ' '  )){
		tokens.push_back(segment);
	}

	return tokens;
	
}
