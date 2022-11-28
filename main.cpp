#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

#include "loading.cpp"
#include "validation.cpp"
#include "product.h"

using namespace std;

void mainMenu();
void dashboard();

enum Position{ LEFT, CENTRE, RIGHT };

void print(Position pos, string s, int linelength ){
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

void dashboard(){
//	system("cls");
	const int LINELENGTH = 75;
	string header( LINELENGTH, '=' );
	cout << '\n';
	print( CENTRE, "** Inventory Management System **", LINELENGTH );
	print( RIGHT, "- Dashboard -", LINELENGTH );
	cout << '\n';
	print(LEFT, "\t[1] Add Product\n", LINELENGTH);
	print(LEFT, "\t[2] View Products\n", LINELENGTH);
	print(LEFT, "\t[3] Search Product\n", LINELENGTH);
	print(LEFT, "\t[4] Edit Product\n", LINELENGTH);
	print(LEFT, "\t[5] Remove Product\n", LINELENGTH);
	print(LEFT, "\t[6] Add Sale\n", LINELENGTH);
	print(LEFT, "\t[7] Sale Report\n", LINELENGTH);
	print(LEFT, "\t[8] Back\n", LINELENGTH);
	print(LEFT, "\t[9] Exit\n", LINELENGTH);
	char input; 
	cout << "\n\tChoose Option: ";
	cin >> input;
	while(input!='0'){
		if(input=='1'){
			system("cls");
			cout << '\n';
			print( CENTRE, "** Inventory Management System **", LINELENGTH );
			print( RIGHT, "- Add Product -", LINELENGTH );
			cout << '\n';
			addProduct();
			dashboard();
		}else if(input=='2'){
			system("cls");
			cout << "\n";
			print( CENTRE, "** Inventory Management System **", LINELENGTH );
			print( RIGHT, "- All Products -", LINELENGTH );
			cout << '\n';
			viewProducts();
			dashboard();
		}else{
			system("cls");
			print(RIGHT, "Invalid Command", LINELENGTH);
			dashboard();
		}
	}
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
	if(username==userInfo[1] && password==decrypt(userInfo[2])){
		system("cls");
		dashboard();
	}
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
	SetConsoleTitle(("Inventory Management System"));
	loadingBar();
	mainMenu();
			
}

