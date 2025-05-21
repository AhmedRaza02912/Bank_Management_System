

This file explains each part of the C++ Bank Management System project to help students understand its structure and functionality.
-----------------------------------------
1. Account Structure
-----------------------------------------
struct Account - This defines a structure to store data for each bank account:
- funds (int): amount in the account
- accountId (string): unique ID of the account
- password (string): password for user authentication
- name (string): name of the account holder

Account A[10]; - Creates an array of 10 accounts.

-----------------------------------------
2. Utility Functions
-----------------------------------------
heading() - Displays a decorative heading for the bank system.

end() - Shows the program end banner.

-----------------------------------------
3. Main Functionalities
-----------------------------------------
add_Account() - Creates a new bank account by taking input from the user and storing it in the array.

search_Account() - Finds and shows account details by matching the password.

delete_Account() - Deletes an account by setting its fields to empty or 0.

deposit_Amount() - Deposits a user-defined amount into an account.

retrieve_Amount() - Withdraws a user-defined amount if the account has enough funds.

Transactions() - Menu for choosing between deposit and withdraw operations.

-----------------------------------------
4. Admin Functions
-----------------------------------------
All_accounts() - (Was showing all stored accounts using a file. Now removed file reading.)

access_History() - (Was showing the log history of admin access. File operations removed.)

check_Transactions() - (Was showing transaction history. File operations removed.)

admin_Operations() - Menu to access admin functions: All accounts, Access history, Check transactions.

-----------------------------------------
5. Main Menu - main()
-----------------------------------------
Displays the main menu with the following options:
1. Create Account
2. Search Account
3. Delete Account
4. Transactions (Deposit/Withdraw)
5. Admin Menu
6. Exit

This loop continues until the user chooses "Exit".

-----------------------------------------
Note for Students:
-----------------------------------------
- Data is stored temporarily in the array, which means all records are lost when the program ends.
- Ideal for learning how a bank system works using basic C++ concepts like structures, arrays, functions, conditionals, and loops.
