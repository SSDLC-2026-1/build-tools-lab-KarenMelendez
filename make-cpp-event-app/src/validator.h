#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "ticket.h"
#include <vector>
#include <string>

using namespace std;

vector<string> validateTicket(const Ticket& ticket);

#endif