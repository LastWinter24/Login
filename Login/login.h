#pragma once
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Функция для авторизации пользователя
void authenticateUser() {
    std::string email, password;

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
        std::cout << "Введите пароль: ";
        std::cin >> password;

        // Считываем пароль в буфер и не обрабатываем, чтобы не перезаписывало
        if (password.length() < 8) {
            std::cout << "Пароль введён неверно. Попробуйте снова.\n";
        }
        else {
            validPassword = true;
        }
    } while (!validPassword);

    std::ifstream file("users.csv");
    if (!file.is_open()) {
        std::cout << "Файл с пользователями не найден.\n";
        return;
    }

    string line;
    bool authSuccess = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string savedEmail, savedPassword;
        getline(ss, savedEmail, ',');
        getline(ss, savedPassword, ',');

        if (email == savedEmail && password == savedPassword) {
            authSuccess = true;
            break;
        }
    }

    if (authSuccess) {
        cout << "Вход выполнен успешно!\n";
    }
    else {
        cout << "Данные не верны. Попробуйте снова.\n";
    }

    file.close();
}