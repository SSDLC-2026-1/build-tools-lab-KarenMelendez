#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "ticket.h"
#include "validator.h"

using namespace std;

int main() {

    ifstream file("data/tickets.csv");

    if (!file.is_open()) {
        cout << "Could not open data/tickets.csv" << endl;
        return 1;
    }

    string line;

    int validCount = 0;
    int invalidCount = 0;

    getline(file, line); // skip header

    while (getline(file, line)) {

        stringstream ss(line);

        string code;
        string type;
        string status;

        getline(ss, code, ',');
        getline(ss, type, ',');
        getline(ss, status, ',');

        Ticket ticket;
        ticket.code = code;
        ticket.type = type;
        ticket.status = status;

        vector<string> errors = validateTicket(ticket);

        if (errors.empty()) {

            validCount++;

            cout << "[VALID] " << ticket.code << endl;

        } else {

            invalidCount++;

            cout << "[INVALID] " << ticket.code << ": ";

            for (string error : errors) {
                cout << error << " | ";
            }

            cout << endl;
        }
    }

    cout << endl;
    cout << "Summary" << endl;
    cout << "Valid tickets: " << validCount << endl;
    cout << "Invalid tickets: " << invalidCount << endl;

    return 0;
}