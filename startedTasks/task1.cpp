#include <iostream>
using namespace std;

void checkPassword(string password){
    for (int i = 0; i < password.length(); i++){
        cout << password[i];
    }
}

int main(){
    string password;
    cout << "Проверка пароля" << endl;
    cout << "Введите пароль: ";
    getline(cin, password);
    checkPassword(password);
}