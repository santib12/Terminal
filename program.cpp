

// this program.cpp file will hold all the out of line member functions of the classes
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include "program.h"
using namespace std;

// user class definitions
User::User()
{
  szName = "";
  iID = "";
  iAge = "";
}

User::User(string name, string id, string age)
{
  szName = name;
  iID = id;
  iAge = age;
}

string User::getName() const
{
  return szName;
}

void User::setName(const string &name)
{
  szName = name;
}

void User::setID(string id)
{
  iID = id;
}

string User::getID() const
{
  return iID;
}

void User::setAge(string age)
{
  iAge = age;
}

string User::getAge() const
{
  return iAge;
}

fetures::fetures()
{
  adminName = "2389-N";
  adminPassword = "guest";
  isAdminLoggedIn = false;
}

void fetures::changeAdmin(fetures &fobj)
{
  char choice;
  display dobj;
  char ADDprofile;
  string username, password;
  string UserAdmin, UserPass;

  cout << "| User log:" << endl;
  cout << "| >> user: ";
  getline(cin, UserAdmin); // Get admin name from system object

  cout << "|admin password: ";
  getline(cin, UserPass); // Get admin password from system object
  // Now you are comparing with the system object's adminName and
  // adminPassword1
  if (UserAdmin == fobj.adminName && UserPass == fobj.adminPassword)
  {
    cout << "Admin credential verified" << endl;
    fobj.isAdminLoggedIn = true;
    cout << "New profile (y/n)";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    if (choice == 'y' || choice == 'Y')
    {
      ofstream outfile("Profile.txt", ios ::app);

      do
      {
        cout << "Enter Profile name: ";
        cout << endl;
        cin >> username;
        cout << "Enter Profile password: ";
        cout << endl;
        cin >> password;
        outfile << username << " " << password << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << "add another profile? (Y/N)";
        cin >> ADDprofile;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
      } while (ADDprofile == 'Y' || ADDprofile == 'y');
      outfile.close();
      // dobj.clearScreen();
      cout << "Credentials saved to profile manager" << endl;

    } // second if statment end brace
    else
    {
      // dobj.clearScreen();
      cout << "Credentials not saved to profile manager" << endl;
    }
  } // end of first if statment curly brace
  else
  {
    cout << "Invalid Credentials" << endl;
    return;
  }
}
// display class definitions

void display::displayHeader()
{
  cout << setw(35) << "WELCOME TO ROBCO INDUSTRIES UNIFIED OPERATING SYSTEM"
       << endl;
  cout << setw(43) << "COPYRIGHT 2075-2077 ROBCO INDUSTRIES" << endl;
  cout << setw(30) << "~SERVER 1~" << endl;
}

void display::displayASCIIArt()
{
  cout << R"(
 _____          _       ____ 
|  __ \   ___  | |     / ___| ____
| |__) | / _ \ | |__  | |    /  _  \
|  ___/ | | | || '_ \ | |   |  | |  |
| | \ \ \ |_| || |_) \| |___|  |_|  |    
|_|  \_\ \___/ |_.__/| \____|\_____/    )"
       << endl;
}

void display::displayMainMenu()
{
  cout << "-ROBCO Trespasser Management System-" << endl;
  cout << "=====================================" << endl;
  cout << "1. Add profiles\n";
  cout << "2. Log in\n";
  cout << "3. view logs\n";
  cout << "4. Unlock Security Door\n";
  cout << "5. Hacking minigame\n";
  cout << "6. Emergency Shutdown\n";
  cout << "7. Next page\n";
  cout << "8. Exit\n";
  cout << "=====================================" << endl;
  cout << "Select an option: ";
}

void display::clearScreen() { cout << "\033[2J\033[1;1H"; }

/*void display::displayLoginProfile(const User &user)
{
  cout << "--------------------------------------" << endl;
  cout << "Logged in user: " << user.getName() << endl;
  cout << "User ID: " << user.getID() << endl;
  cout << "User Age: " << user.getAge() << endl;
  cout << "--------------------------------------" << endl;
}*/

bool Profile::login(const string &username, const string &password, User &user)
{
  string storedLine, storedUsername, storedPassword;
  bool found = false;
  ifstream infile("Profile.txt");
  if (infile.is_open())
  {
    while (getline(infile, storedLine))
    {
      size_t spacePos = storedLine.find(' ');
      storedUsername = storedLine.substr(0, spacePos);
      storedPassword = storedLine.substr(spacePos + 1);
      if (trim(storedUsername) == trim(username) && storedPassword == password)
      {
        found = true;
        break;
      }
    }
    infile.close();
  }
  else
  {
    cout << "Unable to open file." << endl;
  }

  return found;
}

string Profile::trim(const string &str)
{
  size_t first = str.find_first_not_of(' ');
  size_t last = str.find_last_not_of(' ');
  return first != string::npos ? str.substr(first, last - first + 1) : "";
}

void Profile::LoginPage(User &user)
{
  string username, password;
  display dobj;
  cout << "Enter username: ";
  cin >> username;
  cout << "Enter password: ";
  cin >> password;

  if (login(username, password, user))
  {
    cout << "Login successful!" << endl;
    // dobj.clearScreen();
  }
  else
  {
    cout << "Invalid credentials." << endl;
  }
}

void fetures::HackingMiniGame()
{
  srand(time(0));

  vector<string> passwords = {"DRIVING", "BARRING", "HEALING", "HOLDING",
                              "LEAVING", "LEADING", "OPTIONS", "HEADING"};

  string correctPassword = "BARRING"; // This would be the correct password
  int attemptsLeft = 3;
  string userInput;

  while (attemptsLeft > 0)
  {
    displayTerminal(passwords, attemptsLeft);

    cout << "Enter password: ";
    cin >> userInput;

    int matches = checkPassword(userInput, correctPassword);
    if (matches == correctPassword.length())
    {
      cout << "Access granted!\n";
      return;
    }
    else
    {
      cout << matches << "/" << correctPassword.length() << " correct.\n";
      attemptsLeft--;
      if (attemptsLeft == 0)
      {
        cout << "Access denied. Terminal locked.\n";
        return;
      }
    }
  }
}
void fetures::displayTerminal(const vector<string> &passwords, int attemptsLeft)
{
  cout << "ROBCO INDUSTRIES (TM) TERMLINK PROTOCOL\n";
  cout << "ENTER PASSWORD NOW\n\n";
  cout << attemptsLeft << " ATTEMPT(S) LEFT: ";
  for (int i = 0; i < attemptsLeft; ++i)
  {
    cout << "■ ";
  }
  cout << "\n\n";
  for (const auto &password : passwords)
  {
    cout << "0x" << hex << rand() % 0x10000 << " " << password << " ";
    // Simulate random junk data
    for (int i = 0; i < 12; ++i)
    {
      char c = rand() % 94 + 33; // Random printable ASCII character
      cout << c;
    }
    cout << "\n";
  }
  cout << "\n";
}

int fetures::checkPassword(const string &attempt, const string &correctPassword)
{
  int matches = 0;
  for (size_t i = 0; i < attempt.length(); ++i)
  {
    if (attempt[i] == correctPassword[i])
    {
      matches++;
    }
  }
  return matches;
}

void fetures::viewLogs()
{
  cout << "Viewing logs..." << endl;
  // Simulate loading time
  this_thread::sleep_for(chrono::seconds(3));

  ifstream inFile("Logs.txt");

  // Read from the file
  string line;
  while (getline(inFile, line))
  {                       // Read the file line by line
    cout << line << endl; // Print each line to the console
  }

  // Close the file
  inFile.close();
}

void fetures::UnlockSecurityDoor()
{
  string userInput;
  cout << "Enter Admin code" << endl;
  cout << ">> ";
  getline(cin, userInput);

  if (userInput == adminName)
  {
    cout << "Enter password" << endl;
    cout << ">> ";
    cin >> userInput;
    if (userInput == adminPassword)
    {
      cout << "Unlocking door..." << endl;
      this_thread::sleep_for(chrono::seconds(3));
      cout << "Security vault door unlocked. Proceed with caution." << endl;
    }
  }
  else
  {
    cout << "Invalid Credentials" << endl;
    cout << "Shutting down system... Goodbye." << endl;
    exit(0);
  }
}

void fetures::EmergencyShutDown()
{
  cout << "WARNING: Emergency shutdown initiated!" << endl;
  cout << "Confirm shutdown (Y/N): ";
  char confirm;
  cin >> confirm;
  if (confirm == 'Y' || confirm == 'y')
  {
    cout << "Shutting down system... Goodbye." << endl;
    exit(0); // Exit the program immediately
  }
  else
  {
    cout << "Shutdown cancelled. System integrity maintained." << endl;
  }
}
