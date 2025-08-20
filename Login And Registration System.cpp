#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ---------- Function to register a new user ----------
void registration() {
    string username, password;

    cout << "\n=== User Registration ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // ---------- Check if username already exists ----------
    ifstream infile(username + ".txt");
    if (infile.is_open()) {
        cout << "Username already exists. Try a different one.\n";
        infile.close();
        return;
    }

    // ---------- Store credentials in file ----------
    ofstream outfile(username + ".txt");
    outfile << username << endl << password;
    outfile.close();

    cout << "Registration successful!\n";
}

// ---------- Function to login ----------
void login() {
    string username, password, storedUser, storedPass;

    cout << "\n=== User Login ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile(username + ".txt");
    if (!infile.is_open()) {
        cout << "User not found! Please register first.\n";
        return;
    }

    getline(infile, storedUser);
    getline(infile, storedPass);
    infile.close();

    if (storedUser == username && storedPass == password) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n===== Menu =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            registration();
        } else if (choice == 2) {
            login();
        } else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
