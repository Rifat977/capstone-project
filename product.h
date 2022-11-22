#include<bits/stdc++.h>

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
