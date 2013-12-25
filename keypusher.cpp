#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <sys/time.h>

using namespace std;

void send_string(vector<string>);
vector<string> parse_string(string);
bool check_apostrophe(string&);
void send_apostrophe_string(vector<string>);
void replace_apostrophe(string&);
void get_sms();
void take_photo();
void parse_Flags(int, char**);
void push_Script();

bool textmode;


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
        if((it + 1) != words.end()){ //Check if it is the last word
            system("adb shell input keyevent 62"); //Send space key
        }
	}
	if(textmode)
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
	
    return word.find_first_of(" ' ") != string::npos;
}


void send_apostrophe_string(vector<string> frags){
	for(vector<string>::iterator it = frags.begin(); it != frags.end(); ++it){
		

		string send = "adb shell input text " + *it ;
		if(it->length() != 0) //Prevents calling with multiple apostrophes in a row
			system(send.c_str());
		if(((it + 1) != frags.end()))//Check if final fragment
			system("adb shell input keyevent 75"); //Send apostrophe

	}
}

void replace_apostrophe(string &word){
    size_t found = word.find_first_of("'");
    while(found!=string::npos){
		word[found] = ' ';
        found = word.find_first_of("'", found+1);
    }

}

void get_sms(){
	double minutes = 1;
	struct timeval tim;  
    	gettimeofday(&tim, NULL);  
    	double t1=tim.tv_sec+(tim.tv_usec); //current time in miliseconds

	double past_time = t1; 
	system("adb shell date +%s\'");
	ostringstream ss;
	ss << past_time;
	string past_string = ss.str();
    string command = "adb shell \'sqlite3 /data/data/com.android.providers.telephony/databases/mmssms.db \"SELECT address, date, body FROM sms\"\'"; //WHERE date > \'" + past_string +"\'\"\'";

    system("adb root");

	system(command.c_str());
	cout << endl;

}

void take_photo(){
    system("adb shell sh /sdcard/take_photo.sh"); // will only work if script has been pushed to device
}


void push_Script(){
	/* FIXME: Actually push the script */
    string command = "adb push ../take_photo.sh /sdcard/take_photo.sh";
	system(command.c_str());
	cout << "push script here" << endl;
}

void set_TextMode(bool state){
        textmode = state;
}
