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

/*int main(int argc, char** argv){
	string input;
	bool quit = false;
	char selection;
	if(argc != 1){
		parse_Flags(argc, argv);
	}
	cout << "If it isn't plugged in already, please plug your android phone in now." << endl;   //Trying to add some sort of instructions if they didn't read the README

	cout << "Would you like to enable text mode? (Y/n)" << endl;
	cin.get(selection);
	cin.ignore(25, '\n');
	if(toupper(selection) == 'Y'){
		textmode = true;
		cout << "Text Mode enabled" << endl;
	}
	else if(toupper(selection) == 'N'){
		textmode = false;
		cout << "Text Mode disabled" << endl;
	}
	else{
		cout << "Invalid selection automatically enabling Text Mode" << endl;
	}

	cout << "Type \"exit\" at any time to quit"<< endl << "Type \"read\" to get most recent text" << endl;
	while(!quit){
		cout << "input text" << endl;
		getline(cin, input);
		if(input == "exit")
			quit = true;
		else if(input == "read")
			get_sms();
		else if(input == "camera")
			take_photo();
		else
			send_string(parse_string(input));
	}
	return 0;
}*/

void send_string(vector<string> words){


	for(vector<string>::iterator it = words.begin(); it != words.end(); ++it){
		if(!check_apostrophe(*it)){
<<<<<<< HEAD
            string send = "adb shell input text " + *it ;
=======
			string send = "adb shell input text " + *it ;
>>>>>>> 6667469d52d70f1686173999d3b673f50dd860ea
			system(send.c_str());
		}
		else{
			replace_apostrophe(*it);
			send_apostrophe_string(parse_string(*it));
		}	
		if((it + 1) != words.end()) //Check if it is the last word
<<<<<<< HEAD
            system("adb shell input keyevent 62"); //Send space key
	}
	if(textmode)
        system("adb shell input keyevent 66"); //Send enter key
=======
			system("shell input keyevent 62"); //Send space key
	}
	if(textmode)
		system("adb shell input keyevent 66"); //Send enter key
>>>>>>> 6667469d52d70f1686173999d3b673f50dd860ea
	
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
	
	return found!=string::npos;
}


void send_apostrophe_string(vector<string> frags){
	for(vector<string>::iterator it = frags.begin(); it != frags.end(); ++it){
		
<<<<<<< HEAD
        string send = "adb shell input text " + *it ;
		if(it->length() != 0) //Prevents calling with multiple apostrophes in a row
			system(send.c_str());
		if(((it + 1) != frags.end()))//Check if final fragment
            system("adb shell input keyevent 75"); //Send apostrophe
=======
		string send = "adb shell input text " + *it ;
		if(it->length() != 0) //Prevents calling with multiple apostrophes in a row
			system(send.c_str());
		if(((it + 1) != frags.end()))//Check if final fragment
			system("adb shell input keyevent 75"); //Send apostrophe
>>>>>>> 6667469d52d70f1686173999d3b673f50dd860ea
	}
}

void replace_apostrophe(string & word){
	unsigned found = word.find_first_of(" \' ");
	while(found!=string::npos){
		word[found] = ' ';
		found = word.find_first_of(" \' ", found+1);
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
<<<<<<< HEAD
    string command = "adb shell \'sqlite3 /data/data/com.android.providers.telephony/databases/mmssms.db \"SELECT address, date, body FROM sms\"\'"; //WHERE date > \'" + past_string +"\'\"\'";

    system("adb root");
=======
	string command = "adb shell \'sqlite3 /data/data/com.android.providers.telephony/databases/mmssms.db \"SELECT address, date, body FROM sms\"\'"; //WHERE date > \'" + past_string +"\'\"\'";

	system("adb root");
>>>>>>> 6667469d52d70f1686173999d3b673f50dd860ea
	system(command.c_str());
	cout << endl;

}

void take_photo(){
	system("adb shell sh /sdcard/take_photo.sh"); // will only work if script has been pushed to device


}

void parse_Flags(int input_tokens, char **input_string){
	string s;
	int i;
	for(i=1; i < input_tokens; i++){ //Parse the one flag
		
		s = input_string[i];
		if(s == "-s"){
			push_Script();
		}
	}
}

void push_Script(){
	/* FIXME: Actually push the script */
	string command = "adb push ./take_photo.sh /sdcard/take_photo.sh";
	system(command.c_str());
	cout << "push script here" << endl;
}
