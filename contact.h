#ifndef CONTACTS_H_
#define CONTACTS_H_

//--------------------------------
// Structure Types
//--------------------------------

struct Name
{
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

struct Address
{
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};

struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//--------------------------------
// Function Prototypes
//--------------------------------

// Get and store from standard input the values for Name
void getName(struct Name* name);

// Get and store from standard input the values for Address
void getAddress(struct Address* address);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers);

// Get all input at once
void getContact(struct Contact* contact);

#endif // !CONTACTS_H_