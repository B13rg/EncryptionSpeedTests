#include <iostream>
#include <string>

#include "cryptopp/files.h"
#include "cryptopp/modes.h"
#include "cryptopp/filters.h"
#include "cryptopp/serpent.h"

using namespace CryptoPP;
using std::cout;
using std::endl;

class Serp_encrypt{
	private:
		SecByteBlock key(0x00, Serpent::DEFAULT_KEYLENGTH);
		InvertibleRSAFunction params;
		AutoSeededRandomPool rng;
		byte iv[Serpent::BLOCKSIZE];
		string plain, encoded, revocered;
	
	public:
		Serp_encrypt(string input);
		void encrypt_string();
		void decrypt_string();
		void Serp_about();
};

void Serp_encrypt::Serp_about(){
	cout << "-------------Serpent------------" << endl;
	cout << "Key length (min): " << Serpent::MIN_KEYLENGTH << endl;
	cout << "Key length (max): " << Serpent::MAX_KEYLENGTH << endl;
	cout << "Key length: " << Serpent::DEFAULT_KEYLENGTH << endl;
	cout << "Block size: " << Serpent::BLOCKSIZE << endl;
	
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

Serp_encrypt::Serp_encrypt(string input){
	rng.GenerateBlock(iv, key.size());
	plain = input;
	rng.GenerateBlock(iv, sizeof(iv));
}

void Serp_encrypt::encrypt_string(){
	CBC_Mode<Serpent>::Encryption e;
	e.SetKeyWithIV(key, key.size(), iv);
    StringSource ss1(plain, true, 
        new StreamTransformationFilter(e,
        new StringSink(cipher)
    ));
}

void Serp_encrypt::decrypt_string(){
	CBC_Mode<Serpent>::Decryption d;
	d.SetKeyWithIV(key, key.size(), iv);
    StringSource ss1(cipher, true, 
        new StreamTransformationFilter(d,
        new StringSink(recovered)
    ));
}