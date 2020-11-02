#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string members[100][4]={{"1","Wandee Wongpaisal","0951427384","wandee085383@gmail.com"},
						{"2","Thapakorn Ngamckaroen","0652378996","0652378996tong@gmail.com"},
						{"3","Suntimeth Taweepa","0929701607","suntimethpw@gmail.com"},
						{"4","Pranjapol Suriyachai","0868317199","pranjapol2544@gmail.com"},
						{"5","Wuthinan Tanomsap","0956310086","nongaom690@gmail.com"}};
string products[100][2]={{"01","KITKAT"},
						 {"02","LAYS"},
						 {"03","POKKY"},
						 {"04","OREO"},
						 {"05","JELLY BEAR"}};

string orders[100][2];
int qty[100];



float prices[100][2]={{399,100},
					{60,100},
					{30,100},
					{59,100},
					{79,100}};

int index;
void sellproduct();
void report_products();
void report_members();

void mainmenu();
void report();
void admin();

void insert_product();
void insert_member();
void sell();
int main()
{
	mainmenu();
	return 0;
}

void mainmenu() {
	system("cls");
	char menu;
	cout << "***********************" <<endl;
	cout << "1.customer data\n";
	cout << "2.goods data\n";
	cout << "3.buy product\n";
	cout << "4.report\n";
	cout << "5.admin\n";
	cout << "6.exit\n";
	cout<<"***********************"<<endl;
	cout<<"Enter menu : ";
	cin>>menu;
	switch(menu) {
		case '1':
			insert_member();
			break;
		case '2':
			insert_product(); 
			break;
		case '3':
			sell();
			break;
		case '4':
			report();
			break;
		case '5':
			admin();
			break;
		case '6':
			system("pause");
			exit(0);
			break;
		default:
			mainmenu();
	}
}

void report_members() {
	system("cls");
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout <<setw(10)<<left<<"ID"<<setw(25)<<left<<"Name"<<setw(15)<<left <<"TEL."<<setw(10)<<left <<"Email"<< endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<endl;
	for (int i = 0; i < 100; i++) {
		if (!members[i][0].empty()) {
			cout <<setw(10)<<left<<members[i][0] <<setw(25)<<left<< members[i][1]<<setw(15)<<left << members[i][2]<<setw(10)<<left << members[i][3] << endl;
		}
	}
	cout<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl<<endl;
	cout << "...Please enter to menu...";
	cin.get();
	cin.ignore();
	admin();
}


void report_product() {
	system("cls");
		cout<<setw(32)<<"         STOCKS"<<endl;
		cout<<"--------------------------------------------------------"<<endl;
		cout<< setw(10)<<left<<"No."<<setw(10)<<left<< "ID."<<setw(20)<<left<< "Name."<<setw(10)<<left<< "price"<<setw(10)<<left<<"stock"<<endl;
		cout<<"--------------------------------------------------------"<<endl;
		cout<<endl;
	int a = 0;
	for (int i = 0; i < 100; i++) {
		if (!products[i][0].empty()) {
			a++;
			cout<< setw(10)<<left<< a <<setw(10)<<left<< products[i][0] <<setw(20)<<left<< products[i][1] <<setw(10)<<left<< fixed << setprecision(2) << prices[i][0] <<setw(10)<<left<< prices[i][1] <<endl;
		}
	}
	cout<<endl;
	cout<<"--------------------------------------------------------"<<endl<<endl;
	

	cout << "...Please enter to menu...";
	cin.get();
	cin.ignore();
	admin();
}


void report() {
	system("cls");
	int ind;
	float total = 0;
	string id_member;
	cout << "Enter ID Member: ";
	cin >> id_member;
	cout<<"-----------------------------------------------------------"<<endl;
	cout << setw(10)<<left<<"ID"<< setw(17)<<left <<"Name"<< setw(10)<<left<<"Prices"<< setw(10)<<left<<"Amout"<< setw(10)<<left<<"Total prices" << endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<endl;
	for (int i = 0; i < 100; i++) {
		if (orders[i][0] == id_member) {
			float total_product = 0;
					
					
			for (int c = 0; c < 100; c++) {
				if (products[c][0] == orders[i][1]) {
					total_product = prices[c][0] * qty[i];
					total += total_product;
					cout << setw(10)<<left<< products[c][0]<< setw(17)<<left << products[c][1] << setw(10)<<left<< prices[c][0] << setw(10)<<left<< qty[i] << fixed << setprecision(2)<< setw(10)<<left<<total_product << endl;
					break;
				}
			}
		}
	}
	
	cout<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout << "Total : " << fixed << setprecision(2) << total <<" baht"<< endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout << "...Please enter to menu...";
	cin.get();
	cin.ignore();
	mainmenu();
}

void admin() {
	system("cls");
	char select;
	cout << "1 = product data 2 = customer data 3 = Back : ";
			cin >> select;
			switch(select)
			{
				case '1':
					report_product();
					break;
				case '2':
					report_members();
					break;
				default:
					mainmenu();
			}
}

void insert_member()
{
	system("cls");
	char select;
	string check_member;
	bool status = true;
	cout << "Enter ID Member : ";
	cin >> check_member;
	for (int i = 0; i < 100; i++) {
		if (members[i][0] == check_member) {
			status = false;
			break;
		}
	}
	if (status == true) {
		for (int c = 0; c < 100; c++) {
			if (members[c][0].empty()) {
				members[c][0] = check_member;
				cout << "Enter Name: ";
				cin.get();
				getline(cin,members[c][1]);
				cout << "Enter Tel: ";
				cin >> members[c][2];
				cout << "Enter Email: ";
				cin >> members[c][3];
				cout << "Insert Member Success"<<endl;
				
				break;
			}
		}
	} else {
		cout << "Have Data In Array\n";
	}
	cout << "...Please enter to menu...";
				cin.get();
				cin.ignore();
				mainmenu();
}
void insert_product()
{
	system("cls");
	string check_product;
	bool status = true;
	char select;
	cout << "Enter ID Product : ";
	cin >> check_product;
	for(int i = 0;i<100;i++)
	{
		if (check_product == products[i][0])
		{
			status = false;
			break;
		}
	}
	if (status == true) {
			for (int j = 0; j < 100; j++) {
				if (products[j][0].empty()) {
					products[j][0] = check_product;
					cout << "Enter Name Product : ";
					cin >> products[j][1]; 
					cout << "Enter Price : ";
					cin >> prices[j][0]; 
					cout << "Enter Stock : ";
					cin >> prices[j][1];
					break;
				}
			}

			
		}
		else
		{
			cout <<"The ID product already have"<<endl;
		}
	cout << "1 = again 2 = back : ";
			cin >> select ;
			switch(select){
				case '1' : 
					insert_product();
					break;
			}
			mainmenu();
	
}
void sell()
{
	system("cls");
	string id_member;
	bool haveproduct = false;
	bool status = false;
	cout<<"Enter member ID : ";
	cin>>id_member;

	for (int i = 0; i < 100; i++) {
		if (members[i][0] == id_member) {
			status = true;
			index = i;
			break;
		}
	}

	if (status == true) {
		sellproduct();
	} else {
		cout << "Not Found ID Member\n";
	}
}

void sellproduct() {
	system("cls");
	int Qty;
	char select;
	bool status4 = false;
	string id_product;
	cout<<"-------------------------------------"<<endl;
	cout <<setw(15)<<left<<"ID"<<setw(15)<<left<<"Product"<<setw(15)<<left<<"Price"<<endl;
	cout<<"-------------------------------------"<<endl<<endl;
	for (int i = 0; i < 100; i++) {
		if (!products[i][0].empty()) {
			cout<<setw(15)<<left<<products[i][0]<<setw(15)<<left<<products[i][1]<<setw(15)<<left << fixed << setprecision(2) <<prices[i][0]<<endl;
		}
	}
	cout<<endl;
	cout<<"-------------------------------------"<<endl;
	for (int i = 0; i < 100; i++) 
	{
		cout << "Hello "<< members[index][1]<<endl;
		break;
	}
	cout << "Select ID Product : ";
	cin >> id_product;
	for (int z = 0; z < 100; z++) {
		if (id_product == products[z][0]) {
			status4 = true;
			break;
		}
	}
	if (status4 == true) {
	cout << "Qty : ";
	cin >> Qty;
	for (int c = 0; c < 100; c++) {
		if (orders[c][0].empty()) {
			
			for (int h = 0; h < 100; h++) {
				if (products[h][0] == id_product) {
					if (prices[h][1] >= Qty) {
						orders[c][0] = members[index][0];
						orders[c][1] = id_product;
						prices[h][1] -= Qty;
						qty[c] = Qty;
						cout << "Buy Success\n";
					} else {
						cout << "Qty Less Stock\n";
					}
					
					break;
				}
			}
			
			break;
		}
	}
	} else {
		cout << "Not Found Data\n";
	}
	cout << "1 = again 2 = back : ";
			cin >> select ;
			switch(select){
				case '1' : 
					sellproduct();
					break;
			}
			mainmenu();
}