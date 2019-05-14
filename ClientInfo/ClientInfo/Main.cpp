#include "AddressBook.h"

// function prototypes
char Menu();
void Proper_Noun(string &);

int main()
{
	cout << "Welcome to Your Address Book" <<endl<<endl;
	//open file and close if file not found
	AddressBook FAU;
	if(FAU.Get_count() == -1)
	{
		return 0;
	}
	//repeatable menues
	char ext='a';
	do{
		//Main Menu
		char opt = Menu();
		switch (opt)
		{
			case 'A':	{
							string first, last, addr, pn, info;
							cout <<"Enter the FIRST name of the contact you want to Add" <<endl;
							cin >> first;
							Proper_Noun(first);
							cout <<"Enter the LAST name of the contact you want to Add" <<endl;
							cin >> last;
							Proper_Noun(last);
							cout <<"Enter the ADDRESS of the contact you want to Add" <<endl;
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							getline(cin,addr);
							cout <<"Enter the PHONE NUMBER of the contact you want to Add" <<endl;
							cin >> pn;
							info = last + ' ' + first + ' ' + addr + ' ' + pn;
							FAU.Add(info);
						}
						break;
			case 'R':	{
							string fname, lname;
							cout <<"Enter the FIRST name of the contact you want to Remove" <<endl;
							cin >> fname;
							Proper_Noun(fname);
							cout <<"Enter the LAST name of the contact you want to Remove" <<endl;
							cin >> lname;
							Proper_Noun(lname);
							string name = lname+fname;
							FAU.Del(name);
						}
						break;
			case 'M':	{
							string fname, lname;
							cout <<"Enter the FIRST name of the contact you want to Modify" <<endl;
							cin >> fname;
							Proper_Noun(fname);
							cout <<"Enter the LAST name of the contact you want to Modify" <<endl;
							cin >> lname;
							Proper_Noun(lname);
							string name = lname+fname;
							FAU.Modify(name);
						}
						break;
			case 'S':	{
							string fname, lname;
							cout <<"Enter the FIRST name of the contact you are searching for" <<endl;
							cin >> fname;
							Proper_Noun(fname);
							cout <<"Enter the LAST name of the contact you are searching for" <<endl;
							cin >> lname;
							Proper_Noun(lname);
							string name = lname+fname;
							FAU.Search(name);
						}
						break;
			case 'D':	{
							FAU.Print();
						}
						break;
			case 'E':	{
							FAU.Save_Exit();
							ext='E';
						}
						break;
			default:	printf("errer: invalid transaction\n\n");  //errer for invalid input
						ext='E';
						break;
		}
	}while(ext!='E');
	//end
	cout << "\nThank you for using my program. :)\n";
	return 0;
}

char Menu()
{
	cout<<endl<<"Main Menu"<<endl;
	cout << "Please ENTER the letter that correspond to the option you would like to choose" <<endl;
	cout << "Add a contact.....................A\n";
	cout << "Remove a contact..................R\n";
	cout << "Modify a contact..................M\n";
	cout << "Search for a contact..............S\n";
	cout << "Display all contacts..............D\n";
	cout << "Exit & Save contacts..............E\n";
	char answer;
	cin >> answer;
	answer = toupper(answer);
	return answer;
}

//////////////////////////////////////////////////////////////////////
// Function Name: KeepGoing
// Precondition: None
// Postcondition: send users responce as char
// Description: ask user if they want to continue the program
//////////////////////////////////////////////////////////////////////
void Proper_Noun(string & str)
{
	str[0] = toupper(str[0]);
	//loot that makes all elements in an array lower case
	for(int i=str.length(); i>=1 ; i--)
	{
		str[i]=tolower(str[i]);
	}
	return;
}