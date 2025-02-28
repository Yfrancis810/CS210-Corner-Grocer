// Yanika Francis
//
// CS - 210 Project Three 

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

class GroceryTracker {
private:
    map<string, int> groceryList; // Store the grocery items and their frequencies

public:
    // Function to load data from a file
    void loadData(const string& filename) {
        ifstream file(filename);
        string item;
        int frequency;

        if (file.is_open()) {
            while (file >> item >> frequency) {
                groceryList[item] = frequency;
            }
            file.close();
        } else {
            cout << "Error opening file for reading!" << endl;
        }
    }

    // Function to save data to a file
    void saveData(const string& filename) {
        ofstream file(filename);

        if (file.is_open()) {
            for (const auto& pair : groceryList) {
                file << pair.first << " " << pair.second << endl;
            }
            cout << "Data successfully saved to " << filename << endl;
        } else {
            cout << "Error opening file for writing!" << endl;
        }
    }

    // Function to search for an item
    void searchItem() {
        string item;
        cout << "Enter the item you want to search for: ";
        cin >> item;

        auto it = groceryList.find(item);
        if (it != groceryList.end()) {
            cout << "The item " << item << " was purchased " << it->second << " times." << endl;
        } else {
            cout << "Item not found!" << endl;
        }
    }

    // Function to list all items and their frequencies
    void listItems() {
        if (groceryList.empty()) {
            cout << "The grocery list is empty." << endl;
        } else {
            cout << "Item\tFrequency" << endl;
            for (const auto& pair : groceryList) {
                cout << pair.first << "\t" << pair.second << endl;
            }
        }
    }

    // Function to display a histogram of item frequencies
    void showHistogram() {
        if (groceryList.empty()) {
            cout << "The grocery list is empty." << endl;
        } else {
            cout << "Item Frequency Histogram" << endl;
            for (const auto& pair : groceryList) {
                cout << pair.first << " ";
                for (int i = 0; i < pair.second; i++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "Welcome to the Grocery Tracking Program!" << endl;
    cout << "Here's what you can do:" << endl;
    cout << "1. Search for an item" << endl;
    cout << "2. List all items and their frequencies" << endl;
    cout << "3. Show a histogram of item frequencies" << endl;
    cout << "4. Exit the program" << endl;
    cout << "Please enter a number (1-4): ";
}

int main() {
    GroceryTracker tracker; // Create an instance of the GroceryTracker class

    // Load existing data from the file
    tracker.loadData("CS210_Project_Three_Input_File.txt");

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            tracker.searchItem();
            break;
        case 2:
            tracker.listItems();
            break;
        case 3:
            tracker.showHistogram();
            break;
        case 4:
            cout << "Thanks for using the program! Take care!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

    // Save data when the program exits
    tracker.saveData("frequency.dat");

    return 0;
}
