//--------------------------------------------------------//
// Login/registration system V1 (beginner version)                          //
//--------------------------------------------------------//
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// Register function
void Register()
{
    string username, password;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new line

    cout << "****Registration****" << endl;
    cout << "Type your username and password" << endl;
    cout << "Userame: ";
    getline(cin, username); // get username
    cout << "Password: ";
    getline(cin, password); // get password

    // Normally we should implement hashing and salting for security, but this is a beginner level (V1)

    // Opening file for appending (file will be created for us because it's append mode)
    ofstream myFile;
    myFile.open("users.txt", ios::app);

    // check if file is open
    if (!myFile.is_open())
    {
        cerr << "Error opening file for registration. (tap Enter to continue)" << endl;
        return;
    }

    // write username and password in the file
    myFile << username << ' ' << password << endl;

    // close the file
    myFile.close();
    cout << "Successfully registered. (tap Enter to continue)" << endl;
};

// Login function
void Login()
{
    string username, password;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "****Login****" << endl;
    cout << "Type your username and password" << endl;
    cout << "Userame: ";
    getline(cin, username); // get username
    cout << "Password: ";
    getline(cin, password); // get password

    // open file for reading
    ifstream myFile("users.txt");

    // check if file is open
    if (!myFile.is_open())
    {
        cerr << "Error opening file for login. (tap Enter to continue)" << endl;
        return;
    }

    bool found = false;
    string userFound, passwordFound;

    // looping through the file in order to find matching username and password
    while (myFile >> userFound >> passwordFound)
    {
        if (userFound == username && passwordFound == password)
        {
            found = true;

            break;
        }
    }

    // close the file
    myFile.close();
    if (!found)
    {
        cout << "User not found or incorrect password (tap Enter to continue)" << endl;
        return;
    }

    cout << "Login successful! (tap Enter to continue)" << endl;
};

int main()
{
    int option;

    // welcome message
    cout << "****Welcome to this wonderful C++ login/registration system****" << endl;

    do
    {

        cout << "Choose an option:" << endl;
        cout << "1: Register" << endl
             << "2: Login" << endl
             << "3: Exit" << endl;

        // get user's choice
        cin >> option;

        switch (option)
        {
        case 1:
            Register();
            break;
        case 2:
            Login();
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please choose again." << endl;
        }
        cin.clear();                                         // clear any error on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input

    } while (option != 3);

    return 0;
}