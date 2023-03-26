// 01.04.23_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
char* changeWord(char* text, char* str1, char* str2);
int main()
{
    setlocale(LC_ALL, "RUS");
    int i = 0;
    FILE* file;
    char* buffer = new char[200];
    char* buf = new char[50];
    char* buf2 = new char[50];
    if (fopen_s(&file, "myFile.txt", "r") != 0) {
        cout << "Не удалось открыть файл";
    }
    else {
        while (!feof(file)) {
            fgets(buffer, 199, file);
            cout << buffer;
            i++;
        }
        if (!(fclose(file) == 0)) {
            cout << "Файл закрыт с ошибкой";
        }
        cout << endl;
    }
    char** text = new char* [i];
    i = 0;
    if (fopen_s(&file, "myFile.txt", "r") != 0) {
        cout << "Не удалось открыть файл";
    }
    else {
        cout << "Введите заменяемое слово: " << endl;
        cin >> buf;
        cout << "На что меняем?: " << endl;
        cin >> buf2;
        while (!feof(file)) {
            char* buffer2 = new char[200];
            fgets(buffer2, 199, file);
            text[i] = changeWord(buffer2, buf, buf2);
            i++;
        }
        if (!(fclose(file) == 0)) {
            cout << "Файл закрыт с ошибкой";
        }
        cout << endl;
    }
    if (fopen_s(&file, "myFile.txt", "w") != 0) {
        cout << "Не удалось открыть файл";
    }
    else {
        for (int j = 0; j < i; j++) {
            fprintf(file, text[j]);
            fprintf(file, "\n");
        }
        if (!(fclose(file) == 0)) {
            cout << "Файл закрыт с ошибкой";
        }
        cout << endl;
    }
    return 0;
}

char* changeWord(char* text, char* str1, char* str2) {
    if (!strstr(text, str1)) {
        return text;
    }
    else {
        char* firstSymbol = strstr(text, str1);
        char* textNew = new char[strlen(text) - strlen(str1) + strlen(str2) + 1];
        int i = 0;
        for (; i < firstSymbol - text; i++) {
            textNew[i] = text[i];
        }
        for (; i < firstSymbol - text + strlen(str2); i++) {
            textNew[i] = str2[i - (firstSymbol - text)];
        }
        for (int m = 0; i < strlen(text) - strlen(str1) + strlen(str2) + 1; i++, m++) {
            textNew[i] = text[firstSymbol - text + strlen(str1) + m];
        }
        delete[]text;
        return changeWord(textNew, str1, str2);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
