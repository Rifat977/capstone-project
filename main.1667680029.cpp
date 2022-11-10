#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

#include "loading.cpp"
#include "validation.cpp"

using namespace std;

enum Position{ LEFT, CENTRE, RIGHT };

void mainMenu();

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

void createAccount(){
	system("cls");
	string fullName, username, password;
	fstream fout;
	//create account section
	const int LINELENGTH = 75;
	string header( LINELENGTH, '=' );
	cout << '\n';
	print( CENTRE, "** Inventory Management System **", LINELENGTH );
	print( RIGHT, "- Create account -", LINELENGTH );
	cout << '\n';
	
	//take user input for create account	
	cout << "\n\tFull Name: "; cin.ignore();
	getline(cin, fullName);
	cout << "\n\tUsername: "; cin.ignore(0);
	getline(cin, username);
	cout << "\n\tPassword: "; cin.ignore(0);
	getline(cin, password);
	
	while(!isUsernameValidate(username)){
		print(RIGHT, "Invalid username", LINELENGTH);
		cout << "\n\tUsername: "; cin.ignore();
		getline(cin, username);
	}
	while(password==""){
		print(RIGHT, "Too short password", LINELENGTH);
		cout << "\n\tPassword: "; cin.ignore();
		getline(cin, password);
	}
	fout.open("user.csv", ios::out | ios::app);
	fout << fullName << "," 
			<< username << "," 
			<< password << "," 
			<< "\n";
	fout.close();
	system("cls");
	print(RIGHT, "Account created", LINELENGTH);
	mainMenu();
}

void loginAccount(){
	system("cls");
	string username, password;
	//login  section
	const int LINELENGTH = 75;
	string header( LINELENGTH, '=' );
	cout << '\n';
	print( CENTRE, "** Inventory Management System **", LINELENGTH );
	print( RIGHT, "- Login -", LINELENGTH );
	cout << '\n';
	
	//take user input for login	
	cout << "\n\tUsername: "; cin >> username;
	cout << "\n\tPassword: "; cin >> password;
}

void mainMenu(){
	//main menu of this application
	int input;
	const int LINELENGTH = 75;
	string header( LINELENGTH, '=' );
	cout << '\n';
	print( CENTRE, "** Inventory Management System **", LINELENGTH );
	print( RIGHT, "- Main Menu -", LINELENGTH );
	cout << '\n';
	print(LEFT, "\t[1] Create Account\n", LINELENGTH);
	print(LEFT, "\t[2] Login\n", LINELENGTH);
	print(LEFT, "\t[0] Exit", LINELENGTH);
	
	fstream fin; string line;
    fin.open("user.csv", ios::in);
    while(getline(fin, line, ',')){
    	if(line == "rifat"){
    		cout << line;
		}
	}
    
	
	//take user input for choose menu
	cout << "\n\tEnter your choice: ";
	cin >> input;	
	while(input != 0){
		if(input==1) createAccount();
		else if(input==2) loginAccount();
		else print(RIGHT, "Invalid Command", LINELENGTH);
		cout << "\n\tEnter your choice: ";
		cin >> input;
	}	
}

int main() {
	
	loadingBar();
	mainMenu();
			
	return 0;
}

