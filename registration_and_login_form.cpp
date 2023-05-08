#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){

    int c;
    cout<<"\t\t\t______________________________________________________________________\n\n\n";
    cout<<"\t\t\t                            Welcome to the Login page                  \n\n\n";
    cout<<"\t\t\t_____________________________         MENU        _____________________\n\n";
    cout<<"                                                                              \n\n";
    cout<<"\t|  Press 1 to LOGIN                               |"<<endl;
    cout<<"\t|  Press 2 to REGISTER                            |"<<endl;
    cout<<"\t|  Press 3 to if you forgot your PASSWORD         |"<<endl;
    cout<<"\t|  Press 4 to to EXIT                             |"<<endl;
    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
        login();
        break;

        case 2:
        registration();
        break;

        case 3:
        forgot();
        break;

        case 4:
                cout<<"\t\t\t thankyou!  \n\n";
                break;
        default:
        system("cls");
        cout<<"\t\t\t Please select form the options give above \n"<<endl;
        main();
    }
    return 0;
}
void login(){
    int count;
    string userID, password, id, pass;
    system("cls");
    cout<<"\t\t\t please enter the username and password : "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userID;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass){
        if(id == userID && pass == password){
            count = 1;
            system("cls");
        }
    }
    input.close();

    if(count == 1){
        cout<<userID<<"/n YOUR LOGIN IS SUCCESSFULL \n THANKS FOR LOGGING IN ! \n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password\n";
        main();
    }
}

void registration(){
    string ruserID,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserID;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\\t\t\t REGISTRATION IS SUCCESSFULL! \n";
    main();

}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? NO WORRIES \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
    cin>>option;
    switch (option)
    {
    case 1:
    { 
    int count=0;
    string suserId,sID,spass;
    cout<<"\n\t\t\t Enter the username which you remembered : ";
    cin>>suserId;

    ifstream f2("records.txt");
    while(f2>>sID>>spass){
        if(sID == suserId){
            count=1;
        }
    }
    f2.close();
    if(count==1){
        cout<<"\n\n Your account is Found! \n";
        cout<<"\n\n Your password is : "<<spass;
        main();
    }
    else{
        cout<<"\n\t Sorry! your account is not Found! \n";
        main();
    }
        break;
    }
    
    case 2:
    {
        main();
        // break;
    }
    default:
    cout<<"\n\tWRONG CHOICE ! PLEASE TRY AGAIN "<<endl;
    forgot();
        // break;
    }  
}