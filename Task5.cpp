#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>   
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    char raz[] = " ,.!?:;-";
    char s[81];
    char* word;
    int count = 0;
    bool isgrow;
    cout << "Введите текст: ";
    cin.getline(s, 81);
    word = strtok(s, raz);
    while (word != 0)
    {
        for (int i = 1; i < strlen(word); i++)
        {
            if ((word[i - 1] - 'A') > (word[i] - 'A'))
            {
                isgrow = false;
                break;
            }
            else
            {
                isgrow = true;
            }
        }
        if (isgrow == true)
        {
            cout << word << endl;;
            count += 1;
        }
        word = strtok(0, raz);
    }
    if (count == 0)
    {
        cout << "Такие слова в тексте отсутствуют" << endl;
    }
}
