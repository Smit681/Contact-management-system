#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelper.h"
#include <string.h>
#include<ctype.h>
#include "contact.h"

#define MAXCONTACTS 5

void clearKeyboard(void)
{
	while (getchar() != '\n'); 
}

void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	return;
}

int getInt(void)
{
	int value = 0;
	char NL = 'x';
	while (NL != '\n')
	{
		scanf("%d%c", &value, &NL);
		if (NL != '\n')
		{
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	}
	return value;
}

int getIntInRange(int min, int max)
{
	int rangeint = getInt();
	while (rangeint > max || rangeint < min)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		rangeint = getInt();
	}
	return rangeint;
}

int yes(void)
{
	char yesno, NL = 'x';
	int ans = 0;
	while (NL != '\n' || (yesno != 'Y' && yesno != 'y' && yesno != 'N' && yesno != 'n'))
	{
		scanf("%c%c", &yesno, &NL);
		if (NL != '\n' || (yesno != 'Y' && yesno != 'y' && yesno != 'N' && yesno != 'n'))
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
	}
	if (yesno == 'Y' || yesno == 'y')   ans = 1;
	return ans;
}


int manu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by first name\n");
	printf("6. Sort contacts by first name\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	int num = getIntInRange(0, 6);
	return num;
}


void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int flag = 0;
	while (needInput == 1)
	{
		flag = 0;
		scanf("%11s", phoneNum);
		clearKeyboard();

		for (int i = 0; i < 10; i++)
		{
			if (isdigit(phoneNum[i]) != 0)
				flag++;
		}

		if (strlen(phoneNum) == 10 && flag == 10)
		{
			needInput = 0;
		}
		else
		{
			printf("Enter a 10-digit phone number: ");
		}
	}
}


int findContactIndex(const struct Contact contacts[], int size, const char checkname[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp((contacts[i]).name.firstName, checkname) == 0) return i;
	}
	return -1;
}

void displayContactHeader(void)
{
	printf("\n");
	printf("+");
	for (int i = 1; i <= 77; i++)
		printf("-");
	printf("+\n");
	printf("|");
	for (int i = 1; i <= 30; i++)
		printf(" ");
	printf("Contacts Listing");
	for (int i = 1; i <= 31; i++)
		printf(" ");
	printf("|\n");
	printf("+");
	for (int i = 1; i <= 77; i++)
		printf("-");
	printf("+\n");

}

void displayContactFooter(int count)
{
	printf("+");
	for (int i = 1; i <= 77; i++)
		printf("-");
	printf("+\n");
	printf("Total contacts: %d\n\n", count);
}

void displayContact(const struct Contact* contact)
{
	if (contact->name.firstName[0] != '\0')
	{
		if (contact->name.middleInitial[0] != '\0')
			printf("%s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
		else
			printf("%s %s\n", contact->name.firstName, contact->name.lastName);
		printf("    c: %-10s    H: %-10s    B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
		if (contact->address.apartmentNumber > 0)
			printf("       %d %s, APT# %d, %s, %s\n", contact->address.streetNumber, contact->address.street,
				contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
		else
			printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city,
				contact->address.postalCode);
	}
}

void displaycontacts(const struct Contact contacts[], int size)
{
	int footer = 0;
	displayContactHeader();
	for (int i = 0; i < size; i++)
	{
		if ((contacts[i]).name.firstName[0] != '\0')
		{
			displayContact(&contacts[i]);
			footer++;
		}
	}
	displayContactFooter(footer);
}

void searchContacts(const struct Contact contacts[], int size)
{
	printf("\nEnter the first name the contact: ");
	char checkname[31];
	scanf("%30[^\n]", checkname);
	clearKeyboard();
	int a = findContactIndex(contacts, size, checkname);
	if (a != -1)
	{
		displayContact(&contacts[a]);
		printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
}

void addContact(struct Contact contacts[], int size)
{
	int a = findContactIndex(contacts, size, "\0");
	if (a == -1)
	{
		printf("\n*** ERROR: The contact list is full! ***\n\n");
	}
	else
	{
		printf("\n");
		getContact(&contacts[a]);
		printf("--- New contact added! ---\n\n");
	}

}

void updateContact(const struct Contact contacts[], int size)
{
	printf("\nEnter the first name the contact: ");
	char checkname[31];
	scanf("%30[^\n]", checkname);
	clearKeyboard();
	int a = findContactIndex(contacts, size, checkname);
	if (a == -1) printf("*** Contact NOT FOUND ***\n");
	else
	{
		printf("Contact found:\n\n");
		displayContact(&contacts[a]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1) getName(&contacts[a].name);
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) getAddress(&contacts[a].address);
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) getNumbers(&contacts[a].numbers);
		printf("--- Contact Updated! ---\n\n");
	}
}

void deleteContact(struct Contact contacts[], int size)
{
	printf("\nEnter the first name the contact: ");
	char checkname[31];
	scanf("%30[^\n]", checkname);
	clearKeyboard();
	int a = findContactIndex(contacts, size, checkname);

	if (a == -1) printf("*** Contact NOT FOUND ***\n");
	else
	{
		printf("Contact found:\n\n");
		displayContact(&contacts[a]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1)
		{
			(contacts[a]).name.firstName[0] = '\0';
			printf("--- Contact deleted! ---\n\n");
		}


	}
}

void sortContacts(struct Contact contacts[], int size)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (strcmp((contacts[i]).name.firstName, (contacts[j]).name.firstName) < 0)
			{
				contacts[MAXCONTACTS] = contacts[i];
				contacts[i] = contacts[j];
				contacts[j] = contacts[MAXCONTACTS];
				(contacts[MAXCONTACTS]).name.firstName[0] = '\0';
			}
		}
	}
	printf("\nContacts are sorted by first name\n\n");
}
