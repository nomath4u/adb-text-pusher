#ifndef KEYPUSHER_H
#define KEYPUSHER_H

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

#endif // KEYPUSHER_H
