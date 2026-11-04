
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class UserAccount
{
private:
    string username;
    string email;
    string role;
    double balance;
    bool isActive;
public:
	UserAccount(string username_, string email_, string role_, double balance_, bool isActive_) :
		username(username_), email(email_), role(role_), balance(balance_), isActive(isActive_) {
        if (balance < 0.0) {
			balance = 0.0;
			cout << "Баланс не може бути від'ємним. Встановлено значення 0.0." << endl;
        }
	}
	UserAccount(string username_, string email_) :
		UserAccount(username_, email_, "User", 0.0, true){
	}
	UserAccount(string username_, string email_, double initialBonus) :
		UserAccount(username_, email_, "User", initialBonus, true) {
	}
	UserAccount(string username_, string email_, string role_) :
		UserAccount(username_, email_, role_, 0.0, true) {
	}

	void displayInfo() const {
		cout << "Ім'я користувача: " << username << endl;
		cout << "Електронна пошта: " << email << endl;
		cout << "Роль: " << role << endl;
		cout << "Баланс: " << balance << endl;
		cout << "Активний: " << (isActive ? "Так" : "Ні") << endl;
		cout << "-----------------------------" << endl;
	}
	

	
	
	
	
};

class TransactionAmount {
private:
	double amountInUAH;
public:
	explicit TransactionAmount(double uah) : amountInUAH(uah) {
		if (uah <= 0.0) {
			amountInUAH = 0.01;
			cout << "Сума повинна бути більшою за 0. Встановлено 0.01 грн." << endl;
		}
	}
	double getAmount() const {
		return amountInUAH;
	}
};

void processPayment(TransactionAmount payment){
	cout << fixed << setprecision(2);
	cout << "[СИСТЕМА] Успішно проведено платіж на суму: " << payment.getAmount() << " грн." << endl;
}

int main()
{
	int  choice;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do {
		cout << "Виберіть завдання (1-2, 0 - вихід):";
		cin >> choice;

		switch (choice) {
		case 1: {
			UserAccount user1("JohnDoe", "johndoe@example.com");
			user1.displayInfo();
			

			UserAccount user2("JohnDoe", "johndoe@example.com", 100.0);
			user2.displayInfo();

			UserAccount user3("JohnDoe", "johndoe@example.com", "Programer");
			user3.displayInfo();

			UserAccount user4("JohnDoe", "johndoe@example.com", "Programer", 4435.0, true);
			user4.displayInfo();
			break;
		}

		case 2: {
			TransactionAmount t1(500.0);
			processPayment(t1); 
			processPayment(TransactionAmount(1200.50)); 
			//processPayment(2500); // Спроба передати просто число
			//'void processPayment(TransactionAmount)': cannot convert argument 1 from 'int' to 'TransactionAmount'
			//Ключове слово explicit забороняє автоматичне перетворення чисел на об'єкти класу 
			// TransactionAmount. Завдяки цьому випадкове передавання ID замовлення або інших 
			// чисел не призведе до автоматичного створення платежу. Система вимагатиме явно 
			// створити об'єкт транзакції, що зменшує ризик помилкового списання коштів.
			break;
		}

		}

	} while (choice != 0);
}