#include <iostream>
#include <string>

#include "cryptopp/files.h"
#include "cryptopp/modes.h"
#include "cryptopp/filters.h"
#include "cryptopp/cast256.h"

using namespace CryptoPP;
using std::cout;
using std::endl;

class Twofish_encrypt{
	private:
		SecByteBlock key(0x00, Twofish::DEFAULT_KEYLENGTH);
		InvertibleRSAFunction params;
		AutoSeededRandomPool rng;
		byte iv[Twofish::BLOCKSIZE];
		string plain, encoded, revocered;
	
	public:
		Twofish_encrypt(string input);
		void encrypt_string();
		void decrypt_string();
		void Serp_about();
};

void Twofish_encrypt::Twofish_about(){
	cout << "-------------Twofish------------" << endl;
	cout << "Key length (min): " << Twofish::MIN_KEYLENGTH << endl;
	cout << "Key length (max): " << Twofish::MAX_KEYLENGTH << endl;
	cout << "Key length: " << Twofish::DEFAULT_KEYLENGTH << endl;
	cout << "Block size: " << Twofish::BLOCKSIZE << endl;
	
	cout << "\nIV: " << iv << endl;
	cout << "Key: " << key << endl;
	cout << "Plain: " << plain << endl;
	
	StringSource ss2(cipher, true,
    new HexEncoder(
        new StringSink(encoded)
    ));
	
	cout << "Cipher text: " << encoded << endl;
	cout << "Recovered: " << recovered << endl;
}

Twofish_encrypt::Twofish_encrypt(string input){
	rng.GenerateBlock(iv, key.size());
	plain = input;
	rng.GenerateBlock(iv, sizeof(iv));
}

void Twofish_encrypt::encrypt_string(){
	CBC_Mode<Twofish>::Encryption e;
	e.SetKeyWithIV(key, key.size(), iv);
    StringSource ss1(plain, true, 
        new StreamTransformationFilter(e,
        new StringSink(cipher)
    ));
}

void Twofish_encrypt::decrypt_string(){
	CBC_Mode<Twofish>::Decryption d;
	d.SetKeyWithIV(key, key.size(), iv);
    StringSource ss3(cipher, true, 
        new StreamTransformationFilter(d,
        new StringSink(recovered)
    ));
}