#include <iostream>
#include <fstream>
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
            password[i] == '^' || password[i] == '"' || password[i] == '=' || password[i] == '+') symbols++;
    }
    return symbols;
}

bool checkInBase(string password){
    string basePassword;
    ifstream base("../startedTasks/rockyou.txt");
    if (!base) {
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }

    while (!base.eof()){
        getline(base, basePassword);
        if (basePassword == password){
            base.close();
            return true;
        }
    }
    base.close();
    return false;
}

int main(){
    string password = " ";
    int reliability;
    system("chcp 65001");
    while (true) {
        cout << "\033[2J\033[1;1H"; //очистка
        reliability = 4;
        cout << "ПРОВЕРКА ПАРОЛЯ\n" << endl;

        if (checkLettersUpper(password) <= 1){
            cout << "Пароль должен содержать не менее 2 больших букв (QWE)" << endl;
            reliability--;
        }
        if (checkLettersLower(password) <= 1) {
            cout << "Пароль должен содержать не менее 2 маленьких букв (qwe)" << endl;
            reliability--;
        }
        if (checkDigits(password) <= 1) {
            cout << "Пароль должен содержать не менее 2 цифр (123)" << endl;
            reliability--;
        }
        if (checkSymbols(password) <= 1) {
            cout << "Пароль должен содержать не менее 2 символов (!@#)" << endl;
            reliability--;
        }

        if(checkInBase(password)){
            cout << "\nПароль найден в базе использованных" << endl;
        }
        else{
            if (reliability == 4){
                cout << "Пароль надёжный" << endl;
            }
            else if (reliability == 3){
                cout << "\nПароль средний" << endl;
            }
            else if (reliability == 2){
                cout << "\nПароль слабый" << endl;
            }
            else if (reliability == 1){
                cout << "\nПароль очень слабый" << endl;
            }
        }

        cout << "\nВведите пароль: ";
        getline(cin, password);


    }
}
