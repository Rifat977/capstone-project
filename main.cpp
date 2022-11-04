#include<iostream>
#include <string>
#include "loading.cpp"

#include "cpr.h"

using namespace std;

enum Position{ LEFT, CENTRE, RIGHT };

void print( Position pos, string s, int linelength )
{
   int spaces = 0;
   switch( pos )
   {
      case CENTRE: spaces = ( linelength - s.size() ) / 2; break;
      case RIGHT : spaces =   linelength - s.size()      ; break;
   }
   if ( spaces > 0 ) cout << string( spaces, ' ' );
   cout << s << '\n';
}

void mainMenu(){
	int input;
	do{
		const int LINELENGTH = 75;
		string header( LINELENGTH, '=' );
		cout << '\n';
		print( CENTRE, "** Inventory Management System **", LINELENGTH );
		print( RIGHT, "- Main Menu -", LINELENGTH );
		cout << '\n';
		print(LEFT, "\t[1] Create Account\n", LINELENGTH);
		print(LEFT, "\t[2] Login\n", LINELENGTH);
		print(LEFT, "\t[0] Exit", LINELENGTH);
		
		cout << "\n\tEnter your choice: ";
		cin >> input;
		system("cls");
	}while(input != 0);
}

int main(int argc, char** argv) {
//	loadingBar();
//	mainMenu();
	
	cpr::Response r = cpr::Get(cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
                      cpr::Authentication{"user", "pass"},
                      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text; 
		
	return 0;
}




