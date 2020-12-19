#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contact.h"
#include "contactHelper.h"

void getName(struct Name* name)
{
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    if (yes() == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }


    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

void getAddress(struct Address* address)
{
    printf("Please enter the contact's street number: ");
    do
    {
        address->streetNumber = getInt();
        if (address->streetNumber < 1) printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
    } while (address->streetNumber < 1);



    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    if (yes() == 1)
    {
        printf("Please enter the contact's apartment number: ");
        do
        {
            address->apartmentNumber = getInt();
            if (address->apartmentNumber < 1) printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
        } while (address->apartmentNumber < 1);
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();

}

void getNumbers(struct Numbers* numbers)
{
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes() == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);

    }

    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes() == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    return;
}

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
