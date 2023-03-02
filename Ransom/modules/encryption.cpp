#include "encryption.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <iomanip>

#include "../cryptopp/cryptlib.h"
#include "../cryptopp/aes.h"
#include "../cryptopp/rsa.h"
#include "../cryptopp/filters.h"
#include "../cryptopp/modes.h"
#include "../cryptopp/files.h"
#include "../cryptopp/hmac.h"
#include "../cryptopp/osrng.h"
#include "../cryptopp/blowfish.h"
#include "../cryptopp/eax.h"

#include "globals.h"

#define BUFFER_SIZE 16


void Crypting::encryptBlowfish(std::filesystem::path const& file) {
    //std::ifstream inpf(file.string().c_str(), std::ios::in|std::ios::binary);

    CryptoPP::AutoSeededRandomPool prng;

    CryptoPP::SecByteBlock key(CryptoPP::Blowfish::DEFAULT_KEYLENGTH);
    prng.GenerateBlock(key, key.size());

    CryptoPP::byte iv[CryptoPP::Blowfish::BLOCKSIZE];
    prng.GenerateBlock(iv, sizeof(iv));
    
    std::string _file = file.string();
    std::string Ifile = _file;
    std::string Efile = _file.substr(0, _file.find_last_of(".")) + ".enc";

    try {
        CryptoPP::EAX< CryptoPP::Blowfish >::Encryption e1;
        e1.SetKeyWithIV(key, key.size(), iv, sizeof(iv));

        CryptoPP::FileSource fs1(Ifile.c_str(), true,
            new CryptoPP::AuthenticatedEncryptionFilter(e1,
                new CryptoPP::FileSink(Efile.c_str())
            ));

        std::cout << "Encrypted image: " << file << std::endl;

    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
}





void encrypt(std::filesystem::path const& file) {
    Crypting _crypt;

    try {
        _crypt.encryptBlowfish(file);
        std::filesystem::remove(file);
    }
    catch (const std::exception& e) {
        std::cerr << "Encrypt error: " << e.what() << std::endl;
    }
}