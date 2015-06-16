#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;

    
//***********************
// Account Number ADT
//***********************

class AccountNo {                       /* Value range: 0001-9999 */
public:
    AccountNo ();                       /* New account number                          */
    explicit AccountNo ( int number );  /* Existing account number (for lookups)       */
    int number () const;                /* Accessor -- integer value of account number */
private:
    int number_;
    static int next_;
    static int const maxVal_ = 9999;
};


// initialization of static data member to the lowest legal value
int AccountNo::next_ = 1;


// constructor -- constructs a new unique account number
AccountNo::AccountNo () {
    if ( next_ > maxVal_ )
        exit (1);
    number_ = next_++;
}

// constructor -- converts an integer into an account number
// REQUIRES:  number corresponds to an existing account number
AccountNo::AccountNo ( int number ) {
    if ( (number > maxVal_) || (number < 1) )
        exit(1);
    number_ = number;
}


// accessor - returns account number value of object
int AccountNo::number() const {
    return number_;
}


// comparison operators
bool operator== (const AccountNo &a, const AccountNo &b) {
    return a.number() == b.number();
}

bool operator!= (const AccountNo &a, const AccountNo &b) {
    return !(a==b);
}

bool operator< (const AccountNo &a, const AccountNo &b) {
    return a.number() < b.number();
}

bool operator<= (const AccountNo &a, const AccountNo &b) {
    return (a<b) || (a==b);
}

bool operator> (const AccountNo &a, const AccountNo &b) {
    return !(a<=b);
}

bool operator>= (const AccountNo &a, const AccountNo &b) {
    return !(a<b);
}


// streaming operators
istream& operator>> ( istream &sin, AccountNo &a ) {
    int number;
    sin >> number;
    a = AccountNo(number);
    
    return sin;
}

ostream& operator<< ( ostream &sout, const AccountNo &a ) {
    sout.setf(ios::internal);
    sout.width(4);
    sout.fill('0');
    sout << a.number();
    
    return sout;
}


//*******************
// Account
//*******************

class Account {
public:                                             // PUBLIC interface of Account
    explicit Account ( const AccountNo& );          // constructor
    virtual ~Account() {}                           // destructor
    int balance () const;                           // accessor - returns balance as an integer
    virtual void call ( int duration ) = 0;         // records information about a call (e.g., duration of call in minutes)
    virtual void bill () = 0;                       // decrements balance by monthly fee and the cost of using extra minutes
    void pay (int amount);                          // increments balance by amount paid
    virtual void print() const;                     // prints information about the account (e.g., account number, balance, minutes used ths month
protected:
    AccountNo accountNumber () const; // getter for accountNumber object
    int minutesUsed () const; // getter for minutes, returned as int
    void minutesUsedIs (int minutes); // setter for minutes
    void balanceIs (int balance); // setter for balance

private:
    int balance_; // balance is common to all accounts
    int minutesUsed_; // minutesUsed is tracked by all accounts
    AccountNo accountNumber_; // accountNumber is tracked by all accounts
};


//************************************************************************
//* YOUR IMPLENTATION OF ACCOUNT, CHEAP_ACCOUNT, EXPENSIVE_ACCOUNT HERE 
//************************************************************************

// constructor which sets accountNo to value passed in and balance and minutes to 0
Account::Account (const AccountNo& number): accountNumber_(number), minutesUsed_(0), balance_(0) {}

// return the accountNo object
AccountNo Account::accountNumber() const {
    return accountNumber_;
}

// have empty print as the derived classes should override
void Account::print () const {
}

// return minutesUsed in account as int
int Account::minutesUsed() const {
    return minutesUsed_;
}

// set the minutesUsed
void Account::minutesUsedIs(int minutes) {
    minutesUsed_ = minutes;
}

// set the balance
void Account::balanceIs(int balance) {
    balance_ = balance;
}

// pay towards the balance
void Account::pay( int amount ) {
    balance_ += amount;
}

// getter for the balance, returned as int
int Account::balance() const {
    return balance_;
}

class ExpensiveAccount: public Account { // derived from Account
public:
    ExpensiveAccount(const AccountNo& accountNumber): 
        Account(accountNumber),
        monthlyRate_(100) {} // use parent constructor
    void call ( int duration); // implement call; user override if c++ 11
    void bill (); // implement bill
    void print () const; // implement print
private:
    const int monthlyRate_; // const rate for expensive
};

// print function for ExpensiveAccount
void ExpensiveAccount::print () const {
    cout << "ExpensiveAccount:" << endl;
    cout << "  Account number = " << accountNumber() << endl;
    cout << "  Balance = $" << balance() << endl;
}

// call function, increment minutes by duration
void ExpensiveAccount::call (int duration) {
    minutesUsedIs(minutesUsed() + duration);
}

// bill function, subtract rate from current balance
void ExpensiveAccount::bill () {
    balanceIs(balance() - monthlyRate_);
    minutesUsedIs(0);
}

class CheapAccount: public Account { // derived from Account
public:
    CheapAccount(const AccountNo& accountNumber): 
        Account(accountNumber),
        includedMinutes_(200),
        monthlyRate_(30),
        ratePerMinute_(1) {} // use parent constructor
    void call ( int duration); // implement call
    void bill (); // implement bill
    void print () const; // implement print
private:
    const int includedMinutes_; // const as free minutes don't change
    const int monthlyRate_; // const as rate doesn't change
    const int ratePerMinute_; // const as rate for extra minute doesn't change
};

// print details of cheap account
void CheapAccount::print () const {
    cout << "CheapAccount:" << endl;
    cout << "  Account number = " << accountNumber() << endl;
    cout << "  Balance = $" << balance() << endl;
    cout << "  Minutes = " << minutesUsed() << endl;
}
 
// increment total minutes with duration
void CheapAccount::call (int duration) {
    minutesUsedIs(minutesUsed() + duration);
}

void CheapAccount::bill () {
    int extraMinutes = minutesUsed() - includedMinutes_;
    // take the greater of overtime minutes or 0
    if ((extraMinutes) < 0) {
        extraMinutes = 0;
    }
    // subtract overtime minutes and rate from balance
    balanceIs(balance() - monthlyRate_ - ratePerMinute_*extraMinutes);
    minutesUsedIs(0); // reset minutes back to 0
}

//************************************************************************
//  Helper variables and functions for test harness
//************************************************************************

//  test-harness operators
enum Op { NONE, NewE, NewC, Balance, Call, Bill, Pay, PrintAll };


//  converts a one-character input comment into its corresponding test-harness operator
Op convertOp( string opStr ) {
    switch( opStr[0] ) {
        case 'E': return NewE; 
        case 'C': return NewC;
        case 'b': return Balance;
        case 'c': return Call;
        case 'B': return Bill;
        case 'p': return Pay;
        case 'P': return PrintAll;
        default: {
            cerr << "Invalid operation " << opStr << endl;
            return NONE;
        }
    }
}


// Reads anumber from cin and finds the corresponding Phone Service account
// REQUIRES: the next word to read from cin is an integer
// RETURNS: a pointer to a found account.  Otherwise, returns NULL
Account* findAccount( map<AccountNo,Account*>  &accounts) {
    int num;
    cin >> num;
    AccountNo act( num );
    map<AccountNo,Account*>::iterator iter;
    iter = accounts.find( act );
    if ( iter == accounts.end() ) {
        cerr << "Invalid Account Number!" << endl;
        return NULL;
    }
    return iter->second;
}
    

//*******************
// main()
//*******************

int main () {
    cout << "Test harness for family of phone-service accounts:" << endl << endl;
    map<AccountNo, Account*> accounts;
    
    cout << "Command: ";
    string command;
    cin >> command;
    
    Op op = convertOp(command);
    
    while ( !cin.eof() ) {
        switch ( op ) {
                /* Constructors */
            case NewE: {
                AccountNo act;
                Account* p = new ExpensiveAccount( act );
                accounts.insert( pair<AccountNo,Account*>( act, p ) );
                p->print();
                break;
            }
            case NewC: {
                AccountNo act;
                Account* p = new CheapAccount( act );
                accounts.insert( pair<AccountNo,Account*>( act, p ) );
                p->print();
                break;
            }
                
                /* Accessors */
            case Balance: {
                Account* p = findAccount( accounts );
                if ( p!= NULL)
                    cout << "Value of balance data member is: " << p->balance() << endl;
                break;
            }
                
                /* Phone Service Operations */
            case Call: {
                Account* p = findAccount( accounts );
                if ( p != NULL ) {
                    int duration;
                    cin >> duration;
                    p->call( duration );
                }
                break;
            }
                
                
            case Bill: {
                map<AccountNo,Account*>::iterator iter;
                map<AccountNo,Account*>::iterator end = accounts.end();
                for ( iter = accounts.begin(); iter != end; iter++ ) {
                    (iter->second)->bill();
                }
                break;
            }
                
                
            case Pay: {
                Account* p = findAccount( accounts );
                if (p != NULL ) {
                    int amt;
                    cin >> amt;
                    p->pay(amt);
                }
                break;
            }
                
                
                /* Print Accounts */
            case PrintAll: {
                map<AccountNo,Account*>::iterator iter;
                map<AccountNo,Account*>::iterator end = accounts.end();
                for ( iter = accounts.begin(); iter != end; iter++ ) {
                    (iter->second)->print();
                }
                break;
            }
            default: {
                break;
            }
        } // switch 
        
        cout << endl << "Command: ";
        cin >> command;
        op = convertOp(command);
        
    } // while cin OK
    
    map<AccountNo,Account*>::iterator iter;
    map<AccountNo,Account*>::iterator end = accounts.end();
    for ( iter = accounts.begin(); iter != end; iter++ ) 
      delete iter->second;

    return 0;
}
