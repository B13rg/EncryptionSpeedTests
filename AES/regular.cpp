#include <iostream>
#include <string>

#include "cryptopp/files.h"
#include "cryptopp/modes.h"
#include "cryptopp/filters.h"
#include "cryptopp/aes.h"

using namespace CryptoPP;
using std::cout;
using std::endl;

class AES_encrypt{
	private:
		SecByteBlock key(0x00, AES::DEFAULT_KEYLENGTH);
		InvertibleRSAFunction params;
		AutoSeededRandomPool rng;
		byte iv[AES::BLOCKSIZE];
		const char *cstr;
		int messageLen;
	public:
		char *encoded, *recovered;
		
		AES_encrypt(string input);
		void encrypt_string();
		void decrypt_string();
		void AES_about();
};

void AES_encrypt::AES_about(){
	cout << "-------------AES------------" << endl;
	cout << "Key length (min): " << AES::MIN_KEYLENGTH << endl;
	cout << "Key length (max): " << AES::MAX_KEYLENGTH << endl;
	cout << "Key length: " << AES::DEFAULT_KEYLENGTH << endl;
	cout << "Block size: " << AES::BLOCKSIZE << endl;
	
	cout << "\nIV: " << iv << endl;
	cout << "Key: " << key << endl;
	cout << "Plain: " << cstr << endl;
	
	StringSource ss2(cipher, true,
    new HexEncoder(
        new StringSink(encoded)
    ));
	
	cout << "Cipher text: " << encoded << endl;
	cout << "Recovered: " << recovered << endl;
}

AES_encrypt::AES_encrypt(string input){
	rng.GenerateBlock(key, key.size());
	rng.GenerateBlock(iv, AES::BLOCKSIZE);
	*cstr = input.c_str();
	messageLen = (int)strlen(cstr)+1;
}

void AES_encrypt::encrypt_string(){
	CFB_Mode<AES>::Encryption cfbEncryption(key, key.size(), iv);
	cfbEncryption.ProcessData((byte*)encoded, (byte*)cstr, messageLen);
}

void AES_encrypt::decrypt_string(){
	CFB_Mode<AES>::Decryption cfbEncryption(key, key.size(), iv);
	cfbEncryption.ProcessData((byte*)recovered, (byte*)encoded, messageLen);
}