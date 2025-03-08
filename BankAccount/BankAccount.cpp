#include <iostream>
#include <string>
#include <fstream>

class BankAccount{

    private:

        struct subAccount{
            int* balance;
            std::string* Name;
        };


        struct MainAccount{
            std::string* username;
            std::string* password;
            int* balance;
            subAccount* checking;
            subAccount* savings;
            MainAccount* nextAccount;
        };
        
        MainAccount* firstAccount;
    public:

        BankAccount(){
            firstAccount = nullptr;
        }

        void whatToDo(){
            std::cout << "What would you like to do?" << std::endl;
        }

        void clearTerminal(){
            std::cout << "\033[2J\033[H";
        }

        void saveAccounts() {
            std::ofstream file("accounts.txt");
            if (!file) {
                std::cerr << "Error opening file!\n";
            return;
            }
    
            MainAccount* current = firstAccount;
            while (current) {
                file << *(current->username) << " " << *(current->password) << " " << *(current->balance) << "\n";
                current = current->nextAccount;
            }

            file.close();
        }
        void loadAccounts() {
            std::ifstream file("accounts.txt");
            if (!file) {
                std::cerr << "No existing accounts found.\n";
                return;
            }

            while (true) {
                MainAccount* newAccount = new MainAccount;
                newAccount->username = new std::string;
                newAccount->password = new std::string;
                newAccount->balance = new int;
                newAccount->checking = nullptr;
                newAccount->savings = nullptr;
                newAccount->nextAccount = nullptr;

            if (!(file >> *(newAccount->username) >> *(newAccount->password) >> *(newAccount->balance))) {
                delete newAccount->username;
                delete newAccount->password;
                delete newAccount->balance;
                delete newAccount;  // Prevent memory leak
                break;  // Exit loop when there's nothing left to read
            }

        accountLink(newAccount);
    }

    file.close();
}

        void accountLink(MainAccount* account){
            if (firstAccount == nullptr){
                firstAccount = account;
            }
            else{
                MainAccount* current = firstAccount;
                while (current->nextAccount != nullptr){
                    current = current->nextAccount;
                }
                current->nextAccount = account;
            }
        }

        void invalid(int *value){
            std::string invalidPrompt = "Invalid input! Please try again: ";
            std::cout << invalidPrompt;
            std::cin >> *value;
            while (*value != 1 && *value != 2){
                std::cout << invalidPrompt;
                std::cin >> *value;
                if (*value == 1 || *value == 2){
                    continue;
                }
            }
        }

        void accountBalance(MainAccount* account, int value){
            int balanceMod;
            if (value == 1){
                clearTerminal();
                std::cout << "How much would you like to deposit?: ";
                std::cin >> balanceMod;
                *(account->balance) += balanceMod;
            }
            else if (value == 2){
                clearTerminal();
                std::cout << "How much would you like to withdraw?: ";
                std::cin >> balanceMod;
                *(account->balance) -= balanceMod;
            }

        }

        void viewBalance(MainAccount* account){
            std::cout << "You have $" << *(account->balance) << " in your account!" << std::endl;
        }

        void rename(MainAccount* account){
            std::cout << "What would you like to rename your account to?: ";
            std::string newUsername;
            std::cin >> newUsername;
            if (newUsername == *(account->username)){
                std::cout << "Cannot rename your account to the same username!" << std::endl;
                rename(account);
            }
            else{
                *(account->username) = newUsername;
            }
            clearTerminal();
        }

        void printAccountData(MainAccount* account){
            std::cout << "Full account data: " << std::endl;
            std::cout << "Username: " << *(account->username) << std::endl;
            std::cout << "Password: " << *(account->password) << std::endl;
            if (account->checking == nullptr){
                std::cout << "No active checking account!" << std::endl;
            }
            if (account->savings == nullptr){
                std::cout << "No active savings account!" << std::endl;
            }
            std::cout << "Account Balance: $" << *(account->balance) << std::endl;
        }

        void changePassword(MainAccount* account){
            clearTerminal();
            std::cout << "What would you like to change your password to?: ";
            std::string newPassword;
            std::cin >> newPassword;
            if (newPassword == *(account->password)){
                std::cout << "Cannot change your password to the same password!" << std::endl;
                changePassword(account);
            }
            else{
                *(account->password) = newPassword;
            }
            clearTerminal();
            accountAction(account);
        }

        void toFinishViewing(MainAccount* account){
            std::cout << std::endl;
            std::cout << "Please type in 1 when you are finished viewing the data: ";
            int end;
            std::cin >> end;
            if (end == 1){
                clearTerminal();
                accountAction(account);
            }
        }
        void mainAccountActions(){
            std::cout << "To modify your balance, type 1: " << std::endl;
            std::cout << "To rename your account: type 2: " << std::endl;
            std::cout << "To view your balance, type 3: " << std::endl;
            std::cout << "To view entire account data, type 4: " << std::endl;
            std::cout << "To change your password, type 5: " << std::endl;
            std::cout << "To exit account, type 6: " << std::endl;
            std::cout << "Type in your desired action: ";
        }

        void accountAction(MainAccount* account){
            whatToDo();
            mainAccountActions();
            int action;
            std::cin >> action;
            if (action == 1){
                clearTerminal();
                whatToDo();
                std::cout << "To deposit money, type 1: " << std::endl;
                std::cout << "To withdraw money, type 2: " << std::endl;
                std::cout << "Type in your desired action: ";
                std::cin >> action;
                if (action != 1 && action != 2){
                    invalid(&action);
                }
                if (action == 1 || action == 2){
                    accountBalance(account, action);
                    accountAction(account);
                }
            }
                else if (action == 2){
                    clearTerminal();
                    rename(firstAccount);
                    clearTerminal();
                    accountAction(account);
                }
                else if (action == 3){
                    clearTerminal();
                    viewBalance(account);
                    toFinishViewing(account);
                }
                else if (action == 4){
                    clearTerminal();
                    printAccountData(account);
                    toFinishViewing(account);
                }
                else if(action == 5){
                    changePassword(account);
                }
                else if(action == 6){
                    clearTerminal();
                    return;
                }
        }
        
        void accessAccount(){
            std::cout << "Please enter in your username: ";
            std::string username;
            std::cin >> username;
            std::cout << "Please enter in your password: ";
            std::string password;
            std::cin >> password;
            
            if (firstAccount != nullptr && firstAccount->nextAccount == nullptr){
                if (*(firstAccount->username) != username || *firstAccount->password != password){
                    std::cout << "Invalid username or password" << std::endl;
                }
                else if (*(firstAccount->username) == username && *firstAccount->password == password){
                    accountAction(firstAccount);
            }
        }

        }
        void openAccount(){
            MainAccount* newAccount = new MainAccount;
            newAccount->nextAccount = nullptr;
            newAccount->balance = new int(0);
            std::string user;
            std::cout << "What would you like your username to be?: ";
            std::cin >> user;
            newAccount->username = new std::string(user);
            std::cout << "What would you like your password to be?: ";
            std::string password;
            std::cin >> password;
            newAccount->password = new std::string(password);
            std::cout << "Would you like to open a checking? ";
            std::cout << "Type 1 for Yes, 2 for No: ";
            int x;
            std::cin >> x;
            if ((x != 1) && (x != 2)){
                invalid(&x);
            }
            if (x == 1){
                subAccount* newChecking = new subAccount;
                std::cout << "What would you like to call your checking?: ";
                std::string checkingName;
                std::cin >> checkingName;
                newChecking->Name = &checkingName;
                newChecking->balance = 0;
                newAccount->checking = newChecking;
                std::cout << std::endl;
            }
            else{
                std::cout << "Ok! " << std::endl;
            }
            std::cout << "Would you like to open a saving? ";
            std::cout << "Type 1 for Yes, 2 for No: ";
            int y;
            std::cin >> y;
            if (y != 1 && y != 2){
                invalid(&y);
            }
            if (y == 1){
                subAccount* newSaving = new subAccount;
                std::cout << "What would you like to call your saving?: ";
                std::string savingName;
                std::cin >> savingName;
                newSaving->Name = &savingName;
                newSaving->balance = 0;
                std::cout << std::endl;
                newAccount->savings = newSaving;
            }
            else{
                std::cout << "Ok!" << std::endl;
                newAccount->savings = nullptr;
            }
            accountLink(newAccount);
        }

        void openingActions(){
            std::cout << "To open an account, type 1: " << std::endl;
            std::cout << "To access an account, type 2: " << std::endl;
            std::cout << "If you are done, type 3 " << std::endl;
            std::cout << "Please type in your desired action: ";
        }

        int openingPrompt(){
            while(true){
                whatToDo();
                openingActions();
                int x;
                std::cin >> x;
                if (x == 1){
                    clearTerminal();
                    openAccount();
                    clearTerminal();
                }
                else if (x == 2){
                    clearTerminal();
                    accessAccount();
                }
                else if (x == 3){
                    saveAccounts();
                    return 0;
                }
            }
            return 0;
        }

        ~BankAccount(){
            delete firstAccount->username;
            delete firstAccount->balance;
            delete firstAccount;
            std::cout << "Deconstructor called successfully!" << std::endl;

        }

};
int main(){
    
    BankAccount myBankApp;
    myBankApp.loadAccounts();
    myBankApp.openingPrompt();


    return 0;
}