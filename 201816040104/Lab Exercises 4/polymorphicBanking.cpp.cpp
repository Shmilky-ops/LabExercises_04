// Lab 1: polymorphicBanking.cpp
// Processing Accounts polymorphically.
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include "Account.cpp" // Account class definition
#include "SavingsAccount.cpp" // SavingsAccount class definition
#include "CheckingAccount.cpp" // CheckingAccount class definition

int main()
{
   // create vector accounts
   /* Write declarations for a vector of four pointers
      to Account objects, called accounts */
  vector<Account * >accounts(4);

   // initialize vector with Accounts
   accounts[ 0 ] = new SavingsAccount( 25.0, .03 );
   accounts[ 1 ] = new CheckingAccount( 80.0, 1.0 );
   accounts[ 2 ] = new SavingsAccount( 200.0, .015 );
   accounts[ 3 ] = new CheckingAccount( 400.0, .5 );

   cout << fixed << setprecision( 2 );

   // loop through vector, prompting user for debit and credit amounts
   for ( size_t i = 0; i < accounts.size(); i++ )
   {
      cout << "Account " << i + 1 << " balance: $"
         << accounts[i]->getBalance()/* Call the getBalance function through Account pointer i */;

      double withdrawalAmount = 0.0;
      cout << "\nEnter an amount to withdraw from Account " << i + 1
         << ": ";
      cin >> withdrawalAmount;
      /* Call the debit function through Account pointer i */
      accounts[i]->debit(withdrawalAmount);

      double depositAmount = 0.0;
      cout << "Enter an amount to deposit into Account " << i + 1
         << ": ";
      cin >> depositAmount;
      /* Call the credit function through Account pointer i */
      accounts[i]->credit(depositAmount);

      // downcast pointer
      SavingsAccount *savingsAccountPtr =dynamic_cast<SavingsAccount*> (accounts[i]);
         /* Write a dynamic_cast operation to to attempt to downcast
		    Account pointer i to a SavingsAccount pointer */

      // if Account is a SavingsAccount, calculate and add interest
      if ( savingsAccountPtr/* Write a test to determine if savingsAccountPtr isn't 0 */ )
      {
         double interestEarned = /* Call member function calculateInterest
								    through savingsAccountPtr */savingsAccountPtr->calculateInterest();
         cout << "Adding $" << interestEarned << " interest to Account "
            << i + 1 << " (a SavingsAccount)" << endl;
         /* Use the credit function to credit interestEarned to
		    the SavingsAccount pointed to by savingsAccountPtr*/
		    accounts[i]->credit(interestEarned);
      } // end if

      cout << "Updated Account " << i + 1 << " balance: $"
         << accounts[i]->getBalance()/* Call the getBalance function through Account pointer i */
		 << "\n\n";
   } // end for
} // end main
