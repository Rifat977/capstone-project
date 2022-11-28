#include<bits/stdc++.h>
#include <conio.h>

using namespace std;

void addProduct(){
	fstream fout, fin;
	string productName, productCode, productStock, productPrice;
	vector<string> products;
	string file_text = "";
	int isExists = 1;
	
	
	cout << "\n\tProduct Code: "; cin.ignore();
	getline(cin, productCode);
	cout << "\n\tProduct Name: "; cin.ignore(0);
	getline(cin, productName);
	cout << "\n\tProduct Price: "; cin.ignore(0);
	getline(cin, productPrice);
	cout << "\n\tProduct Stock: "; cin.ignore(0);
	getline(cin, productStock);

	fin.open("product.csv", ios::in);
	while(getline(fin, file_text, ',')){
		products.push_back(file_text);
	}
	for(int i=0; i<products.size(); i+=4){
		if(productCode==products[i]){
			isExists = 0;
		}
	}
	if(isExists==1){
		fout.open("product.csv", ios::out | ios::app);
		fout	<< productCode << "," 
				<< productName << "," 
				<< productPrice << "," 
				<< productStock << "," 
				<< "\n";
		fout.close();
		cout << "\n\t\t\tProduct Added Successfully\n";
	}else{
		cout << "\n\t\t\tProduct code already exists\n";
	}
}

void viewProducts(){
		struct Product{
			string code, name, price, stock;
		};
		const int LINELENGTH = 75;
		fstream fin; string file_text = "";
		vector<string> products;
		fin.open("product.csv", ios::in);
		while(getline(fin, file_text, ',')){
			products.push_back(file_text);
		}
		struct Product p1[products.size()];
		for(int i=0, j=0; i<products.size()-3; i++, j++){
			p1[j].code = products[i];
			p1[j].name = products[i+1];
			p1[j].price = products[i+2];
			p1[j].stock = products[i+3];
			i+=3;
		}
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout << "Code\t\t\t Name\t\t\t Price\t\t\t Stock\n";
		cout<<"--------------------------------------------------------------------------------\n"<<endl;
		for(int i=0; i<products.size()/4; i++){
			cout << p1[i].code << "\t\t\t" << p1[i].name << "\t\t\t" << p1[i].price << "\t\t\t" << p1[i].stock << "\n";
		
		}
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
  	    cout<<">---->---->---->---->---->---->  FINISH  <----<----<---<----<----<----<----<---<"<<endl;
  		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout << "\n\t\tPress any key to back dashboard ... ";
		char ch = getch();
		system("cls");
}
