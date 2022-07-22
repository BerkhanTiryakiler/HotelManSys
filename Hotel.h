#ifndef HOTEL_H
#define HOTEL_H
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<conio.h>
#include<algorithm>
#include<iomanip>


using namespace std;

class Workers{
	public:
	int No;
	string NaS;
	int Salary;
	int Age;
	string Position;
	string Time;
	string Gender; 
	
	Workers(string,string,int,int,int,string,string);
	
	//set functions
	
	void SetNameandSurname(string);
	void SetNo(int);
	void SetSalary(int);
	void SetGender(string);
	void SetAge(int);
	void SetTime(int);
	void SetPosition(string);
	
	//get functions
	string GetNameandSurname();
	int GetNo();
	string GetEmail();
	string GetGender();
	int GetAge();
	string GetPosition();
	
	//other functions
	void WorkerMenu();//to travel between functions
	void createWorker();//creates worker
	void editWorker();//edits worker using vectors
	void showWorkers();//reads from txt file
	void deleteWorker();//deletes workers from txt file using vectors
	void deleteallWorkers();//deletes all workers
	void assignWorker();//copies worker info and customer name to another file.
	
	
	string toStringW();//transforms all values to string
	void ejectheworkerdata(string);//sends all string values to txt file
	
	
};

class Customers{
	public:
		
    string NameandSurname;
	int IdNo;
	string Email; 
	string Gender;
	int Phone;
	int RoomNo;
	string Date;
	 
	
	Customers(string, int, string, string, int, int, string);
	
	//set functions
	void setNameandSurname(string);
	void setIdNo(int);
	void setEmail(string);
	void setGender(string);
	void setPhone(int);
	void setRoom(int);
	void setDate(string);
	
	//get functions
	string getNameandSurname();
	int getIdNo();
	string getEmail();
	string getGender();
	int getPhone();
	int getRoomNo();
	string getDate();
	
	
	//other functions
	void deleteCustomer();
	void ShowCustomers();
	void createCustomer();
	void editCustomer();
	void deleteallCustomers();
	void CustomerMenu();
	void CalculateCost();
	void RecalculateAv(string,int);
	
	string toStringC();
	void ejecthecustomerdata(string);
    
};
class Rooms{
	public:
		
	string Type;
	int Available;
	int Number;
	
	Rooms(string, int, int);
	
	//get functions
	string getType();
	int getAvailable();
	int getNumber();
	
	//set functions
    void setType(string);
	void setAvailable(int);
	void setNumber(int n);
	
    //other functions
    void RoomMenu();
	void createRoom();
	void editRoom();
	void deleteRoom();
	void ShowRooms();
	void deleteallRooms();
	void changeCosts();
	void roomSelection();
	
	string toStringRo();
	void ejectheroomdata(string);
	
};

class Locations{
	public:
		
	string TypeL;
	int Number;
	int Capacity; 
	
	Locations(string, int, int);
	
	//get functions
	string getType();
	int getNumber();
	int getCapacity();
	
	//set functions
    void setType(string);
	void setCapacity(int);
	void setNumber(int n);
	
    //other functions
    void LocationsMenu();
	void createLocation();
	void editLocation();
	void deleteLocation();
	void ShowLocation();
	void deleteallLocation();
	void assignCustomer();
	
	string toStringL();
	void ejecthelocationdata(string);
	
	
	
};

//other functions: changeauth()(changes password), AuthProcess(), cooldown(adds cooldown to functions)

#endif
