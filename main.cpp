#include<iostream>
#include "loading.cpp"
using namespace std;

int main(){
	loadingBar();
	
	string menu[] = {
		"1. Add", "2. Insert", "3. Exit"
	};
	
	gotoxy(x_margin, 3);
	cout << "=========================\n";
	gotoxy(x_margin, 4);
	cout << "|          Menu         |\n";
	gotoxy(x_margin, 5);
	cout << "=========================\n";
	
	gotoxy(x_margin, 7);
	cout << menu[0];
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	
	return 0;
}
