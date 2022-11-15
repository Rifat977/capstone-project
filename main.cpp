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

void print(Position pos, string s, int linelength )
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

string encrypt(string str){
	for(int i=0; i<str.length(); i++){
        str[i] = char(str[i]+26);
    }
    return str;
}

string decrypt(string str){
	for(int i=0; i<str.length(); i++){
        str[i] = char(str[i]-26);
    }
    return str;
}

void createAccount(){
	system("cls");
	const int LINELENGTH = 75;
	fstream fout, fin;
	fin.open("user.csv", ios::in);
	string fullName, username, password;
	//create account section
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
			<< encrypt(password) << "," 
			<< "\n";
	fout.close();
	system("cls");
	cout << "\n\n";
	print(RIGHT, "Account created", LINELENGTH);
	mainMenu();
}

void loginAccount(){
	system("cls");
	vector<string> userInfo;
	fstream fin; string file_text;
	string username, password;
	//login  section
	const int LINELENGTH = 75;
	string header( LINELENGTH, '=' );
	cout << '\n';
	print( CENTRE, "** Inventory Management System **", LINELENGTH );
	print( RIGHT, "- Login -", LINELENGTH );
	cout << '\n';
	
	//take user input for login	
	cout << "\n\tUsername: "; cin.ignore();
	getline(cin, username);
	cout << "\n\tPassword: "; cin.ignore(0);
	getline(cin, password);
	fin.open("user.csv", ios::in);
	userInfo.clear();
	while(getline(fin, file_text, ',')){
		userInfo.push_back(file_text);
	}
	cout << userInfo[1] << " " << decrypt(userInfo[2]);
	if(username==userInfo[1] && password==decrypt(userInfo[2])) cout << "Logged In";
	else{
		system("cls");
		cout << "\n";
		print(CENTRE, "XX - Credentials are incorrect - XX", LINELENGTH );
		mainMenu();	
	}
}

void mainMenu(){
	fstream fin; string line;
    fin.open("user.csv", ios::in);
    int checkUser = 0;
    while(getline(fin, line, ',')){
    	if(line != ""){
    		checkUser++;
		}
	}
	int input;
	const int LINELENGTH = 75;
	string header( LINELENGTH, '=' );
	cout << '\n';
	print( CENTRE, "** Inventory Management System **", LINELENGTH );
	print( RIGHT, "- Main Menu -", LINELENGTH );
	cout << '\n';
	print(LEFT, "\t[1] Login\n", LINELENGTH);
	if(checkUser == 0)
		print(LEFT, "\t[2] Create Account\n", LINELENGTH);
	print(LEFT, "\t[0] Exit", LINELENGTH);
    
	
	//take user input for choose menu
	cout << "\n\tEnter your choice: ";
	cin >> input;	
	while(input != 0){
		if(input==1) loginAccount();
		else if(input==2){
			if(checkUser == 0)
				createAccount();
			else print(RIGHT, "You have already registered", LINELENGTH);	
		}
		else print(RIGHT, "Invalid Command", LINELENGTH);
		cout << "\n\tEnter your choice: ";
		cin >> input;
	}	
}

int main() {
	
	loadingBar();
	mainMenu();
			
}

