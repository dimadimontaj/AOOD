#include <iostream>
using namespace std;

void main() 
{
    setlocale(LC_ALL, "rus");

    bool exist = false;
    bool error = false;

    char email[255];
    char test[] = { "'/\*(),+=;:%$#№!^<>?`{}[] " };

    cout << "Введите адрес почты: ";
    cin >> email;

    for (int i = 0; i < strlen(email); i++) 
    {
        if (email[i] != '@')
        {
            for (int j = 0; j < strlen(test); j++) 
            {
                if (email[i] == test[j])
                {
                    error = true;
                    break;
                }
                if (email[i] == '_' && email[i+1] == '_') 
                {
                    error = true;
                    break;
                }
            }
        }
        else exist = true;

        if (error)
            break;
    }
    if (exist && !error)
        cout << "Email адрес корректен!" << endl;
    else cout << "Email адрес не корректен!" << endl;

}
