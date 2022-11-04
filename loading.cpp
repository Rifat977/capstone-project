#include<bits/stdc++.h>
#include<windows.h>
#include "align.cpp"

using namespace std;

int x_margin = 23, y_margin = 5;
void loadingBar()
{
	system("cls");
	system("color 0F");
	char a = 221, b = 219;
	gotoxy(x_margin, y_margin);
	cout<<"Student Management System\n";
	gotoxy(x_margin, y_margin+=2);
	cout<<"Project By Rifat\n";
	gotoxy(x_margin, y_margin+=2);
	cout<<"Loading...\n";
	cout<<endl;
	
	gotoxy(x_margin, y_margin+=2);
	for(int i = 0;i<30;i++)
	cout<<a;
	
	gotoxy(x_margin, y_margin);
	for(int i = 0; i < 30 ; i++)
	{
		cout<<b;
		Sleep(5);
	}
	cout << "\n\n";
	
	system("cls");
	
}
