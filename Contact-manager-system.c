#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5
#include <stdio.h>
#include "contact.h"
#include "contactHelper.h"

int main(void)
{
    //allocate 1 more space for sorting perpose
	struct Contact intialvalues[MAXCONTACTS + 1] = { {{'\0'}} };

	int choice;
	int flag = 0;
	while (flag != 1)
	{
		choice = manu();
		if (choice == 1)
		{
			displaycontacts(&intialvalues, MAXCONTACTS);
			pause();
		}
		else if (choice == 2)
		{
			addContact(&intialvalues, MAXCONTACTS);
			pause();
		}
		else if (choice == 3)
		{
			updateContact(&intialvalues, MAXCONTACTS);
			pause();
		}
		else if (choice == 4)
		{
			deleteContact(&intialvalues, MAXCONTACTS);
			pause();
		}
		else if (choice == 5)
		{
			searchContacts(&intialvalues, MAXCONTACTS);
			pause();
		}
		else if (choice == 6)
		{
			sortContacts(&intialvalues, MAXCONTACTS);
			pause();
		}
		printf("\n");

		if (choice == 0)
		{
			printf("Exit the program? (Y)es/(N)o: ");

			if (yes() == 1)
			{

				printf("\nContact Management System: terminated");
				flag = 1;
			}
			printf("\n");
		}
	}

    return 0;
}