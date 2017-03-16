#include <iostream>
#include <chrono>
#include <string>

#include "blowfish.cpp"
#include "triple_des.cpp"
#include "idea.cpp"
#include "rc5.cpp"

const string PLAINTEXT = "1BhEk676RAUBoXVyZMtK6uAyVG148nVzpi1AbhfzaqozKo7gpkUua3syJTKvwfiXaUUFEfU0W1uEZ4dQZIX8NcwicTOfHSa4ePVJeaEehBhu7rk4sPNOWyDzHhVlD3owcW6vGpPONHB0w8XJnEhYNZ3SJH5xq3AzIrimx7PT9pwWRxPUXqdocJUjv2X2eUP7Y91onCvP7QiQeSALmEgnXwpC3xoRzsB7eNacEdPq7CFGVq8lwEnojfTLRsO2c76zz8JF6WWulzhhhhVEqUfmaULexu6RxLQLYbEkwuspJRNY0QFghoAQXyVF4erLUY3KvqBUKOPyD412P5gz8fjKlgORRTYgTfsCJPPYHBeYfZe8SSHEnW6XnLmz5O9aClaMXaeJdO80qkIfNGVQf0fEvEYIV25v5c4Xhiito8wFal0azIFDR96IoZGfR67XdBF5u4xx68sWYOnYE0xTeJZOVMp0Q6ODYNnZ0AX7J0dbEtGKX5RW86r2nr9ZFNxpGHo9rEpv8COB3bC6xpFyl5wmz5ZhwlZolKM5lYH5ZTnfPGWeftyCpL0saeDKOsLVTnVsiyPDaFnpnkYsjdqt8MdlydKsag2BO5GcqMPckHGZEAFrmiioxSbQoaszMouS3MnwoZJBy6jE5dclYnokWHjrYmAF8aUcDmPF1G3piD2gDx15jZWhmsuN0W0vcTUSnRvuoevXps32fRsQJEikcAZSPvTjFzrP5HJvoGNOrPxVvq2h32k9Qs06XuGXqrMNFx51lDzbqSuRf29ZMLUBONXJ99STXMruLpY5aRceRk3PNdnkbf8HzJRRLwdLwSsaTC2py5cOu3UgCNdw8yohs5SN6Ll8A80BBG5kRj3ISk1RUijw86pZTloyaeOvQnTBgS0wUP0N0xjYyfbktil1JpEYnWbhCrrvK32iBBctaunVddyciWAAOdMzV7FhzkqBX5aBXytq8l8Pyjv3UASgwmo0D3fXpbYgL4v2hnTuCj6Z"

int main(){
	Blowfish_encrypt blowfish(PLAINTEXT);
	Triple_DES triple(PLAINTEXT);
	RC5_encrypt rc5(PLAINTEXT);
	IDEA_encrypt idea(PLAINTEXT);
	
	high_resolution_clock::time_point t1, t2;
	auto 	d_blow_en, d_blow_de, 
			d_trip_en, d_trip_de, 
			d_rc5_en, d_rc5_de,
			d_idea_en, d_idea_de;
	
	
	/***********Blowfish************\
	\*******************************/
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		blowfish.encrypt_string();
		t2 = high_resolution_clock::now();
		d_blow_en += d_blow_en_cast<microseconds>(t2-t1).count();
	}
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		blowfish.decrypt_string();
		t2 = high_resolution_clock::now();
		d_blow_de += d_blow_de_cast<microseconds>(t2-t1).count();
	}
	blowfish.Blowfish_about();
	
	
	/**********Triple-DES***********\
	\*******************************/
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		triple.encrypt_string();
		t2 = high_resolution_clock::now();
		d_trip_en += d_trip_en_cast<microseconds>(t2-t1).count();
	}
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		triple.decrypt_string();
		t2 = high_resolution_clock::now();
		d_trip_de += d_trip_de_cast<microseconds>(t2-t1).count();
	}
	triple.triple_about();
	
	
	/*************RC5***************\
	\*******************************/
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		rc5.encrypt_string();
		t2 = high_resolution_clock::now();
		d_trip_en += d_trip_en_cast<microseconds>(t2-t1).count();
	}
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		rc5.decrypt_string();
		t2 = high_resolution_clock::now();
		d_trip_de += d_trip_de_cast<microseconds>(t2-t1).count();
	}
	rc5.rc5_about();
	
	
	/*************IDEA**************\
	\*******************************/
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		idea.encrypt_string();
		t2 = high_resolution_clock::now();
		d_rc5_en += d_rc5_en_cast<microseconds>(t2-t1).count();
	}
	for(int i=0; i< 50; i++){
		t1 = high_resolution_clock::now();
		idea.decrypt_string();
		t2 = high_resolution_clock::now();
		d_rc5_de += d_rc5_de_cast<microseconds>(t2-t1).count();
	}
	idea.idea_about();
	
	/***********Averages************\
	\*******************************/
	cout << endl << "----------------Averages----------------" << endl;
	cout << "Blowfish:" << endl;
	cout << "	Average encrypt time: " << d_blow_en/50.0 << endl;
	cout << "	Average decrypt time: " << d_blow_de/50.0 << endl;
	
	cout << "Triple-DES:" << endl;
	cout << "	Average encrypt time: " << d_trip_en/50.0 << endl;
	cout << "	Average decrypt time: " << d_trip_de/50.0 << endl;
	
	cout << "RC5:" << endl;
	cout << "	Average encrypt time: " << d_rc5_en/50.0 << endl;
	cout << "	Average decrypt time: " << d_rc5_de/50.0 << endl;
	
	cout << "IDEA:" << endl;
	cout << "	Average encrypt time: " << d_idea_en/50.0 << endl;
	cout << "	Average decrypt time: " << d_idea_de/50.0 << endl;
	
	return 0;
}
