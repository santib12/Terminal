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
#include <iostream>
#include "program.h"

using namespace std;

int main() {
  string username, password;
  display dobj;
  Profile lobj;
  fetures fobj;
  User user;
  User loggedInUser;
  
  //dobj.displayHeader();
  //dobj.displayASCIIArt();
  
  while (true) {
    dobj.clearScreen();
    dobj.displayHeader();
    dobj.displayASCIIArt();
    dobj.displayLoginProfile(user);
    dobj.displayMainMenu();


    int choice;
    cin >> choice;
    cin.ignore(); // Clear the newline character left by cin

    switch (choice) {
    case 1:
      dobj.clearScreen();
      fobj.changeAdmin(fobj);
      break;
    case 2:
      dobj.clearScreen();
      lobj.LoginPage(user);
      break;
    case 3:
      dobj.clearScreen();
       fobj.viewLogs();
      break;
    case 4:
      dobj.clearScreen();
      fobj.UnlockSecurityDoor();
      break;
    case 5:
      dobj.clearScreen();
      fobj.HackingMiniGame();
      break;
    case 6:
      dobj.clearScreen();
      fobj.EmergencyShutDown();
      break;
    case 7:
      dobj.clearScreen();
      break;
    case 8:
      cout << "Exiting the program. Goodbye!" << endl;
      return 0;
    default:
      dobj.clearScreen();
      cout << "Invalid choice. Please try again." << endl;
    }
    
  }

  return 0;
}
