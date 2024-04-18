#pragma once
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Функция для проверки валидности email
void isValidEmail(const string& email, bool& isValid) {
    regex pattern("^[a-zA-Z0-9._%+-]+@(mail.ru|bk.ru|yandex.ru|inbox.ru|list.ru|internet.ru|xmail.eu|gmail.com|yahoo.com|hotmail.com|outlook.com)$");
    isValid = regex_match(email, pattern);
}

// Функция для регистрации нового пользователя
bool registerUser() {
    std::string email, password;

    do {
        bool validEmail = false;
        do {
            std::cout << "Введите email: ";
            std::cin >> email;

            isValidEmail(email, validEmail);
            if (!validEmail) {
                std::cout << "Введены неверные данные почты. Попробуйте снова.\n";
            }
        } while (!validEmail);

        bool validPassword = false;
        do {
            std::cout << "Введите пароль (не менее 8 цифр на латинице): ";
            std::cin >> password;

            if (password.length() < 8) {
                std::cout << "Пароль должен содержать не менее 8 цифр. Попробуйте снова.\n";
            }
            else {
                validPassword = true;
            }
        } while (!validPassword);

        // Сохранение данных в файл формата .csv
        std::ofstream file("users.csv", std::ios::app);
        file << email << "," << password << "\n";
        file.close();

        std::cout << "Пользователь успешно зарегистрирован!\n";

        return true; // Успешная регистрация
    } while (true);

    return false; // Если у пользователя не получилось зарегистрироваться
}
