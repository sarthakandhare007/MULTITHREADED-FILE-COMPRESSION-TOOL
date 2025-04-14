#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to write to a file (overwrite mode)
void writeToFile(const string& filename) {
    ofstream outFile(filename); // overwrite mode
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    string data;
    cout << "Enter data to write to the file: ";
    cin.ignore();
    getline(cin, data);

    outFile << data << endl;
    outFile.close();
    cout << "Data written to file.\n";
}

// Function to append to a file
void appendToFile(const string& filename) {
    ofstream outFile(filename, ios::app); // append mode
    if (!outFile) {
        cerr << "Error opening file for appending.\n";
        return;
    }

    string data;
    cout << "Enter data to append to the file: ";
    cin.ignore();
    getline(cin, data);

    outFile << data << endl;
    outFile.close();
    cout << "Data appended to file.\n";
}

// Function to read from a file
void readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    cout << "\n--- File Contents ---\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    cout << "---------------------\n";
}

// Main menu
int main() {
    string filename = "example.txt";
    int choice;

    do {
        cout << "\nFile Handling Menu\n";
        cout << "1. Write to file (overwrite)\n";
        cout << "2. Append to file\n";
        cout << "3. Read file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

