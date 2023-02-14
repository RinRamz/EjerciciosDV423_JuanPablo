#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>

using namespace std;

int _numeroMagico = 0;

string _input;
int _numero = 0;
bool _isInt;

bool checkInteger(string input);
void GuessMyNumber();

int main()
{
    srand(time(NULL));
    GuessMyNumber();
}

bool checkInteger(string input)
{
    int itr = 0;

    if (input.size() == 0)
    {
        return false;
    }

    if (input[0] == '-')
    {
        return false;
    }

    if (input == "0")
    {
        return false;
    }

    for (int i = itr; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}

void GuessMyNumber()
{
    cout << "Bienvenido a Guess My Number, se generara un numero al azar entre el 1 y el 100, suerte!" << endl;
    _numeroMagico = 1 + rand() % (101 - 1);
    cout << _numeroMagico << endl;
    cout << "Numero al azar generado!\n" << "Hora de adivinar!" << endl;

    while (_numero != _numeroMagico)
    {
        cout << "Por favor ingrese un numero entero del 1 al 100" << endl;
        cin >> _input;
        _isInt = checkInteger(_input);
        while (!_isInt)
        {
            cout << "Ingresa un numero valido porfis" << endl;
            cin >> _input;
            _isInt = checkInteger(_input);
        }
        _numero = stoi(_input);

        if (_numero > _numeroMagico)
        {
            if (_numero - _numeroMagico <= 5)
            {
                cout << "Casi!" << endl;
            }
            else if (_numero - _numeroMagico <= 10)
            {
                cout << "Estas muy cerca!" << endl;
            }

            cout << "Mas abajo!" << endl;
        }
        else if (_numero < _numeroMagico)
        {
            if (_numeroMagico - _numero <= 5)
            {
                cout << "Casi!" << endl;
            }
            else if (_numeroMagico - _numero <= 10)
            {
                cout << "Estas muy cerca!" << endl;
            }

            cout << "Mas arriba!" << endl;
        }
    }

    cout << "Has adivinado, felicidades!" << endl;
}


