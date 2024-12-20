// this program.h file wll hold all class definitons
#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User{
    private:
    string szName;
    string iID;
    string iAge;

    public:
    User();
    User(string,string, string);
    string getName()const;
    void setName(const string&);
    void setID(string);
    string getID()const;
    void setAge(string);
    string getAge()const;
    
};

class display{
    public:
    void displayHeader();
    void displayASCIIArt();
    void displayMainMenu();
    void clearScreen();
    void displayLoginProfile(const User&);
};

class Profile{
    public:
    bool login(const string&, const string&, User&);
    void displayLOGIN();
    int checkPassword();
    string trim(const string&);
    void LoginPage(User &user);
};

class fetures{
    private:
    string adminName;
    string adminPassword;
    bool isAdminLoggedIn;

    public:
    fetures();
    void HackingMiniGame();
    int checkPassword(const string&, const string&);
    void displayTerminal(const vector<string>&, int);
    void viewLogs();
    void UnlockSecurityDoor();
    void EmergencyShutDown();
    void changeAdmin(fetures&);
};

#endif