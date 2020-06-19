// Gerkules-программа зашифрования и расшифрования файлов
// используя библиотеку Crypto++.
// Тип алгоритма шифрования — блочный. Режим шифрования — CBC.
// PR 4-2: main.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "AES.h"
#include "Blow.h"

using namespace std;
using namespace CryptoPP;

int main ()
{
    unsigned op, cip;
    string FileIn, FileOut, Pass;

    do {
        cout << "Enter operation number (0 - exit, 1 - encrypt, 2 - decrypt): ";
        cin >> op;

        if (op != 0) {
//           cout << "|1 - AES-256 \" << endl;
            //         cout << "|2 - Blowfish \" << endl;
            cout << "1 - AES-256 | " << endl;
            cout << "2 - Blowfish| " << endl;
            cout << "            '--> Select algorithm number: ";
            cin >> cip;

            if (op > 2) {
                cerr << "Error! Invalid operation number\n";
            }

            else if (op > 0) {
                cout << "\nEnter input  file name <name.txt>: ";
                cin >> FileIn;

                cout << "\nEnter output file name <name.txt>: ";
                cin >> FileOut;

                cout << "\nEnter Key: ";
                cin >> Pass;

                if (cip == 1) {
                    AES_Cryptor aes(FileIn, FileOut, Pass);

                    if (op == 1) {
                        if (aes.AES_Encrypt())
                            cout << "Successful encrypting!" << endl;
                        else
                            cout << "Encrypting failed!" << endl;
                    } else {
                        if (aes.AES_Decrypt())
                            cout << "Successful decrypting!" << endl;
                        else
                            cout << "Decryption failed!" << endl;
                    }
                } else if (cip == 2) {
                    BLOW_Cryptor b(FileIn, FileOut, Pass);

                    if (op == 1) {
                        if (b.BLOWFISH_Encrypt())
                            cout << "Successful encrypting!" << endl;
                        else
                            cout << "Encryption failed!" << endl;
                    } else {
                        if (b.BLOWFISH_Decrypt())
                            cout << "Successful decrypting!" << endl;
                        else
                            cout << "Decryption failed!" << endl;
                    }
                } else {
                    cerr << "Error! Wrong algorithm number!!!\n";
                }
            }
        }

    } while (op != 0);

    return 0;
}
