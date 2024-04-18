#pragma once
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// ������� ��� ����������� ������������
void authenticateUser() {
    std::string email, password;

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
        std::cout << "������� ������: ";
        std::cin >> password;

        // ��������� ������ � ����� � �� ������������, ����� �� ��������������
        if (password.length() < 8) {
            std::cout << "������ ����� �������. ���������� �����.\n";
        }
        else {
            validPassword = true;
        }
    } while (!validPassword);

    std::ifstream file("users.csv");
    if (!file.is_open()) {
        std::cout << "���� � �������������� �� ������.\n";
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
        cout << "���� �������� �������!\n";
    }
    else {
        cout << "������ �� �����. ���������� �����.\n";
    }

    file.close();
}