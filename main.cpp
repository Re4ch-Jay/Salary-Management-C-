#include <iostream>
#include "header.hpp"
#include "auth.hpp"
using namespace std;

void authScreen();
void menu();
void readFile();
void saveFile(string ID, string name, string job, double salary);

int main () {
    List * myList;
    myList = createEmptyList();
    string name, ID, job, newID;
    double salary, average, max1, max2, max3, min;
    int choice;

    struct Element* head = NULL;
    
    while (choice != 0)
    {   
        if(isAuth == true) {
            
            system("pause");
            menu();
            cout<<"\n\tChoice: "; cin>>choice;
           
        }else if (isAuth == false){
            system("cls");
            authScreen();
        }
        switch (choice) 
        {
            case 1:
                system("cls");
                cout<<"\n\t**************************************"<<endl;
                cout<<"\n\tEnter user ID: "; cin>>ID;
                cout<<"\n\tEnter user name: "; cin>>name;
                cout<<"\n\tEnter user job: "; cin>>job;
                cout<<"\n\tEnter user salary: "; cin>>salary;
                if(isIdExist(myList, ID) == 1) cout<<"This ID "<<ID<<" is already existed"<<endl;
                if(isIdExist(myList, ID) == 0) {
                    insertBegin(myList, ID, name, job, salary);
                    //insertAtBeginning(&head, salary, ID, name, job);
                }else
                cout<<"\n\t**************************************"<<endl;
                loading();
                break;
            case 2:
                system("cls");
                cout<<"\n\t***********************************"<<endl;
                displayData(myList);
                cout<<"\n\t***********************************"<<endl;
                loading();
                break;
            case 3:
                system("cls");
                cout<<"\n\t******************************"<<endl;
                cout<<"\n\tEnter user ID: "; cin>>ID;
                searchById(myList, ID);
                cout<<"\n\t******************************"<<endl;
                loading();
                break;
            case 4:
                system("cls");
                cout<<"\n\t*************************************************"<<endl;
                cout<<"\n\tEnter user salary that you want to filter: "; cin>>salary;
                filterUserBySalary(myList, salary);
                cout<<"\n\t*************************************************"<<endl;
                loading();
                break;
            case 5:
                system("cls");
                cout<<"\n\t*************************************************"<<endl;
                cout<<"\n\tEnter user salary that you want to filter: "; cin>>job;
                filterUserByJob(myList, job);
                cout<<"\n\t*************************************************"<<endl;
                loading();
                break;
            case 6:
                system("cls");
                max1 = findMax1(myList);
                cout<<"\n\t*************************************"<<endl;
                cout<<"\n\tTop 1 salary is: "<<endl;
                displayMax(myList, max1);
                cout<<"\n\t*************************************"<<endl;
                break;
            case 7:
                system("cls");
                max1 = findMax1(myList);
                max2 = findMax2(myList);
                max3 = findMax3(myList);
                if(counter == 3) {
                    displayMax(myList, max1);
                    
                }else if(counter == 2){
                    displayMax(myList, max2);
                }else if(counter == 1) {
                    displayMax(myList, max3);
                }

                break;
            case 8:
                system("cls");
                average = findAverageSalary(myList);
                max1 = findMax1(myList);
                min = findMin(myList);
                cout<<"\n\t*************************************"<<endl;
                cout<<"\n\tAverage salary of users is "<<average<<endl;
                cout<<"\n\tMax salary of users is "<<max1<<endl;
                cout<<"\n\tMin salary of users is "<<min<<endl;
                cout<<"\n\t*************************************"<<endl;
                loading();
                break;
            case 9:
                system("cls");
                cout<<"\n\t******************************"<<endl;
                cout<<"\n\tEnter user ID to delete: "; cin>>ID;
                cout<<"\n\t******************************"<<endl;
                searchByIdAndDelete(myList, ID);
                loading();
                break;
            case 10:
                system("cls");
                deleteBegin(myList);
                loading();
                break;
            case 11:
                system("cls");
                deleteLast(myList);
                loading();
                break;
            case 12:
                system("cls");
                deleteAll(myList);
                loading();
                break;
            case 13:
                    system("cls");

                    // cout<<"Enter ID to update: "; cin>>ID;
                    
                    // cout<<"Enter new ID: "; cin>>newID;
                    // cout<<"Enter new name: "; cin>>name;
                    // cout<<"Enter new job: "; cin>>job;
                    // cout<<"Enter new salary: "; cin>>salary;

                    // updateData(myList, ID, newID, name, job, salary);

                    cout<<"Enter ID to update: "; cin>>ID;
                    searchByIdAndDelete(myList, ID);
                    saveFile(ID, name, job, salary);
                    cout<<"Enter new ID: "; cin>>ID;
                    cout<<"Enter new name: "; cin>>name;
                    cout<<"Enter new job: "; cin>>job;
                    cout<<"Enter new salary: "; cin>>salary;
                    insertBegin(myList, ID, name, job, salary);

                    loading();
                break;
            case 14:
                    system("cls");
                    sort(myList);
                    displayData(myList);
                break;
            case 15:
                    system("cls");
                    sortReverse(myList);
                    displayData(myList);
                break;
            case 16:
                    system("cls");
                    saveFile(ID, name, job, salary);
                break;
            default:
                system("cls");
                cout<<"\n\t******************************"<<endl;
                cout<<"\n\tThank for using our program"<<endl;
                cout<<"\n\t******************************"<<endl;
                break;
            }
    }
    return 0;
}

void readFile() {
    fstream file;
    file.open("data.txt");
    string myline;
    if ( file.is_open() ) {
        while ( file ) { 
            getline (file, myline);
            cout << myline << '\n';
        }
    }
    else {
        cout << "Couldn't open file\n";
    }
}


void saveFile(string ID, string name, string job, double salary) {
    fstream file;
    file.open("data.txt", ios::app);
    file<<"\n\tID: "<<ID<<"\tName: "<<name<<"\tJob: "<<job<<"\tSalary: "<<salary<<endl; 
    file.close();
}


void menu(){
    cout<<"\n\t***************************************"<<endl;
    cout<<  "\t*                                     *"<<endl;
    cout<<  "\t*      Salary Management System       *"<<endl;
    cout<<  "\t*                                     *"<<endl;
    cout<<"\n\t***************************************"<<endl;

    cout<<"\n\t1. Create a new user"<<endl;
    cout<<"\n\t2. View all users information"<<endl;
    cout<<"\n\t3. Search user by ID"<<endl;
    cout<<"\n\t****************Filter**********************"<<endl;
    cout<<"\n\t4. Filter users by their salary"<<endl;
    cout<<"\n\t5. Filter users by their job"<<endl;
    cout<<"\n\t****************Find**********************"<<endl;
    cout<<"\n\t6. Find a user who has top 1 salary"<<endl;
    cout<<"\n\t7. Find a user who has top 3 salary"<<endl;
    cout<<"\n\t8. Find min max and average salary"<<endl;
    cout<<"\n\t****************Delete**********************"<<endl;
    cout<<"\n\t9. Delete user by given ID"<<endl;
    cout<<"\n\t10. Delete user from begin"<<endl;
    cout<<"\n\t11. Delete user from last"<<endl;
    cout<<"\n\t12. Delete All users that exist in the list"<<endl;
    cout<<"\n\t****************Exit**********************"<<endl;
    cout<<"\n\t13. Update data"<<endl;
    cout<<"\n\t14. Sorted small to big"<<endl;
    cout<<"\n\t15. Sorted big to small"<<endl;
    cout<<"\n\t16. Save data"<<endl;
    cout<<"\n\t0. Exit the console application"<<endl;
}

void authScreen() {
    cout << "\n***** Login or Register *****\n\n";
    cout << "===================================\n";
    cout << "\n***** Please write (login) or (register) *****\n\n";
    string LoR;
    while(true){

        getline(cin,LoR);
        if(LoR == "login"){
            login();
            break;
        }else if(LoR == "register"){
            registry();
            break;
        }else{
            cout << "\n*Please write (login) or (register) correctly*\n" ;
        }
    }
}

