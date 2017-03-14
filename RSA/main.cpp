#include <iostream>
#include <string>

#include "../cryptopp/files.h"
#include "../cryptopp/modes.h"
#include "../cryptopp/osrng.h"
#include "../cryptopp/rsa.h"
#include "../cryptopp/sha.h"

using namespace CryptoPP;
using std::cout;
using std::endl;

class RSA_encrypt{
	private:
		RSA::PrivateKey privateKey;
		InvertibleRSAFunction params;
	public:
		RSA::PublicKey publicKey;
		std::string plain, cipher, recovered;

		RSA_encrypt();
		void encrypt_string();
		void decrypt_string();
};

RSA_encrypt::RSA_encrypt(){
	AutoSeededRandomPool rng;
	//InvertibleRSAFunction params;
	params.GenerateRandomWithKeySize(rng, 3072);


	cout << "---------Dump----------" << endl;
	cout << "RSA Parameters:" << endl;
	cout << " n: " << params.GetModulus() << endl << endl;
	cout << " p: " << params.GetPrime1() << endl << endl;
	cout << " q: " << params.GetPrime2() << endl << endl;
	cout << " d: " << params.GetPrivateExponent() << endl << endl;
	cout << " e: " << params.GetPublicExponent() << endl << endl;


	RSA::PrivateKey privtemp(params);
	privateKey = privtemp;
	RSA::PublicKey pubtemp(params);
	publicKey = pubtemp;
}

void RSA_encrypt::encrypt_string(){
	cout << "Enter string to encrypt: ";
	std::cin >> plain;

	AutoSeededRandomPool rng;
	RSAES_OAEP_SHA_Encryptor e(publicKey);

	StringSource ss1(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
}

void RSA_encrypt::decrypt_string(){
	cout << "Cipher: " << cipher << endl;

	AutoSeededRandomPool rng;
	RSAES_OAEP_SHA_Decryptor d(privateKey);

	StringSource ss2(cipher, true, new PK_DecryptorFilter(rng, d, new StringSink(recovered)));

	cout << "Plain text: " << recovered << endl;
}




int main(){
	RSA_encrypt cryptor;
	cryptor.encrypt_string();
	cryptor.decrypt_string();



	return 0;
}
