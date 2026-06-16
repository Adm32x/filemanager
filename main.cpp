#include <iostream>
#include <cstdlib> 
#include <string>
#include <unistd.h>
using namespace std;

void showmenu() {
    system("clear");
    cout << "== fileManager-V1.0==" << endl;
    cout << "1. Посмотреть файлы" << endl;
    cout << "2. Переместиться в директорию" << endl;
    cout << "3. Создать директорию" << endl;
    cout << "0. Выход" << endl;
}

void director(string& directory) {
    system("clear");
    cout << "Введите директорию: ";
    cin >> directory;
    if (chdir(directory.c_str()) == 0) {
        cout << "Перешли в: " << directory << endl;
    } else {
        cout << "Ошибка: каталог не найден!" << endl;
    }
    cout << "Нажмите Enter, чтобы продолжить..." << endl;
    cin.ignore();
    cin.get();
}

void createFolder() {
    string name;
    system("clear");
    cout << "Введите имя папки: ";
    cin >> name;
    string cmd = "mkdir " + name;
    int result = system(cmd.c_str());
    if (result == 0) {
        cout << "Папка '" << name << "' создана!" << endl;
    } else {
        cout << "Ошибка: не удалось создать папку!" << endl;
    }
    cout << "Нажмите Enter, чтобы продолжить..." << endl;
    cin.ignore();
    cin.get();
}

int main() {
    int number;
    string directory;

    while (true) {
        showmenu();
        cin >> number;

        if (number == 1) {
            system("clear");
            system("ls");
            cout << "Нажмите Enter, чтобы вернуться в меню..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (number == 2) {
            director(directory);
        }
        else if (number == 3) {
            createFolder();
        }
        else if (number == 0) {
            cout << "Выход..." << endl;
            break;
        }
        else {
            cout << "Неверный выбор!" << endl;
            cout << "Нажмите Enter, чтобы продолжить..." << endl;
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}