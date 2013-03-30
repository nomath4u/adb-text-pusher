#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void send_string(vector<string>);
vector<string> parse_string(string);
bool check_apostrophe(string&);
void send_apostrophe_string(vector<string>);
void replace_apostrophe(string&);

int main(){
	string input;
	cout << "input text" << endl;
	getline(cin, input);
	send_string(parse_string(input));
	return 0;
}

void send_string(vector<string> words){


	for(vector<string>::iterator it = words.begin(); it != words.end(); ++it){
		if(!check_apostrophe(*it)){
			string send = "adb shell input text " + *it ;
			system(send.c_str());
		}
		else{
			replace_apostrophe(*it);
			send_apostrophe_string(parse_string(*it));
		}	
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

bool check_apostrophe(string &word){

	unsigned found = word.find_first_of(" \' ");
	
	if(found!=string::npos){
		return true;
	}	
	else
		return false;
}

void send_apostrophe_string(vector<string> frags){
	for(vector<string>::iterator it = frags.begin(); it != frags.end(); ++it){
		
		string send = "adb shell input text " + *it ;
		if(it->length() != 0) //Prevents calling with multiple apostrophes in a row
			system(send.c_str());
		if((it + 1) != frags.end())//Check if final fragment
			system("adb shell input keyevent 75"); //Send apostrophe
	}
}

void replace_apostrophe(string & word){
	unsigned found = word.find_first_of(" \' ");
	while(found!=string::npos){
		word[found] = ' ';
		found = word.find_first_of(" \' ", found+1);
	}
}
