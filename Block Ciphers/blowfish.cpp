#include <iostream>
#include <string>

#include "cryptopp/files.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/blowfish.h"

using namespace CryptoPP;
using std::cout;
using std::endl;

class Blowfish_encrypt{
	private:
		SecByteBlock key(Blowfish::DEFAULT_KEYLENGTH);
		InvertibleRSAFunction params;
		AutoSeededRandomPool rng;
		byte iv[Blowfish::BLOCKSIZE];
	public:
		std::string plain, encoded, recovered;

		Blowfish_encrypt(string input);
		void encrypt_string();
		void decrypt_string();
		void Blowfish_about();
};

void Blowfish_encrypt::Blowfish_about(){
	cout << "-------------Blowfish------------" << endl;
	cout << "Key length (min): " << Blowfish::MIN_KEYLENGTH << endl;
	cout << "Key length (max): " << Blowfish::MAX_KEYLENGTH << endl;
	cout << "Key length: " << Blowfish::DEFAULT_KEYLENGTH << endl;
	cout << "Block size: " << Blowfish::BLOCKSIZE << endl;
	
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

Blowfish_encrypt::Blowfish_encrypt(string input){
	SecByteBlock key(Blowfish::DEFAULT_KEYLENGTH);
	rng.GenerateBlock(iv, sizeof(iv));
	plain = input;
}

void Blowfish::encrypt_string(){
    CBC_Mode< Blowfish >::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource s1(plain, true, 
        new StreamTransformationFilter(e, 
		new StringSink(cipher)));
}

void Blowfish::decrypt_string(){
	CBC_Mode< Blowfish >::Decryption d;
	d.SetKeyWithIV(key, key.size(), iv);
	
	StringSource s3(cipher, true, 
		new SteamTranformationFilter(d, 
		new StringSink(recovered)));
}