#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Contact {
	char name[20];
	char phone[20];
};

void printMenu()
{
	printf("\t\tМЕНЮ\n");
	printf("\t0 - выйти\n");
	printf("\t1 - добавить запись(имя и телефон)\n");
	printf("\t2 - распечатать все имеющиеся записи\n");
	printf("\t3 - найти телефон по имени\n");
	printf("\t4 - найти имя по телефону\n");
	printf("\t5 - сохранить текущие данные в файл\n");
}

void expandBook(Contact** &contacts, int &contactBookCapacity)
{
	Contact** newContacts = new Contact*[contactBookCapacity * 2];

	for (int i = 0; i < contactBookCapacity; ++i)
	{
		newContacts[i] = contacts[i];
	}
	delete[] contacts;

	contacts = newContacts;
	contactBookCapacity *= 2;
}

void addContact(Contact** &contacts, int &contactCount, int &contactBookCapacity)
{
	Contact* newContact = new Contact();

	printf("Введите имя нового контакта ");
	std::cin.ignore(INT_MAX, '\n');
	gets_s(newContact->name);
	printf("Введите номер нового контакта ");
	gets_s(newContact->phone);

	if (contactCount == contactBookCapacity)
	{
		expandBook(contacts, contactBookCapacity);
	}

	contacts[contactCount] = newContact;
	++contactCount;
}

void printContact(Contact* contact) {
	if (contact == nullptr) {
		return;
	}
	printf("%s\t: %s", contact->name, contact->phone);
}

void printContacts(Contact** &contacts, int contactCount)
{
	if (contactCount == 0) {
		printf("Book is empty\n");
	}
	for (int i = 0; i < contactCount; ++i)
	{
		printf("%d. %s\t: %s\n", i, contacts[i]->name, contacts[i]->phone);
	}
}

Contact* searchByName(Contact** contacts, int contactCount, char name[20])
{
	for (int i = 0; i < contactCount; ++i)
	{
		if (strcmp(contacts[i]->name, name) == 0)
		{
			return contacts[i];
		}
	}
	return nullptr;
}

Contact* searchByNumber(Contact** contacts, int contactCount, char phone[20])
{
	for (int i = 0; i < contactCount; ++i)
	{
		if (strcmp(contacts[i]->phone, phone) == 0)
		{
			return contacts[i];
		}
	}
	return nullptr;

}

void saveToFile(Contact** &contacts, int &contactCount)
{
	FILE* pFile = fopen("book.txt", "a+");
	for (int i = 0; i < contactCount; ++i) {
		fprintf(pFile, "%s\n%s\n", contacts[i]->name, contacts[i]->phone);
	}
	fclose(pFile);
}

void makeChoice(int choice, Contact** &contacts, int &contactCount, int &contactBookCapacity)
{
	char searchName[20] = "";
	char searchNumber[20] = "";
	switch (choice) {
	case 1:
		addContact(contacts, contactCount, contactBookCapacity);
		break;
	case 2:
		printContacts(contacts, contactCount);
		break;
	case 3:
		printf("Введите имя ");
		scanf("%s", searchName);
		printContact(searchByName(contacts, contactCount, searchName));
		break;
	case 4:
		printf("Введите телефон ");
		scanf("%s", searchNumber);
		printContact(searchByNumber(contacts, contactCount, searchNumber));
		break;
	case 5:
		saveToFile(contacts, contactCount);
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;

	int contactsCount = 0;
	int contactBookCapacity = 10;
	Contact** contactBook = new Contact*[contactBookCapacity];

	FILE* pFile = fopen("book.txt", "w");

	while (!feof(pFile))
	{
		Contact* newContact = new Contact();
		fscanf(pFile, "%s %s\n", newContact->name, newContact->phone);
		if (strcmp(newContact->name, "") == 0)
		{
			break;
		}
		if (contactsCount == contactBookCapacity)
		{
			expandBook(contactBook, contactBookCapacity);
		}
		contactBook[contactsCount] = newContact;
		++contactsCount;
	}
	fclose(pFile);

	do {
		printMenu();
		printf("Ваш выбор: ");
		scanf("%d", &choice);
		makeChoice(choice, contactBook, contactsCount, contactBookCapacity);
	} while (choice != 0);

	for (int i = 0; i < contactsCount; ++i)
	{
		delete contactBook[i];
	}
	delete[] contactBook;

	system("PAUSE");
	return 0;
}