#include "../Account/account.h"
Account accountTab[] =
    // Table with Account-objects.
    {
        Account("Twain, Mark", 1234567, -3434.30),
        Account("Crusoe, Robinson", 200000, 0.00),
        Account("Temple, Shirley", 543001, +777.70),
        Account("Valentin, Carl", 543002, -1111.10),
};

int cnt  = sizeof(accountTab)/sizeof(Account);
int displayOverdraw(const Account *acc, int cnt, double limit);
int main()
{
     double limit = 0.0;
     cout << "Output the overdrawn accounts!\n"
          << "These are the accounts, which fell below \n"
          << "the limit, ex. -1000.00.\n"
          << endl;
     cout << "What is the limit? ";
     cin >> limit;
     cout << "Listing the overdrawn accounts:\n"
          << endl;

     
     if (displayOverdraw(accountTab, cnt, limit) == 0)
         cout << "\nNo account found!"
              << endl;
     return 0;
}

int displayOverdraw(const Account *acc, int cnt, double limit){
     int count = 0;
     const Account* temp ;
     for(temp = acc;temp < (acc+cnt); temp++){
          if(temp->getBalance() < limit){
               temp->display();
               ++count;
          }
     }

     return count;
}