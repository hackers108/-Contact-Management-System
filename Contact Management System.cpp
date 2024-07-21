#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
};

void addContact(vector<Contact>& contacts) {
    Contact contact;
    cout << "Enter contact name: ";
    cin.ignore();
    getline(cin, contact.name);
    cout << "Enter phone number: ";
    getline(cin, contact.phone);
    contacts.push_back(contact);
}

void displayContacts(const vector<Contact>& contacts) {
    for (const auto& contact : contacts) {
        cout << "Name: " << contact.name << ", Phone: " << contact.phone << endl;
    }
}

void deleteContact(vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to delete: ";
    cin.ignore();
    getline(cin, name);
    auto it = remove_if(contacts.begin(), contacts.end(), [&](const Contact& c) {
        return c.name == name;
    });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void searchContact(const vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to search: ";
    cin.ignore();
    getline(cin, name);
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Name: " << contact.name << ", Phone: " << contact.phone << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Contact not found." << endl;
    }
}

void sortContacts(vector<Contact>& contacts) {
    sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.name < b.name;
    });
}

int main() {
    vector<Contact> contacts;
    int choice;
    while (true) {
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Search Contact" << endl;
        cout << "5. Sort Contacts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        if (choice == 1) {
            addContact(contacts);
        } else if (choice == 2) {
            displayContacts(contacts);
        } else if (choice == 3) {
            deleteContact(contacts);
        } else if (choice == 4) {
            searchContact(contacts);
        } else if (choice == 5) {
            sortContacts(contacts);
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
