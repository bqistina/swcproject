#include <iostream>
#include <string>
#include <iomanip>
#include <set>
#include <cctype>
#include <algorithm>
#include <limits>

using namespace std;

//Declare Arrays
const int numOfStudents = 50;
int studentID[numOfStudents];
string studentName[numOfStudents];
double scores[numOfStudents];
int attendance[numOfStudents];

void inputStudentData()
{
	//Declare variable
	int id;
	string name;
	double studentScores, percentageAttendance, studentAttendance;
	set<int> uniqueID;
	
		// For loop to enter student data based on total student
		for (int i = 0; i < numOfStudents; ++i)
			{
				bool iD; //to compare the variable 
				
				//do while loop making sure there is no repeated ID value. Make it Unique
				// Student Id Code Segment
				do{
					cout<<"Enter ID for Student "<< i+1 <<" in Integer Number\t "<<": ";
					cin>>id;
					
					//The code to making sure the value is not repeated
					iD=uniqueID.insert(id).second;
					
						if(!iD)
						{
							cout<<"=========================================================================================="<<endl;
							cout<<"||                ID already existed!\nPlease enter a different ID                      ||"<<endl;
							cout<<"=========================================================================================="<<endl;
							cout<<endl;
						}
					}
				
				while (!iD);
					studentID[i] = id; //end of the do while loop for studentID	
				 	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the newline character from the buffer
			
					//Student Name Code segment
           			cout<<"Enter name for Student "<< i+1 <<"\t\t\t : ";
					getline(cin,name); // User prompt name with spacing allow
					studentName[i] = name; // address the data to student Name Arrays
    
    			//Student scores segment
				do{
					cout<<"Student "<< i+1 <<" scores\t\t\t\t : ";
					cin>>studentScores;
					
						//Checking the value of scores must betwen 0.00 to 100.00					
						if (studentScores >= 100.00 || studentScores <= 0.00)
							{
								cout<<"=========================================================================================="<<endl;
								cout<<"||                                  Invalid scores!!                                    ||"<<endl;
								cout<<"=========================================================================================="<<endl;
							}
					}
				
				while (studentScores >= 100.00 || studentScores <= 0.00);
				scores[i]= studentScores; //address the data to studentScores Arrays
				
				do{
					cout<<"Student "<< i+1 <<" attendance in days (max 265 days)\t : ";
					cin>>studentAttendance; // User prompt attendance based on days
					cout<<endl;
					
						if (studentAttendance > 265 || studentAttendance <= 0)
							{
								cout<<"=========================================================================================="<<endl;
								cout<<"||                     Invalid attendance. Please re-insert attendance!                 ||"<<endl;
								cout<<"=========================================================================================="<<endl;
							}
					}
				
				while (studentAttendance > 265 || studentAttendance <= 0);
				
				//calculation to make it as percentage
				percentageAttendance = (studentAttendance/265) * 100;
				attendance[i] = percentageAttendance; //address the data to attendance Arrays
			
				cout<<"=========================================================================================="<<endl;
				cout<< endl;
			}
				
	
}

int main()
{
	inputStudentData();
	
	return 0;
}