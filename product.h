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
		if(!productCode.empty() && !productName.empty() && !productPrice.empty() && !productStock.empty()){
			fout.open("product.csv", ios::out | ios::app);
		fout	<< productCode << "," 
				<< productName << "," 
				<< productPrice << "," 
				<< productStock << "," 
				<< "\n";
		fout.close();
		cout << "\n\t\t\tProduct Added Successfully\n";
		}else{
			cout << "\n\t\t\tProduct field doesn't empty\n";
		}
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
		if(fin.fail()){
			cout << "failed";
		}else{
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
		cout << "Code\t\t Name\t\t\t Price\t\t Stock\n";
		cout<<"--------------------------------------------------------------------------------\n"<<endl;
		for(int i=0; i<products.size()/4; i++){
			cout << p1[i].code << "\t\t" << p1[i].name << "\t\t" << p1[i].price << "\t\t" << p1[i].stock << "\n";
		
		}
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
  		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout << "\n\t\tPress any key to back dashboard ... ";
		char ch = getch();
		system("cls");
		}
}

//void searchProduct(){
//		string pro_code;
//		cout << "\n\tSearch product by code: "; cin.ignore();
//		getline(cin, pro_code);
//		
//		fstream fin; string file_text = "";
//		fin.open("product.csv", ios::in);
//		if(fin.fail()){
//			cout << "\n\tNo such file\n";
//		}else{
//			while(getline(fin, file_text, ',')){
//				if(file_text==pro_code){
//					cout << file_text;
//				}
//			}
//  			cout<<"--------------------------------------------------------------------------------"<<endl;
//			cout << "\n\t\tPress any key to back dashboard ... ";
//			char ch = getch();
//			system("cls");
//		}
//		
//}

void read_record()
{
    fstream fin;
  
    fin.open("product.csv", ios::in);
  
    string input_product, file_product; int count = 0;
    cout << "Enter the product code: ";
    cin >> input_product;
  
    vector<string> row;
    string line, word, temp;
  
    while (fin >> temp) {
  
        row.clear();
  
        getline(fin, line);
  
        stringstream s(line);
  
        while (getline(s, word, ',')) {
  
            row.push_back(word);
        }
  
        file_product = row[0];
  
        if (file_product == input_product) {
  
            count = 1;
            cout << "Product code: " << row[0] << " : \n";
            break;
        }
    }
    if (count == 0)
        cout << "Product not found\n";
}
