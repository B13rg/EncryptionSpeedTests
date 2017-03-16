#include <iostream>
#include <string>

#include "cryptopp/files.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/idea.h"

using namespace CryptoPP;
using std::cout;
using std::endl;

class IDEA_encrypt{
	private:
		SecByteBlock key(IDEA::DEFAULT_KEYLENGTH);
		InvertibleRSAFunction params;
		AutoSeededRandomPool rng;
		byte iv[IDEA::BLOCKSIZE];
	public:
		std::string plain, encoded, recovered;

		IDEA_encrypt(string input);
		void encrypt_string();
		void decrypt_string();
		void IDEA_about();
};

void IDEA_encrypt::IDEA_about(){
	cout << "----------------IDEA--------------" << endl;
	cout << "IV: " << iv << endl;
	cout << "Key: " << key << endl;
	cout << "Plain: " << plain << endl;
	
	StringSource ss2(cipher, true,
    new HexEncoder(
        new StringSink(encoded)
    ));
	
	cout << "Cipher text: " << encoded << endl;
	cout << "Recovered: " << recovered << endl;
}

IDEA_encrypt::IDEA_encrypt(string input){
	SecByteBlock key(IDEA::DEFAULT_KEYLENGTH);
	rng.GenerateBlock(iv, sizeof(iv));
	plain = input;
}

void IDEA::encrypt_string(){
    CBC_Mode< IDEA >::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource s1(plain, true, 
        new StreamTransformationFilter(e, 
		new StringSink(cipher)));
}

void IDEA::decrypt_string(){
	CBC_Mode< IDEA >::Decryption d;
	d.SetKeyWithIV(key, key.size(), iv);
	
	StringSource s3(cipher, true, 
		new SteamTranformationFilter(d, 
		new StringSink(recovered)));
}