#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>
#include "Register.h"
#include "login.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

    int choice;
    bool exitFlag = false;

    do {
        cout << "Выберите действие:\n1. Регистрация\n2. Авторизация\n3. Выход\n";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            authenticateUser();
            break;
        case 3:
            cout << "До свидания!\n";
            exitFlag = true;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    } while (!exitFlag);
	
	return 0;
}



