#include <iostream>
#include <string>

//1. ���������� ����� ������

using namespace std;

char encryptCaesar(char c, int tShift, int alphabetLength = 26) {

    // ������ ��� ����������� ��������

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



//� ��������� ��� ���������� ��������� ������������� ����� ������ : 
// ��� ����� � ��������� ���������� �� ���� � �� �� ����� ������� � ��������.
// ����� ������� ����� ���� ��� �������������, ��� � ������������� � ��������
//  ���������� �����.���� ��� ������ �� ������ ����� ������� �������� �� �������,
//  �� �� �������������(�� ���� ����� � ������� 27 � ��� ����� ����� �a�, ����� �
//  ������� 28 � ��� �b� � ��� �����).
//
//��������, ����� abracadabra ��� ������ �� 10 ������� ����������� �
//  klbkmknklbk.���� ���������� ���� ���������� ������ ������.������� 
// ����(��������� � ��������) ������ �� �����.�������� ������� encrypt_caesar
//  �� ������ � �����, ������� ���������� �������� ������, ������������� ������ 
// ������ � ����������, ������ ������� �����.����� �������� ������� decrypt_caesar,
//  ����������� �������� ��������������.�������, ��� ������� ������ ������� ���� ��
//  ���������� ����; ���� ��� ���������� � ������ �������, �� �� ���� ������������.
//

//������ 1
//The quick brown fox jumps over the lazy dog
//Ymj vznhp gwtbs ktc ozrux tajw ymj qfed itl