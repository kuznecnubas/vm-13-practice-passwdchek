#include <iostream>
using namespace std;

int checkLettersUpper(string password){
    int letters = 0;
    for (int i = 0; i < password.length(); i++){
        if (isupper(password[i])) letters++;
    }
    return letters;
}

int checkLettersLower(string password){
    int letters = 0;
    for (int i = 0; i < password.length(); i++){
        if (islower(password[i])) letters++;
    }
    return letters;
}

int checkDigits(string password){
    int digits = 0;
    for (int i = 0; i < password.length(); i++){
        if (isdigit(password[i])) digits++;
    }
    return digits;
}

int checkSymbols(string password){
    int symbols = 0;
    for (int i = 0; i < password.length(); i++){
        if (password[i] == '-' || password[i] == '!' || password[i] == '#' || password[i] == '$' ||
            password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '@' ||
            password[i] == '^') symbols++;
    }
    return symbols;
}

int main(){
    string password;
    while (true) {
        cout << "\033[2J\033[1;1H"; //очистка
        cout << "Проверка пароля\n" << endl;
        if (checkLettersUpper(password) <= 0) cout << "Пароль должен содержать большие буквы (QWE)" << endl;
        if (checkLettersLower(password) <= 0) cout << "Пароль должен содержать маленькие буквы (qwe)" << endl;
        if (checkDigits(password) <= 0)cout << "Пароль должен содержать цифры (123)" << endl;
        if (checkSymbols(password) <= 0)cout << "Пароль должен содержать символы (!@#)" << endl;
        cout << "Введите пароль: ";
        getline(cin, password);
    }
}