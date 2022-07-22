#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<conio.h>
#include<algorithm>
#include<iomanip>
#include "Hotel.h"
#include <time.h>
#include <Windows.h>
#include <thread>

using namespace std;



	Workers::Workers(string Na, string p, int n, int s, int a, string g,string t){
		NaS=Na;
		Position=p;
		No=n;
		Salary=s;
		Age=a;
		Gender=g;
		Time=t;
	}
	
	
	void Workers::SetNo(int n){
		No=n;
		
	}
	
	void Workers::SetNameandSurname(string ns){
		NaS=ns;
		
	}
	
	void Workers::SetSalary(int s){
		Salary=s;
		
	}
	
	void Workers::SetAge(int a){
		Age=a;
		
	}
	
	void Workers::SetPosition(string p){
		Position=p;
		
	}
	void Workers::SetTime(int t){
		Time=t;
		
	}
	void Workers::SetGender(string g){
		Gender=g;
		
	}
	
	int Workers::GetNo(){
		return Salary;
		
	}
	
	string Workers::GetNameandSurname(){
		return NaS;
		
	}
	
	string Workers::GetGender(){
		return Gender;
		
	}
	
	int Workers::GetAge(){
		return Age;
		
	}
	
	string Workers::GetPosition(){
		return Position;
		
	}
	
	
	
	
	string Workers::toStringW(){
		
	ostringstream output;
	
	output<<endl<<NaS<<endl<<Age<<endl<<No<<endl<<Gender<<endl<<Position<<endl<<Salary<<endl<<Time;
	
	return output.str();
		
	}
	
	
	void Workers::ejectheworkerdata(string x){
	ofstream doc;
	doc.open("Workers.txt", ios::app);
	doc<<x;
	doc.close();
}
	
	
	void Workers::createWorker(){
		system("CLS");
		int g=0;
		
		vector<string> v1;
	string str;
	ifstream work("Workers.txt");
	while(getline (work, str)) {
	v1.push_back(str);
	}	
work.close();

		cout<<"Enter Name and Surname(x.x) :"<<endl;
		cin>>NaS;
		
		
		cout<<"Enter Age:"<<endl;
		cin>>Age;
		
		while(g==0){
		cout<<"Enter Id No:"<<endl;
		cin>>No;
		string strr= to_string(No);
		auto a=find(v1.begin(), v1.end(), strr);
		if(a!=v1.end()){
			cout<<"Same id cannot be exist"<<endl;
		}
		
		else if(a==v1.end()){
			g=1;
		}
		
	}
		
	
	
	
		
		cout<<"Enter Gender:"<<endl;
		cin>>Gender;
		cout<<"Enter Position:"<<endl;
		cin>>Position;
		cout<<"Enter Salary(€):"<<endl;
		cin>>Salary;
		cout<<"Enter Working Hours(xx.xx-xx.xx):"<<endl;
		cin>>Time;
	
		
	
		
		
		ejectheworkerdata(toStringW());
		
		cout<<"Process Completed"<<endl;		
	 cout<<"Press anything to continue"<<endl;
	 getch();
		
		
		exit;
	}
	
	
	
	void Workers::editWorker(){	
		
		vector<string> v1;
	string str, strF, strR,Name;
	ifstream work("Workers.txt");
	while(getline (work, str)) {
	v1.push_back(str);
	}	
work.close();

showWorkers();


cout<<"Enter the name of the worker:"<<endl;
		cin>>Name;

cout<<endl<<"Type the word that you want to change : "<<endl;
cin>>strF;


auto n = find(v1.begin(), v1.end(), Name);

		
auto f = find(n, n+7, strF);


cout<<endl<<"Replace with : "<<endl;
cin>>strR;

if (f != v1.end()){

    *f = strR;

}



deleteallWorkers();


ofstream doc1;
	doc1.open("Workers.txt", ios::app);
	for(auto y1 : v1){
	
	doc1<<endl<<y1;
	
}
	doc1.close();





	}
	
	
	
	
	
	void Workers::deleteWorker(){
		
		vector<string> v2;
		showWorkers();
		string str, Name;
	ifstream work("Workers.txt");
	while(getline (work, str)) {
	v2.push_back(str);
	}	
    work.close();



		cout<<"Enter the name of the worker:"<<endl;
		cin>>Name;
		
		
		auto f = find(v2.begin(), v2.end(), Name);
		
		v2.erase(f,f+7);
		
		
		
		deleteallWorkers();
		
     ofstream doc1;
	 doc1.open("Workers.txt", ios::app);
	 for(auto y1 : v2){
	 doc1<<endl<<y1;
     }
	 doc1.close();
		
		
		
		cout<<"Process Completed"<<endl;		
	 cout<<"Press anything to continue"<<endl;
	 getch();	
	 }
	
	
void Workers::deleteallWorkers(){
	
ofstream ofs;
ofs.open("Workers.txt", ofstream::out | ofstream::trunc);
ofs.close();



}
	
	
	
	
	
	
	void Workers::showWorkers(){
	cout<<endl;
	string Workers;
	ifstream read("Workers.txt");
	while(!read.eof()){
	read>>Workers;
	cout<<"Name and Surname:"<<Workers<<endl;
	read>>Workers;
	cout<<"Age:"<<Workers<<endl;
	read>>Workers;
	cout<<"Id No:"<<Workers<<endl;
	read>>Workers;
	cout<<"Gender:"<<Workers<<endl;
	read>>Workers;
	cout<<"Position:"<<Workers<<endl;
	read>>Workers;
	cout<<"Salary:"<<Workers<<endl;
	read>>Workers;
	cout<<"Working hours:"<<Workers<<endl;
    cout<<"***"<<endl;
}
read.close();	
	
			

	
}

void Workers::WorkerMenu(){
	system("CLS");
	int select;
	

	
	while(select!=6){
	
	cout<<endl<<"1-| Add a Worker"<<endl<<"2-| Edit a Workers Information"<<endl<<"3-| Delete a Worker"<<endl<<"4-| Delete all Workers"<<endl<<"5-| Show all Workers"<<endl<<"6-| Assign Worker to a customer"<<endl<<"7-| Go back"<<endl;
cout<<"Select to continue."<<endl;
cin>>select;
	
	
	switch(select){
		
		case 1:
		system("CLS");
		createWorker();
		system("CLS");
		
		break;
		
		case 2:
		system("CLS");
		editWorker();
		system("CLS");
		
		break;
		
		
		case 3:
		system("CLS");
		deleteWorker();
		system("CLS");
	
		break;
		
		
		
		case 4:
			system("CLS");
		deleteallWorkers();
		cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();
		
		system("CLS");
		
			
		break;
		
		
		
		case 5:
		system("CLS");
		showWorkers();
		cout<<"Press anything to continue"<<endl;
	    getch();
		system("CLS");
			
		break;
		
		
		case 6:
		assignWorker();
		system("CLS");
		break;
		
	case 7:
		exit;
		system("CLS");
		break;	
		
	}
	
}


}


  void Workers::assignWorker(){
  	 		vector<string> v1;
 		vector<string> v3;
 		vector<string> v7;
 		vector<string> v8;
	string strf,Name1, Name,str;
	ifstream work("Workers.txt");
	while(getline (work, strf)) {
	v1.push_back(strf);
	}	
work.close();

	system("CLS");
		
	
showWorkers();


cout<<"Enter the name of the worker:"<<endl;
		cin>>Name1;
		
auto n = find(v1.begin(), v1.end(), Name1);


	ifstream Custmr("Customers.txt");
	while(getline (Custmr, str)) {
	v3.push_back(str);
	}	
Custmr.close();

cout<<endl;
	string Res;
	ifstream read("Customers.txt");
	while(!read.eof()){
	read>>Res;
	cout<<"Name and Surname:"<<Res<<endl;
	read>>Res;
	cout<<"Age:"<<Res<<endl;
	read>>Res;
	cout<<"Id No:"<<Res<<endl;
	read>>Res;
	cout<<"Gender:"<<Res<<endl;
	read>>Res;
	cout<<"Phone:"<<Res<<endl;
	read>>Res;
	cout<<"Room Number:"<<Res<<endl;
	read>>Res;
	cout<<"Date:"<<Res<<endl;
	cout<<"***"<<endl;

cout<<"Enter the name of the customer:"<<endl;
		cin>>Name;


auto c = find(v3.begin(), v3.end(), Name);

copy(c,c+1,v7.begin());
copy(n,n+7,v8.begin());

     ofstream doc1;
	doc1.open("AssignedW.txt", ios::app);
	for(auto y1 : v8){
	
	doc1<<endl<<y1;
	
}
	doc1.close();
 	
 	ofstream doc2;
	doc2.open("AssignedW.txt", ios::app);
	for(auto y2 : v7){
	
	doc1<<endl<<y2;
	
}
	doc1.close();
 	
 	
 	
 	
 	
 }

}


	  Customers::Customers(string N, int i, string e, string g, int p, int r, string d){
	  	
	  	NameandSurname=N;
	  	IdNo=i;
	  	Email=e;
	  	Gender=g;
	  	Phone=p;
	  	RoomNo=r;
	  	Date=d;
	  } 
	   
	void Customers:: setNameandSurname(string n){
		NameandSurname=n;
	}
	
	void Customers:: setIdNo(int i){
		
		IdNo= i;
		
	}
	
	void Customers:: setEmail(string e){
		
		Email=e;
		
	}
	
	void Customers:: setGender(string g){
		
		Gender=g;
		
	}
	
	void Customers:: setPhone(int p){
		
		Phone=p;
		
	}
	
	void Customers:: setRoom(int r){
		
		RoomNo=r;
		
	}
	
	void Customers:: setDate(string d){
		
		Date=d;
		
	}
	
	string Customers::getNameandSurname(){
		
		return NameandSurname;
		
	}
	
	int Customers::getIdNo(){
		
		return IdNo;
		
	}
	
	string Customers::getEmail(){
		return Email;
	}
	
	string Customers::getGender(){
		return Gender;
	}
	
	int Customers::getPhone(){
		return Phone;
	}
	   
	   int Customers::getRoomNo(){
		return RoomNo;
	}
	   
	 string Customers::getDate(){
		return Date;
	}  
	   
	   
	   
	   
	   
	string Customers::toStringC(){
		
	ostringstream output;
	
	output<<endl<<NameandSurname<<endl<<IdNo<<endl<<Email<<endl<<Gender<<endl<<Phone<<endl<<RoomNo<<endl<<Date;
	
	return output.str();
		
	}
	
	
	void Customers::ejecthecustomerdata(string x){
	ofstream doc;
	doc.open("Customers.txt", ios::app);
	doc<<x;
	doc.close();
}
	   
	void Customers::createCustomer(){
		int g=0;
		int b=0;
		
			vector<string> v1;
	string str,RoomType;
	ifstream customers("Customers.txt");
	while(getline (customers, str)) {
	v1.push_back(str);
	}	
customers.close();
		
		
		cout<<"Enter Name and Surname :"<<endl;
		cin>>NameandSurname;
		
		while(g==0){
		cout<<"Enter Id No(11 characters):"<<endl;
		cin>>IdNo;
		string strr= to_string(IdNo);
		auto a=find(v1.begin(), v1.end(), strr);
		if(a!=v1.end()){
			cout<<"Same id cannot be exist"<<endl;
		}
		
		else if(a==v1.end()){
			g=1;
		}
		
	}
		
		cout<<"Enter Email:"<<endl;
		cin>>Email;
		cout<<"Enter Gender:"<<endl;
		cin>>Gender;
		cout<<"Enter phone(5xx-xxx-xx-xx):"<<endl;
		cin>>Phone;
		while(b==0){
	    cout<<"Enter Room Number(0-300):"<<endl;
		cin>>RoomNo;
		string strrr= to_string(RoomNo);
		auto f=find(v1.begin(), v1.end(), strrr);
		if(f!=v1.end()){
			cout<<"Same id cannot be exist"<<endl;
		}
		
		else if(f==v1.end()){
			b=1;
		}
		
	}
		cout<<"Enter Room Number(0-300):"<<endl;
		cin>>RoomType;
		
	
		cout<<"Enter Date(DD,MM,YYYY-DD,MM,YYYY):"<<endl;
		cin>>Date;
		ejecthecustomerdata(toStringC());
		
	cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();
		
	}
	
	
	
	void Customers::editCustomer(){
		system("CLS");
		
			vector<string> v3;
	string str, strF, strR, Name;
	ifstream Custmr("Customers.txt");
	while(getline (Custmr, str)) {
	v3.push_back(str);
	}	
Custmr.close();

ShowCustomers();

cout<<"Enter the name of the customer:"<<endl;
		cin>>Name;
		
		
		auto n = find(v3.begin(), v3.end(), Name);


cout<<endl<<"Type the word that you want to change : "<<endl;
cin>>strF;

auto f = find(n, n+7, strF);

cout<<endl<<"Replace with : "<<endl;
cin>>strR;

if (f != v3.end()){

    *f = strR;

}

deleteallCustomers();
system("CLS");
ofstream doc1;
	doc1.open("Customers.txt", ios::app);
	for(auto y1 : v3){
	
	doc1<<endl<<y1;
	
}
	doc1.close();
	
	cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();
	
	}
	
	
	
	void Customers::deleteCustomer(){
		system("CLS");
			vector<string> v4;
		ShowCustomers();
		string str, Name;
	ifstream work("Customers.txt");
	while(getline (work, str)) {
	v4.push_back(str);
	}	
work.close();



		cout<<"Enter the name of the customer:"<<endl;
		cin>>Name;
		
		
		auto f = find(v4.begin(), v4.end(), Name);
		
		v4.erase(f,f+7);
		
		
		
		deleteallCustomers();
		
		
ofstream doc1;
	doc1.open("Customers.txt", ios::app);
	for(auto y1 : v4){
	
	doc1<<y1<<endl;
	
}
	doc1.close();
			
	cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();		
			
			
	}
	
	
	
void Customers::deleteallCustomers(){
	
ofstream ofs;
ofs.open("Customers.txt", ofstream::out | ofstream::trunc);
ofs.close();
}    	   
	   
	void Customers::ShowCustomers(){
	cout<<endl;
	string Res;
	ifstream read("Customers.txt");
	while(!read.eof()){
	read>>Res;
	cout<<"Name and Surname:"<<Res<<endl;
	read>>Res;
	cout<<"Age:"<<Res<<endl;
	read>>Res;
	cout<<"Id No:"<<Res<<endl;
	read>>Res;
	cout<<"Gender:"<<Res<<endl;
	read>>Res;
	cout<<"Phone:"<<Res<<endl;
	read>>Res;
	cout<<"Room Number:"<<Res<<endl;
	read>>Res;
	cout<<"Date:"<<Res<<endl;
	cout<<"***"<<endl;
	
}

}
void Customers::CustomerMenu(){
	
	int select;
	while(select!=6){
cout<<endl<<"1-| Add a Customer"<<endl<<"2-| Edit a Customer"<<endl<<"3-| Delete a Customer"<<endl<<"4-| Delete all Customers"<<endl<<"5-| Show all Customers"<<endl<<"6-| Go Back"<<endl<<endl;
cout<<"Select to continue."<<endl;
cin>>select;
	
	
	switch(select){
		
		case 1:
		system("CLS");
		createCustomer();
		system("CLS");
		break;
		
		case 2:
		system("CLS");
		editCustomer();
		
		cout<<"Press anything to continue"<<endl;
	getch();
	system("CLS");
		break;
		
		case 3:
		system("CLS");
		deleteCustomer();
		
		break;
		
		case 4:
		system("CLS");
		deleteallCustomers();
		system("CLS");	
			
		break;
		
		case 5:
		system("CLS");
		ShowCustomers();
		
		cout<<"Press anything to continue"<<endl;
	getch();
		system("CLS");	
		break;
		
		case 6:
		exit;
		system("CLS");
		break;
		
	}




}






}
/*
void Customers::CalculateCost(string RoomTy){
	
	int cost;
	
	
	
	if (RoomTy==''){
		
		cost+=
		
	}
	
	else if (RoomN<150 && Room){
		
		cost+=
		
	}	
	
	
	
}*/
/*
void Customers::RecalculateAv(string RoomT, int x){
	int j;
	vector<string> v1;
	string str;
	ifstream customers("Customers.txt");
	while(getline (customers, str)) {
	v1.push_back(str);
	}	
customers.close();
	
	
	auto t=find(v1.begin(),v1.end(),RoomT);
	
	auto y=find(t,t+2,x);

	if (y != v1.end()){

    *y = strR;

}
	
	
}*/


	
	Rooms::Rooms(string T, int A, int N){
		Type=T;
		Number=N;
		Available=A;
	}
	
	string Rooms::getType(){
		
		return Type;
		
	}
	
	int Rooms::getAvailable(){
		
		return Available;
		
	}
	
	
	int Rooms::getNumber(){
		
		return Number;
		
	}
	
	
	void Rooms::setType(string t){
		Type=t;
	}
	
	void Rooms::setAvailable(int a){
		Available=a;
	}
	
	void Rooms::setNumber(int n){
		Number=n;
	}
	
	string Rooms::toStringRo(){
		
	ostringstream output;
	
	output<<endl<<Type<<endl<<Number<<endl<<Available;
	
	return output.str();
		
	}
	
	void roomSelection(){
		
	}
	
	void Rooms::ejectheroomdata(string x){
	ofstream doc;
	doc.open("Rooms.txt", ios::app);
	doc<<x;
	doc.close();
}
	
	
	void Rooms::createRoom(){
		
			int g=0;
			vector<string> v1;
	string str;
	ifstream rooms("Rooms.txt");
	while(getline (rooms, str)) {
	v1.push_back(str);
	}	
rooms.close();
		
		while(g==0){
		cout<<"Enter Room Type(Economic.Single- Lux.Multiple etc.) :"<<endl;
		cin>>Type;
		auto a=find(v1.begin(), v1.end(), Type);
		if(a!=v1.end()){
			cout<<"Same id cannot be exist"<<endl;
		}
		
		else if(a==v1.end()){
			g=1;
		}
		
	}
		
		
		cout<<"Enter Number:"<<endl;
		cin>>Number;
		cout<<"Enter Amount of Availabile room:"<<endl;
		cin>>Available;
		ejectheroomdata(toStringRo());
		cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();
		
	}
	
	
	
	void Rooms::editRoom(){
		
			vector<string> v6;
	string str, strF, strR,Room;
	ifstream Roomf("Room.txt");
	while(getline (Roomf, str)) {
	v6.push_back(str);
	}	
Roomf.close();

ShowRooms();



		cout<<"Enter the type of the room:"<<endl;
		cin>>Room;
		
		
		auto n = find(v6.begin(), v6.end(), Room);


cout<<endl<<"Type the word that you want to change : "<<endl;
cin>>strF;

auto f = find(n, n+3, strF);

cout<<endl<<"Replace with : "<<endl;
cin>>strR;

if (f != v6.end()){

    *f = strR;

}

deleteallRooms();

ofstream doc1;
	doc1.open("Customers.txt", ios::app);
	for(auto y1 : v6){
	
	doc1<<y1<<endl;
	
}
	doc1.close();
		
		cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();
		
	}
	
	
	
	void Rooms::deleteRoom(){
		
			vector<string> v4;
		ShowRooms();
		string str, Room;
	ifstream work("Customers.txt");
	while(getline (work, str)) {
	v4.push_back(str);
	}	
work.close();



		cout<<"Enter the type of the room:"<<endl;
		cin>>Room;
		
		
		auto f = find(v4.begin(), v4.end(), Room);
		
		v4.erase(f,f+3);
		
		
		
		deleteallRooms();
		
		
ofstream doc1;
	doc1.open("Customers.txt", ios::app);
	for(auto y1 : v4){
	
	doc1<<endl<<y1;
	
}
	doc1.close();
		
	
	
	cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();
		
		
	}
	
	
	





void Rooms::deleteallRooms(){
	
ofstream ofs;
ofs.open("Rooms.txt", ofstream::out | ofstream::trunc);
ofs.close();



}
	
	
	void Rooms::ShowRooms(){
		cout<<endl;
	string ro;
	ifstream read("Rooms.txt");
	while(!read.eof()){
	read>>ro;
	cout<<"Type:"<<ro<<endl;
	read>>ro;
	cout<<"Number:"<<ro<<endl;
	read>>ro;
	cout<<"Available:"<<ro<<endl;
	read>>ro;
	cout<<"***"<<endl;
	
}




}
void Rooms::RoomMenu(){
	system("CLS");
	int select;
	

	
	
	while(select!=6){
	
	cout<<endl<<"1-| Add a Room Category"<<endl<<"2-| Edit a Room Category"<<endl<<"3-| Delete a Room Category"<<endl<<"4-| Delete all Rooms"<<endl<<"5-| Show all Rooms"<<endl<<"6-| Go Back"<<endl<<endl;
cout<<"Select to continue."<<endl;
cin>>select;
	
	
	switch(select){
		
		case 1:
		system("CLS");
		createRoom();
		system("CLS");
		break;
		
		case 2:
		system("CLS");
		editRoom();
		system("CLS");
		break;
		
		
		case 3:
		system("CLS");
		deleteRoom();
		system("CLS");
		break;
		
		
		
		case 4:
			system("CLS");
		deleteallRooms();
		cout<<"Process Completed"<<endl;		
cout<<"Press anything to continue"<<endl;
getch();
			system("CLS");
			
		break;
		
		
		
		case 5:
			system("CLS");
		ShowRooms();		
	cout<<"Press anything to continue"<<endl;
	getch();
			system("CLS");
		break;
		
		case 6:
		exit;
		system("CLS");
		break;
		
	}
	
	
	
	
}
}


	
	Locations::Locations(string T, int A, int N){
		TypeL=T;
		Number=N;
		Capacity=A;
	}
	
	string Locations::getType(){
		
		return TypeL;
		
	}
	
	int Locations::getCapacity(){
		
		return Capacity;
		
	}
	
	
	int Locations::getNumber(){
		
		return Number;
		
	}
	
	
	void Locations::setType(string t){
		TypeL=t;
	}
	
	void Locations::setCapacity(int a){
		Capacity=a;
	}
	
	void Locations::setNumber(int n){
		Number=n;
	}
	
	string Locations::toStringL(){
		
	ostringstream output;
	
	output<<endl<<TypeL<<endl<<Number<<endl<<Capacity;
	
	return output.str();
		
	}
	
	
	void Locations::ejecthelocationdata(string x){
	ofstream doc;
	doc.open("Locations.txt", ios::app);
	doc<<x;
	doc.close();
}
	
	
	void Locations::createLocation(){
		
			int g=0;
			vector<string> v1;
	string str;
	ifstream rooms("Locations.txt");
	while(getline (rooms, str)) {
	v1.push_back(str);
	}	
rooms.close();
		
		while(g==0){
		cout<<"Enter Location Type(Restourant-Pool.) :"<<endl;
		cin>>TypeL;
		auto a=find(v1.begin(), v1.end(), TypeL);
		if(a!=v1.end()){
			cout<<"Same id cannot be exist"<<endl;
		}
		
		else if(a==v1.end()){
			g=1;
		}
		
	}
		
		
		cout<<"Enter Number:"<<endl;
		cin>>Number;
		cout<<"Enter Amount of Availabile room:"<<endl;
		cin>>Capacity;
		ejecthelocationdata(toStringL());
		cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();
		
	}
	
	
	
	void Locations::editLocation(){
		
			vector<string> v6;
	string str, strF, strR,Room;
	ifstream Roomf("Locations.txt");
	while(getline (Roomf, str)) {
	v6.push_back(str);
	}	
Roomf.close();

ShowLocation();



		cout<<"Enter the type of the room:"<<endl;
		cin>>Room;
		
		
		auto n = find(v6.begin(), v6.end(), Room);


cout<<endl<<"Type the word that you want to change : "<<endl;
cin>>strF;

auto f = find(n, n+3, strF);

cout<<endl<<"Replace with : "<<endl;
cin>>strR;

if (f != v6.end()){

    *f = strR;

}

deleteallLocation();

ofstream doc1;
	doc1.open("Locations.txt", ios::app);
	for(auto y1 : v6){
	
	doc1<<y1<<endl;
	
}
	doc1.close();
		
		cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();
		
	}
	
	
	
	void Locations::deleteLocation(){
		
			vector<string> v4;
		ShowLocation();
		string str, Room;
	ifstream work("Locations.txt");
	while(getline (work, str)) {
	v4.push_back(str);
	}	
work.close();



		cout<<"Enter the type of the room:"<<endl;
		cin>>Room;
		
		
		auto f = find(v4.begin(), v4.end(), Room);
		
		v4.erase(f,f+3);
		
		
		
		deleteallLocation();
		
		
ofstream doc1;
	doc1.open("Locations.txt", ios::app);
	for(auto y1 : v4){
	
	doc1<<endl<<y1;
	
}
	doc1.close();
		
	
	
	cout<<"Process Completed"<<endl;		
	cout<<"Press anything to continue"<<endl;
	getch();
		
		
	}
	
	
	





void Locations::deleteallLocation(){
	
ofstream ofs;
ofs.open("Locations.txt", ofstream::out | ofstream::trunc);
ofs.close();



}
	
	
	void Locations::ShowLocation(){
		cout<<endl;
	string ro;
	ifstream read("Locations.txt");
	while(!read.eof()){
	read>>ro;
	cout<<"Type:"<<ro<<endl;
	read>>ro;
	cout<<"Number:"<<ro<<endl;
	read>>ro;
	cout<<"Capacity:"<<ro<<endl;
	read>>ro;
	cout<<"***"<<endl;
	
}




}
void Locations::LocationsMenu(){
	system("CLS");
	int select;
	

	
	
	while(select!=7){
	
	cout<<endl<<"1-| Add a Location Category"<<endl<<"2-| Edit a Location Category"<<endl<<"3-| Delete a Location Category"<<endl<<"4-| Delete all Location"<<endl<<"5-| Show all Location"<<endl<<"6-| Assign customer to a Location"<<endl<<"7-| Go Back"<<endl<<endl;
cout<<"Select to continue."<<endl;
cin>>select;
	
	
	switch(select){
		
		case 1:
		system("CLS");
		createLocation();
		system("CLS");
		break;
		
		case 2:
		system("CLS");
		editLocation();
		system("CLS");
		break;
		
		
		case 3:
		system("CLS");
		deleteLocation();
		system("CLS");
		break;
		
		
		
		case 4:
			system("CLS");
		deleteallLocation();
		cout<<"Process Completed"<<endl;		
cout<<"Press anything to continue"<<endl;
getch();
			system("CLS");
			
		break;
		
		
		
		case 5:
			system("CLS");
		ShowLocation();		
	cout<<"Press anything to continue"<<endl;
	getch();
			system("CLS");
		break;
		
		
			case 6:
			system("CLS");
		assignCustomer();		
	cout<<"Press anything to continue"<<endl;
	getch();
			system("CLS");
		break;
		
		
		
		case 7:
		exit;
		system("CLS");
		break;
		
	}
	
	
	
	
}
}

  void Locations::assignCustomer(){
 		vector<string> v1;
 		vector<string> v8;
	string strf,Name;
	ifstream work("Customers.txt");
	while(getline (work, strf)) {
	v1.push_back(strf);
	}	
work.close();

	system("CLS");
		

cout<<"Enter the name of the Customer:"<<endl;
		cin>>Name;
		
auto n = find(v1.begin(), v1.end(), Name);

copy(n,n+6,v8.begin());





	vector<string> v3;
	string str;
	ifstream Custmr("Locations.txt");
	while(getline (Custmr, str)) {
	v3.push_back(str);
	}	
Custmr.close();



cout<<"Enter the name of the customer:"<<endl;
		cin>>Name;


auto c = find(v1.begin(), v1.end(), Name);

copy(n,n+1,v8.end());

     ofstream doc1;
	doc1.open("AssignedC.txt", ios::app);
	for(auto y1 : v8){
	
	doc1<<endl<<y1;
	
}
	doc1.close();
 	
 	
 	
 	
 	
 	
 	
 }


void Cooldown(int seconds){
	
    Sleep(1000);
    while (seconds >= 1)
    {
        cout << "\rTime remaining: " << seconds << flush;
        Sleep(1000);
        seconds--;
    }
		
}






void changeAuth(){

string NUsername, NPassword;
	
ofstream ofss;
ofss.open("AuthorizationProcess.txt", ofstream::out | ofstream::trunc);
ofss.close();
	
	cout<<"Enter new username:"<<endl;
	cin>>NUsername;
	cout<<endl<<"Enter new Password:"<<endl;
	cin>>NPassword;
	
	ofstream doc;
	doc.open("AuthorizationProcess.txt", ios::app);
	doc<<NUsername<<endl<<NPassword;
	doc.close();
	
	cout<<endl<<"Press anything to go back";
	getch();
	
	
}





int AuthorizationProcess(){
	

	string Username;
	string Password;
	string UsernameFile;
	string PasswordFile;
	int access = 0;
	int c = 0;
	
	ifstream verify("AuthorizationProcess.txt", ios::in);
	verify.close();
	if(!verify){
		changeAuth();
		
	}

	
	
	
	
	while(access==0){
	

	
	cout<<"Please type your username and password:"<<endl<<endl<<"Username : ";
	cin>>Username;
	
	cout<<endl<<"Password : ";
	cin>>Password;
	
	ifstream auth;
	auth.open("AuthorizationProcess.txt", ios::in);
	
	auth>>UsernameFile>>PasswordFile;
	
	
	
	
	if(Username == UsernameFile && Password == PasswordFile){
		access=1;
		
		cout<<endl<<"Welcome Sir!"<<endl<<endl<<"Press enter to continue."<<endl;
		
		getch();
		
		return 1;
		break;
	}
	
	
	
	
	else if (Username != UsernameFile || Password != PasswordFile){
		
		cout<<endl<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl<<"Invaild Username or Password"<<endl<<endl;
		
		c++;
		
		
		
		getch();
		
		system("CLS");
	}
	
	
	
	
	if(c==3){
		
		cout<<endl<<endl<<"Too many attempts caused system lockdown."<<endl<<endl;
		getch();
		access=2;
	 return 0;
	 break;
		exit;
	}
	
	
	
}


exit;

}






int main(){
	int select;
	string Na,p,g,T,N2,e,g2,d,ti,lna;
	int n,s,a,N,i,p2,r,A,ln,lc;
	
	Workers w1(Na, p, n, s, a, g,ti);
	Rooms r1(T, A, N);
	Customers c1(N2, i, e, g2, p2, r, d);
	Locations L1(lna,ln,lc);
	cout<<"Hotel Mangement System"<<endl<<endl;
	
	if(AuthorizationProcess()==1){
		
	system("CLS");
	
	while(select!=6) {
		
		
cout<<"Macco Babu Hotel"<<endl<<"Since 1908 - Izmir"<<endl<<endl;
		
		
	
cout<<"*********************************************************************************************************"<<endl;


cout<<endl<<"1-| Manage Workers"<<endl<<"2-| Access Customers"<<endl<<"3-| Control Rooms"<<endl<<"4-| Change Username and Password"<<endl<<"5-| A Close Look to Locations"<<endl<<endl<<"Press 6 to shutdown the system"<<endl<<endl;
cout<<"Select to continue."<<endl;
cin>>select;

	switch (select){
		
		case 1:
		system("CLS");
		
		w1.WorkerMenu();
		Cooldown(60);
		break;
	
		case 2:
		system("CLS");
		c1.CustomerMenu();
		system("CLS");
		break;	
	
		
		case 3:
		system("CLS");
		r1.RoomMenu();
		system("CLS");
		break;
		
		case 4:
		system("CLS");
		changeAuth();
		system("CLS");	
		break;
		
		
		case 5:
		
		L1.LocationsMenu();
		
		case 6:
			break;
		
		default:
			
		cout<<"Invalid Choice"<<endl;	
			getch();
	system("CLS");
}



}
			
	}
	
	
	
	else {
	
	return 0;
	}
	
	
	

}
	

