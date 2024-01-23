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
            password[i] == '^') symbols++;
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
    while (true) {
        reliability = 4;
        cout << "ПРОВЕРКА ПАРОЛЯ\n" << endl;

        if (checkLettersUpper(password) <= 0){
            cout << "Пароль должен содержать большие буквы (QWE)" << endl;
            reliability--;
        }
        if (checkLettersLower(password) <= 0) {
            cout << "Пароль должен содержать маленькие буквы (qwe)" << endl;
            reliability--;
        }
        if (checkDigits(password) <= 0) {
            cout << "Пароль должен содержать цифры (123)" << endl;
            reliability--;
        }
        if (checkSymbols(password) <= 0) {
            cout << "Пароль должен содержать символы (!@#)" << endl;
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

        cout << "\033[2J\033[1;1H"; //очистка
    }
}
