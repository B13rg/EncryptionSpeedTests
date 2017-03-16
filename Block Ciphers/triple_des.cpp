#include <iostream>
#include <string>

#include "cryptopp/files.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/des.h"

using namespace CryptoPP;
using std::cout;
using std::endl;

class Triple_DES{
	private:
		SecByteBlock key(0x00, DES_EDE2::DEFAULT_KEYLENGTH);
		InvertibleRSAFunction params;
		AutoSeededRandomPool rng;
		byte iv[DES_EDE2::BLOCKSIZE];
	public:
		std::string plain, encoded, recovered;

		Triple_DES(string input);
		void encrypt_string();
		void decrypt_string();
		void triple_about();
};

void Triple_DES_encrypt::triple_DES_about(){
	cout << "-------------2-Key Triple-DES------------" << endl;
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

Triple_DES::Triple_DES(string input){
	rng.GenerateBlock(key, key.size());
	rng.GenerateBlock(iv, sizeof(iv));
}

void Triple_DES::encrypt_string(){
    CBC_Mode< DES_EDE2 >::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource ss1(plain, true, 
        new StreamTransformationFilter(e, 
		new StringSink(cipher)));
}

void Triple_DES::decrypt_string(){
	CBC_Mode< DES_EDE2 >::Decryption d;
	d.SetKeyWithIV(key, key.size(), iv);
	
	StringSource s3(cipher, true, 
		new SteamTranformationFilter(d, 
		new StringSink(recovered)));
}