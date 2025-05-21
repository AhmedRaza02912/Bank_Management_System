#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;
// FUNCTIONS USED
// one to create account.
// one to search for account existence.
// transaction fucntion that has sub fucntions to deposit and retrieve amount. 
// one function to deal with admin operations.
// one exit function.
// FILES USED
// one to store all accounts.
// one to store when admins accessed to check all accounts.
// one to store transactions made.
int i=0;
struct Account
{
    int funds;
    string accountId, password, name;
};
Account A[10];
void heading()
{
    int ascii = 178;
    char ch = ascii;
    cout << "\n ";
    for (int i = 1; i <= 26; i++)
    cout << ch;
    cout << " BANK MANAGEMENT SYSTEM ";
    for (int i = 1; i <= 26; i++)
    cout << ch;
}

void end()
{
    system("cls");
    int ascii = 178;
    char ch = ascii;
    cout << "\n ";
    for (int i = 1; i <= 26; i++)
    cout << ch;
    cout << " PROGRAM ENDED ";
    for (int i = 1; i <= 26; i++)
    cout << ch;
}

void write_to_file()
{
    ofstream mybank("file1.txt"); // this file holds all registered account details.
    mybank << "ID\t    Amount\t\tName" << endl;
    for (int j = 0; j <= i; j++) 
    mybank << A[j].accountId << "\t    " << A[j].funds << "\t\t" << A[j].name << endl;
    mybank.close();
	
}


void add_Account()
{
    system("cls");
    heading();
    cout << "\n\nEnter your account ID(XX-123): ";
    getline(cin >> ws, A[i].accountId);
    cout << "\n\nEnter your full name : ";
    getline(cin >> ws, A[i].name, '.');
    cout << "\n\nEnter your password: ";
    getline(cin >> ws, A[i].password);
    cout << "\n\nDeposit your amount: ";
    cin >> A[i].funds;
    cout << "\n\nACCOUNT HAS BEEN CREATED! ";
    cout << "\n\nPress any key to return to Main Menu";
    write_to_file();
    i++;   //increment number of accounts.
	getch();                        
}

void search_Account()
{
    system("cls");
    heading();
    string password;
    int present = 0;
    cout << "\n\nEnter your password: ";
    cin >> password;
    for (int a = 0; a <= i; a++)
    {
        if (password == A[a].password)
        {    
            
            cout << "\n\nWelcome: " << A[a].name;    
            cout << "\n\nAccount ID: " << A[a].accountId;
            cout << "\n\nAmount stored: " << A[a].funds;
            present++;
        }
    }
    if (present==0)
    cout << "\nInvalid Password!!";
    cout << "\n\nPress any key to return to Main Menu";
    getch();
}

void delete_Account()
{
    system("cls");
    heading();
    string password;
    int found = 0;
    cout << "\n\nEnter the account password to delete: ";
    getline(cin >> ws,password);
    for(int a =0; a <=i; a++)
    {
    	if(password == A[a].password)
    	{   
    	    
    		A[a].funds = 0;
    		A[a].accountId= " ";
    		A[a].name= " ";
    		found++;
		}
		write_to_file();
    }
    cout<<"\n\nAccount successfully deleted! ";
    if (found == 0)
    cout << "\nAccount not found or incorrect password!";
    cout << "\n\nPress any key to return to Main Menu";
    getch();
}

void deposit_Amount()
{
    system("cls");
    heading();
    string password;
    int amount;
    cout << "\n\nEnter account password: ";
    cin >> password;
    for (int a = 0; a <= i; a++)
    {
        if (password == A[a].password)
        {
            cout << "\nEnter amount to be deposited: ";
            cin >> amount;
            A[a].funds += amount;
            cout << "\nSUCCESSFUL";
            cout << "\nAccount now stores: " << A[a].funds;
            write_to_file();
            fstream transactions("file2.txt", ios::out | ios::app); // file 2 stores all transactions made by users.
            transactions << A[a].accountId <<"\t "<< amount <<"\t\t"<<" Deposited"<<endl;
            transactions.close();
        }
    }
    cout << "\n\nPress any key to return to Main Menu";
    getch();
}

void retrieve_Amount()
{
    system("cls");
    heading();
    string password;
    cout<< "\n\nEnter account password: ";
    cin >> password;
    for (int a = 0; a <= i; a++)
    {
        if (password == A[a].password)
        {
            cout<< "\nEnter amount to be retrieved: ";
            int amount;
            cin >> amount;
            if (amount > A[a].funds)
                cout << "\nYour account doesn't have enough amount to be retrieved!";
            else
            {
                A[a].funds -= amount;
                cout << "\nSUCCESSFUL\n";
                cout << "\nAccount now stores: " << A[a].funds;
                write_to_file();
            }
            fstream transactions("file2.txt", ios::out | ios::app);
            transactions << A[a].accountId <<"\t "<< amount <<"\t\t"<<" Retrieved"<<endl;
            transactions.close();
        }
    }
    cout << "\n\nPress any key to return to Main Menu";
    getch();
}
void Transactions()
{   
    system("cls");
    heading();
	cout<<" \n\n1. DEPOSIT AMOUNT";
	cout<<" \n\n2. WITHDRAW AMOUNT";
	int choice;
	cout<<" \n\nEnter choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			deposit_Amount();
			break;
		case 2:
			retrieve_Amount();
			break;
		default:
			cout<<"\n\nInvalid";
		
	}
}
void All_accounts()
{
    system("cls");
    heading();
    string date, password, admin, storedPassword = "ABC123";
    string admin1 = "44AbuDhabi";
    cout << "\n\nEnter password: ";
    cin>>password;
    if (password != storedPassword)
        cout << "\n\nWrong Entry!!";
    else
    {
        cout << "\n\nEnter today's date(dd/mm/yy): ";
        cin >> date;
        cout << "\n\nEnter admin name: ";
        getline(cin >> ws, admin);
        if (admin != admin1)
        cout << "\n\nAdmin Name incorrect!!";
        else
        {   
            fstream adminLogins("file3.txt", ios::out | ios::app); // file3 holds admin record 
		                                                   // for when they accessed the database.
            adminLogins << date << "\t\t" << admin << endl;
            adminLogins.close();
            cout << "\n\n\t\tACCOUNTS DATABASE";
            cout<<"\n------------------------------------------------\n";
            fstream mybank("file1.txt", ios::in);
           while(!mybank.eof())
		   {
           	string line;
           	getline(mybank, line);
           	cout<<line<<endl;
		   }
		   mybank.close();
            cout<<"\n------------------------------------------------\n";
            
        }
    }
    cout << "\n\nPress any key to return to Main Menu";
    getch();
}

void access_History()
{
    system("cls");
    heading();
    string accessPassword = "ABC123";
    string password;
    cout << "\n\nEnter password:";
    cin >> password;
    if (password == accessPassword)
    {
        cout << "\n\n\t\tADMIN ACCESS DATABASE";
        fstream adminLogins("file3.txt", ios::in);
        cout << "\n-------------------------------------------------------\n";
        while (!adminLogins.eof())
        {
            string line;
            getline(adminLogins, line);
            cout << line << endl;
        }
        cout << "\n-------------------------------------------------------\n";
        cout << "\nPress any key to return to Main Menu";
        adminLogins.close();
        getch();
    }
    else
        cout << "\n\nWrong Password!!";
        getch();
}
void check_Transactions()
{   
    system("cls");
	fstream transactions("file2.txt", ios::in);
	while(!transactions.eof())
	{
		string line;
		getline(transactions, line);
		cout<<line<<endl;
	}
	transactions.close();
}

void admin_Operations()
{   
    system("cls");
    heading();
	cout<<"\n\n 1. SHOW ALL ACCOUNTS";    // all registered accounts.
	cout<<"\n\n 2. ACCESS HISTORY";       // admin logins history.
	cout<<"\n\n 3. CHECK TRANSACTIONS";     
	short int choice;
	cout<<"\n\n Enter your choice: ";
	cin>>choice;
	switch (choice)
	{
		case 1:
			All_accounts();
			break;
		case 2:
			access_History();
			break;
		case 3:
			check_Transactions();
			break;
		default:
			cout<<"\n\n INVALID";
			break;
	}
	getch();
}

int main() 
{
    fstream adminLogins("file3.txt", ios::out | ios::app);
    adminLogins << "Date\t\t Admin Name" << endl;
    adminLogins.close();
    fstream transactions("file2.txt", ios::out | ios::app);
    transactions << "ID\t Amount \t\tTransactions"<<endl;
    transactions.close();
    short int choice;
do{ 

    system("cls");
    heading();
    cout << "\n\n 1. CREATE ACCOUNT";
    cout << "\n\n 2. SEARCH ACCOUNT";
    cout<<"\n\n 3. DELETE ACCOUNT";
    cout<<"\n\n 4. TRANSACTIONS ";
    cout<<"\n\n 5. ADMIN";
    cout << "\n\n 6. EXIT";
    cout << "\n\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add_Account();
        break;
    case 2:
        search_Account();
        break;
    case 3:
        delete_Account();
        break;
    case 4:
        Transactions();
        break;
    case 5:
        admin_Operations();
        break;
    default:
        cout << "\n\nIncorrect!!";
        break;
    }
}while(choice !=6);
  end();
  return 0;
}

