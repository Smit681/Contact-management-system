#include "contact.h"

//clear buffer
void clearKeyboard(void);

//pause the exicusion
void pause(void);

// get foolproof integer value
int getInt(void);

// get integer in range
int getIntInRange(int min, int max);

// check whether user enters yes or no
int yes(void);

// show available options and get user's option
int manu(void);

// get a ten-digit phone number foolproof
void getTenDigitPhone(char phoneNum[]);

// find index of the contect 
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// display contact header
void displayContactHeader(void);

// display Contact Footer
void displayContactFooter(int count);

// display Contact
void displayContact(const struct Contact* contact);

// display all Contacts
void displaycontacts(const struct Contact contacts[], int size);

// search Contacts
void searchContacts(const struct Contact contacts[], int size);

// add Contact
void addContact(const struct Contact contacts[], int size);

// update Contact
void updateContact(const struct Contact contacts[], int size);

// delete Contact
void deleteContact(const struct Contact contacts[], int size);

// sort Contacts
void sortContacts(const struct Contact contacts[], int size);