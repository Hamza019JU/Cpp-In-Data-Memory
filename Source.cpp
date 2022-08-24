#include<iostream>
#include<fstream>
#include<sstream>      //Choose the best sorting algorethem using Cpp //implementation //Decumentation
#include<string>
using namespace std;
const int n = 5;      //this variable to  dtermine the size of the Informations    /*/
class Info {
private:
	string name[n];
	int age[n];
	int rows[n];
public:
	string GetName(int *rows) {  //function to enter a name of the Person ((Info type))
		cout << "Name : ";
		cin >> name[*rows];
		return name[*rows];
	}
	int GetAge(int *rows ) {  //function to enter an age of the Person ((Info type))
		cout << "Age : ";
		cin >> age[*rows];
		return age[*rows];
	}
	int GetNumber(int *Rrows) { //function to get an Regestration number of the Person 
		rows[*Rrows] = *Rrows;
		return rows[*Rrows];	
	}
	string PrintInfo(int *in_row) {   // Function to print a specifice Information of someone  
		stringstream ss;              // used here to print in file  
		ss << rows[*in_row]; 
		ss << " .";
		ss << name[*in_row];
		ss << " || ";	
		ss << age[*in_row] << endl;
		return ss.str();
	}
	void Search_Process_Info(int *reg_number) {        // Function to search by using Regestration number   
		for (int i = 0; i < n; i++) {
			if (rows[i] == *reg_number) {
				break;
			}
		} 
		cout << rows[*reg_number] << " ." << name[*reg_number] << " || " << age[*reg_number] << endl;
	}
	void Search_Process_Info_name(string* nameReg) {      // Function to search by using Regestration name    
		int i;
		for ( i = 0; i < n; i++) {
			if (name[i] == *nameReg) {
				cout << rows[i] << " ." << name[i] << " || " << age[i] << endl;
				break;
			}
		}
	}
	void Search_Process_Info_age(int *ageReg) {           // Function to search by using Regestration Age   
		for (int i = 0; i < n; i++) {
			if (age[i] == *ageReg) {
				cout << rows[i] << " ." << name[i] << " || " << age[i] << endl;
				break;
			}
		}
	}
	void Edit_Process(int reg_number,string* regName, int* regAge) {         // Function to edit a previose Info of some one by using Reg.Nu. only
		for (int i = 0; i < n; i++) {
			if (rows[i] == reg_number) {
				cout << "Name : ";
				cin >> *regName;
				name[i] = *regName;
				cout << "Age : ";
				cin >> *regAge;
				age[i] = *regAge;
				cout << rows[i] << " ." << name[i] << " || " << age[i] << endl;
				break;
			}
		}
	}
	void Del(int reg_number) {             // Delel an previose information and replace the name with empty and Age with 0
		for (int i = 0; i < n; i++) {
			if (rows[i] == reg_number) {
				name[i] = "";
				age[i] = 0;
				cout << rows[i] << " ." << name[i] << " || " << age[i] << endl;
				break;
			}
		}
	}
};
void Welcome_Choose() {        //procces to show the user the services that we offer 
	cout << "wellcome to our site" << endl;
	cout << "What kind of servises can we help " << endl;
	cout << "Enter the number of the service\n==========================" << endl;
	cout << "1. add information " << endl;
	cout << "2. Search for Info  " << endl;
	cout << "3. edit information " << endl;
	cout << "4. Delete information " << endl;
	cout << "5. Exit " << endl;
}
void Choose_type() {      // used in Search process to determine the search method
	cout << "Can you enter the number of your info : "<<endl;
	cout << "1. ID number" << endl;
	cout << "2. Name" << endl;
	cout << "3. Age" << endl;
}
int main() {
	ofstream outfile("D:\\Cpp projects\\In data base memory\\source.txt");     // Creat a file to print the information in it 
	outfile << "No." << "||" << "Studen " << "||" << "Age " << endl;           // Print in the file
	Info Person[n];                           //Creat a Info variable arrey containa the Information for each Person 
	Welcome_Choose();  //show options for the user 
	int No_of_serv;                           // the Number of sevice that user enter it
	int* P_No_of_serv = &No_of_serv;          // create a location in the system that specialize for the number of service on only
	cin >> No_of_serv;
	int No_of_rows = 0; //This Varian=ble is used to dertermine the reg number of the data
	int Updated_Reg;  //This variable to determine the Reg Number of the data that the user want to upgrade 
	int regNo;          // Reg.Num. of the data 
	string RegName;     // Reg.Name. of the data 
	int regAge;         // Reg.Age. of the data 
	while (No_of_serv != 0) {      //While The Number of service is not zero ((AND IT WILL NEVER BE)) repeat the followin 
		switch (No_of_serv){       
		case 1:        // Add Information
			if (No_of_rows == n) {                                  //If the user enter Information multible time and reach 
				cout << "the memory is completly full " << endl;    //the limit of number of data the procesing of adding
				break;                                              //information will be stoped and return to the chosing process
			}
			cout << "Please enter the name and the age: " << endl;
			Person[No_of_rows].GetNumber(&No_of_rows);                 //Verify regestration number
			Person[No_of_rows].GetName(&No_of_rows);                        //Enter the name
			Person[No_of_rows].GetAge(&No_of_rows);                         //Enter the age 
			Person[No_of_rows].Search_Process_Info(&No_of_rows);   //This process used to show what the user enter    
			No_of_rows++;                                                   //Add 1 to prepare a place in Info array for the up comming Info
			break;
		case 2:      // Search 
			Choose_type();         // Show the methodes of searching 
			cin >> Updated_Reg;    //1.Reg.Nu 2.Name 3.Age
			switch (Updated_Reg) {
			case 1:     //search using regestration number
				cout << "Please enter the Regisration Number : ";
				cin >> regNo;  
				if (regNo >= n) {
					cout << "The regestration Number is Not Available " << endl;}
				else{
				Person[regNo].Search_Process_Info(&regNo);
				}
				break;
			case 2:     //search using regestration name
				cout << "Please enter the Regisration Name : ";
				cin >> RegName;
				for (int i = 0; i < n; i++) {
					Person[i].Search_Process_Info_name(&RegName);
				}
				break;
			case 3:     // Search using regestration age
				cout << "Please enter the Regisration Age : ";
				cin >> regAge;
				for (int i = 0; i < n; i++) {
					Person[i].Search_Process_Info_age(&regAge);
				}
				break;
			}
			break;
		case 3:                // Edit Information
			cout << "Enter the regestration number : ";
			cin >> regNo;      // Enter the Reg No of the wanted Info to be updated
			if (regNo > n - 1) {
				cout << "The regestration Number is Not Available " << endl;}
			cout << "The Information that you want to edit " << endl;
			Person[regNo].Search_Process_Info(&regNo);
			cout << "The new Information that you want to upgrade : " << endl;
			cout << endl << "The new Information : " << endl;
			Person[regNo].Edit_Process(regNo, &RegName, &regAge);
			cout << endl;
			break;
		case 4:               //Delete Information
			cout << "The Information that you want to DELETE " << endl;
			cout << "Enter the regestration number : ";
			cin >> regNo;      // Enter the Reg No of the wanted Info to be updated
			if (regNo > n - 1) {
				cout << "The regestration Number is Not Available " << endl;}
			Person[regNo].Del(regNo);
			cout << endl;
			break;
		case 5:              // EXIT
			for (regNo = 0; regNo < n; regNo++) {
				outfile << Person[regNo].PrintInfo(&regNo);}
			cout << "Thank you for your time" << endl;
			outfile.close();
		}
		cout << "Do you need anything else?\n1. YES \n2. NO " << endl;
		cin >> *P_No_of_serv;        //the User choose between continue or quit 
		if (*P_No_of_serv == 2) {
			for (regNo = 0; regNo < n; regNo++) {               // We use the for loop to print all information in the file 
				outfile << Person[regNo].PrintInfo(&regNo);     //by the sorting of Reg.No, When the user choose to exit 
			}   
			cout << "Thank you for your time" << endl;
			outfile.close();        
			break;
		}
		else if (*P_No_of_serv == 1) {
			Welcome_Choose();  
			cin >> No_of_serv;   // enter the service u want and repeat the previuse steps (( because of the while function))
		}
	}
	return 0;
}
