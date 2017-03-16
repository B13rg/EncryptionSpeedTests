#include <iostream>
#include <chrono>
#include <string>

#include "twofish.cpp"	//Twofish
#include "serpent.cpp"	//Serpent
#include "regular.cpp"	//AES

const string PLAINTEXT = "1BhEk676RAUBoXVyZMtK6uAyVG148nVzpi1AbhfzaqozKo7gpkUua3syJTKvwfiXaUUFEfU0W1uEZ4dQZIX8NcwicTOfHSa4ePVJeaEehBhu7rk4sPNOWyDzHhVlD3owcW6vGpPONHB0w8XJnEhYNZ3SJH5xq3AzIrimx7PT9pwWRxPUXqdocJUjv2X2eUP7Y91onCvP7QiQeSALmEgnXwpC3xoRzsB7eNacEdPq7CFGVq8lwEnojfTLRsO2c76zz8JF6WWulzhhhhVEqUfmaULexu6RxLQLYbEkwuspJRNY0QFghoAQXyVF4erLUY3KvqBUKOPyD412P5gz8fjKlgORRTYgTfsCJPPYHBeYfZe8SSHEnW6XnLmz5O9aClaMXaeJdO80qkIfNGVQf0fEvEYIV25v5c4Xhiito8wFal0azIFDR96IoZGfR67XdBF5u4xx68sWYOnYE0xTeJZOVMp0Q6ODYNnZ0AX7J0dbEtGKX5RW86r2nr9ZFNxpGHo9rEpv8COB3bC6xpFyl5wmz5ZhwlZolKM5lYH5ZTnfPGWeftyCpL0saeDKOsLVTnVsiyPDaFnpnkYsjdqt8MdlydKsag2BO5GcqMPckHGZEAFrmiioxSbQoaszMouS3MnwoZJBy6jE5dclYnokWHjrYmAF8aUcDmPF1G3piD2gDx15jZWhmsuN0W0vcTUSnRvuoevXps32fRsQJEikcAZSPvTjFzrP5HJvoGNOrPxVvq2h32k9Qs06XuGXqrMNFx51lDzbqSuRf29ZMLUBONXJ99STXMruLpY5aRceRk3PNdnkbf8HzJRRLwdLwSsaTC2py5cOu3UgCNdw8yohs5SN6Ll8A80BBG5kRj3ISk1RUijw86pZTloyaeOvQnTBgS0wUP0N0xjYyfbktil1JpEYnWbhCrrvK32iBBctaunVddyciWAAOdMzV7FhzkqBX5aBXytq8l8Pyjv3UASgwmo0D3fXpbYgL4v2hnTuCj6Z"

int main(){
	AES_encrypt aes(PLAINTEXT);
	Serp_encrypt serp(PLAINTEXT);
	Twofish_encrypt twofish(PLAINTEXT);
	
	high_resolution_clock::time_point t1, t2;
	auto 	d_aes_en, d_aes_de, 
			d_serp_en, d_serp_de,
			d_fish_en, d_fish_de;
	
	
	/**************AES**************\
	\*******************************/
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		aes.encrypt_string();
		t2 = high_resolution_clock::now();
		d_aes_en += d_aes_en_cast<microseconds>(t2-t1).count();
	}
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		aes.decrypt_string();
		t2 = high_resolution_clock::now();
		d_aes_de += d_aes_de_cast<microseconds>(t2-t1).count();
	}
	aes.AES_about();
	
	
	/************Serpent************\
	\*******************************/
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		serp.encrypt_string();
		t2 = high_resolution_clock::now();
		d_serp_en += d_serp_en_cast<microseconds>(t2-t1).count();
	}
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		serp.decrypt_string();
		t2 = high_resolution_clock::now();
		d_serp_de += d_serp_de_cast<microseconds>(t2-t1).count();
	}
	serp.Serp_about();
	
	
	/***********Twofish*************\
	\*******************************/
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		twofish.encrypt_string();
		t2 = high_resolution_clock::now();
		d_fish_en += d_fish_en_cast<microseconds>(t2-t1).count();
	}
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		twofish.decrypt_string();
		t2 = high_resolution_clock::now();
		d_fish_de += d_fish_de_cast<microseconds>(t2-t1).count();
	}
	twofish.Twofish_about();

	
	/***********Averages************\
	\*******************************/
	cout << endl << "----------------Averages----------------" << endl;
	cout << "AES:" << endl;
	cout << "	Average encrypt time: " << d_aes_en/50.0 << endl;
	cout << "	Average decrypt time: " << d_aes_de/50.0 << endl;
	
	cout << "Serpent:" << endl;
	cout << "	Average encrypt time: " << d_serp_en/50.0 << endl;
	cout << "	Average decrypt time: " << d_serp_de/50.0 << endl;
	
	cout << "TwoFish:" << endl;
	cout << "	Average encrypt time: " << d_fish_en/50.0 << endl;
	cout << "	Average decrypt time: " << d_fish_de/50.0 << endl;
	
	return 0;
}
