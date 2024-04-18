#pragma once
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// ������� ��� �������� ���������� email
void isValidEmail(const string& email, bool& isValid) {
    regex pattern("^[a-zA-Z0-9._%+-]+@(mail.ru|bk.ru|yandex.ru|inbox.ru|list.ru|internet.ru|xmail.eu|gmail.com|yahoo.com|hotmail.com|outlook.com)$");
    isValid = regex_match(email, pattern);
}

// ������� ��� ����������� ������ ������������
bool registerUser() {
    std::string email, password;

    do {
        bool validEmail = false;
        do {
            std::cout << "������� email: ";
            std::cin >> email;

            isValidEmail(email, validEmail);
            if (!validEmail) {
                std::cout << "������� �������� ������ �����. ���������� �����.\n";
            }
        } while (!validEmail);

        bool validPassword = false;
        do {
            std::cout << "������� ������ (�� ����� 8 ���� �� ��������): ";
            std::cin >> password;

            if (password.length() < 8) {
                std::cout << "������ ������ ��������� �� ����� 8 ����. ���������� �����.\n";
            }
            else {
                validPassword = true;
            }
        } while (!validPassword);

        // ���������� ������ � ���� ������� .csv
        std::ofstream file("users.csv", std::ios::app);
        file << email << "," << password << "\n";
        file.close();

        std::cout << "������������ ������� ���������������!\n";

        return true; // �������� �����������
    } while (true);

    return false; // ���� � ������������ �� ���������� ������������������
}
