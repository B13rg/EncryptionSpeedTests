#include <iostream>
#include <string>

#include "cryptopp/files.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/rc5.h"

using namespace CryptoPP;
using std::cout;
using std::endl;

class RC5_encrypt{
	private:
		SecByteBlock key(RC5::DEFAULT_KEYLENGTH);
		InvertibleRSAFunction params;
		AutoSeededRandomPool rng;
		byte iv[RC5::BLOCKSIZE];
	public:
		std::string plain, encoded, recovered;

		RC5_encrypt(string input);
		void encrypt_string();
		void decrypt_string();
		void RC5_about();
};

void RC5_encrypt::RC5_about(){
	cout << "----------------RC5---------------" << endl;
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

RC5_encrypt::RC5_encrypt(string input){
	SecByteBlock key(RC5::DEFAULT_KEYLENGTH);
	rng.GenerateBlock(iv, sizeof(iv));
	plain = input;
}

void RC5::encrypt_string(){
    CBC_Mode< RC5 >::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource s1(plain, true, 
        new StreamTransformationFilter(e, 
		new StringSink(cipher)));
}

void RC5::decrypt_string(){
	CBC_Mode< RC5 >::Decryption d;
	d.SetKeyWithIV(key, key.size(), iv);
	
	StringSource s3(cipher, true, 
		new SteamTranformationFilter(d, 
		new StringSink(recovered)));
}