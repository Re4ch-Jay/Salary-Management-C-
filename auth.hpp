#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
bool isAuth = false;
//Login function
bool login(){
string UserName,Password;
string UseEnter,PassEnter;
bool On_Off = true;
bool Off = true;
int countt = 0;
int left = 3;

cout << "\n**** Login to your Account **** \n";
while(On_Off){
    //********************************************
    fstream user;
    user.open("users.txt", ios::in);
    if(countt < 3 && Off && user.is_open()){
        if(countt > 0){
        cout << "\nPassword or UserName are not correct!!" << endl;
        left--;
        cout << "You have *" << left << "* attempts left \n" << endl;
        }
        
        do
        {
            cout<<"\n\tEnter UserName: ";
            getline(cin,UseEnter);
            if(UseEnter == "") cout<<"\n\t*****Please input username*****"<<endl;
            else cout<<"\n\t*****Please input password*****"<<endl;
        } while (UseEnter == "");
        
        do
        {
            cout<<"\n\tEnter Password: ";
            getline(cin,PassEnter);
            if(PassEnter == "") cout<<"\n\t*****Please input password*****"<<endl;
        } while (PassEnter == "");

        // cout << "Enter UserName: ";
        // getline(cin,UseEnter);
        // cout << "Enter Password: ";
        // getline(cin,PassEnter);
        
        countt++;
        string read;
        //====================================================*
        while(getline(user,read)){
            stringstream convertor(read);
            convertor >> UserName >> Password;
            if(UseEnter == UserName && PassEnter == Password){
                Off = false;}}
        //=====================================================*
            }
    else if(!Off){
        cout << "\n**** Welcome! ****\n\n";
        isAuth = true;
        user.close();
        On_Off = false;
}
    else {
        cout << "\n**** try again later!! **** \n\n";
        isAuth = false;
        user.close();
        On_Off = false;
    }
}
}

// Registry function
void registry(){
string newName,checkName,newPass,confirmPass;
int MiniPass ;
bool if_ON = true;
bool oo = true;

cout << "\n**** Create New Account **** \n";

//UserName Validation
while(oo){
    cout << "Enter New UserName: ";
    getline(cin, newName);
    MiniPass = newName.length();
    fstream yusers;
    yusers.open("Users.txt",ios::in);
    if(if_ON && MiniPass >= 1 && yusers.is_open()){
        string readd;
        while(getline(yusers,readd)){
            stringstream OnlyUsers(readd);
            OnlyUsers >> checkName;
            if(newName == checkName){
                cout <<"\n*"<< newName <<"* UserName already exists Try another one\n" << endl;
                if_ON = false;
            }
    }
    yusers.close();
    if(!if_ON){
       if_ON = true;
    }
    else{
        oo = false;
    }
    }
}
//Password Validation
while(true){
    cout << "Enter New password: ";
    getline(cin,newPass);
    cout << "Confirm the password: ";
    getline(cin,confirmPass);
    MiniPass = newPass.length();

    if (MiniPass < 5){
        cout << "\nYour password is weak at least 5 letters\n \n";
    }
    else if(confirmPass == newPass){
        fstream users;
        users.open("Users.txt",ios::app);
        if(users.is_open()){
            users << newName +" "+ newPass << endl;
            users.close();
        }
        cout << "\n===================================\n";
        cout << "\nSuccessfully new account created! \n \n";
        cout << "===================================\n";
        break;}
    else{
        cout << "\nPassword confirmation not correct! \n" << endl;

        }
        }
    login();

}
