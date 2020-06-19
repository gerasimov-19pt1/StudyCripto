// Gerkules- программа вычисления хэш-функции
// от содержимого файла используя библиотеку Crypto++
// PR 4-1
#include <iostream>
#include <string>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <cryptopp/channels.h>
#include <cryptopp/filters.h>

using namespace std;
using namespace CryptoPP;

int main ()
{
    try {
        std:CryptoPP::SHA1 sha1;
        string hash;

        const char* FILE = "FilePR4";

        cout << "Calculating the hash function using the algorithm " << sha1.AlgorithmName() << endl;
        cout << "File name: " << FILE << endl;

        HashFilter filter(sha1, new HexEncoder(new StringSink(hash)));

        ChannelSwitch cs;
        cs.AddDefaultRoute(filter);

        FileSource(FILE, true, new Redirector(cs));

        cout << "Hash from " << FILE << ": " << hash << endl;
    }

    catch (const Exception &ex) {
        cerr << ex.what() << endl;
        return 1;
    }

    return 0;
}