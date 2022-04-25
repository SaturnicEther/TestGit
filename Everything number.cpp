#include <iostream>
#include <string>

//1. Реализация шифра Цезаря

using namespace std;

char encryptCaesar(char c, int tShift, int alphabetLength = 26) {

    // только для однобайтных символов

    if (tShift == 0) return c;
    if (tShift > alphabetLength) tShift %= alphabetLength;
    if (tShift < -alphabetLength)  tShift = -((-tShift) % alphabetLength);

    if (tShift > 0) {
        if (c >= 'A' && c <= 'Z') {
            if (tShift <= 'Z' - c)  c += tShift;
            else c += (tShift - alphabetLength);
        }
        if (c >= 'a' && c <= 'z') {
            if (tShift <= 'z' - c)  c += tShift;
            else c += (tShift - alphabetLength);
        }
    }
    else {									// tShift  < 0
        if (c >= 'A' && c <= 'Z') {
            if (tShift >= 'A' - c)  c += tShift;
            else c += (tShift + alphabetLength);
        }
        if (c >= 'a' && c <= 'z') {
            if (tShift >= 'a' - c)  c += tShift;
            else c += (tShift + alphabetLength);
        }
    }
    return c;

}


char decryptCaesar(char c, int tShift) 
{
    return encryptCaesar(c, -tShift);
}

//sijfkjfsdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddjpppppppppppppppppppd
// test

int main() 
{

    using namespace std;


    string originalText, encryptedText = "", decryptedText = "";

    originalText = "The quick brown fox jumps over the lazy dog";

    for (int i = 0; i < originalText.size(); i++)
        encryptedText += encryptCaesar(originalText[i], 5);

    cout << encryptedText << "\n";

    for (int i = 0; i < originalText.size(); i++)
        decryptedText += decryptCaesar(encryptedText[i], 5);

    cout << decryptedText << "\n\n";


    originalText = "Lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua Ut enim ad minim veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur Excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum";
    encryptedText = ""; decryptedText = "";

    for (int i = 0; i < originalText.size(); i++)
        encryptedText += encryptCaesar(originalText[i], 5);

    cout << encryptedText << "\n";

    for (int i = 0; i < originalText.size(); i++)
        decryptedText += decryptCaesar(encryptedText[i], 5);

    cout << decryptedText << "\n";

    return 0;
}



//В древности для шифрования сообщений использовался такой способ : 
// все буквы в сообщении сдвигались на одно и то же число позиций в алфавите.
// Число позиций могло быть как положительным, так и отрицательным и являлось
//  параметром шифра.Если для сдвига на данное число позиций алфавита не хватает,
//  то он зацикливается(то есть буква с номером 27 — это снова буква «a», буква с
//  номером 28 — это «b» и так далее).
//
//Например, слово abracadabra при сдвиге на 10 позиций превратится в
//  klbkmknklbk.Этот простейший шифр называется шифром Цезаря.Регистр 
// букв(заглавные и строчные) менять не нужно.Напишите функцию encrypt_caesar
//  от строки и числа, которая возвращает исходную строку, зашифрованную шифром 
// Цезаря с параметром, равным данному числу.Также напишите функцию decrypt_caesar,
//  выполняющую обратное преобразование.Считаем, что входные строки состоят лишь из
//  английских букв; если там содержатся и другие символы, то их надо игнорировать.
//

//Пример 1
//The quick brown fox jumps over the lazy dog
//Ymj vznhp gwtbs ktc ozrux tajw ymj qfed itl