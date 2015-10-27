#include <stdlib.h>
#include "Playfair.h"
#include<iostream>
int main(){
	string key = "monarchy";
	Playfair playfair(key);
	cout << "key:" << key << endl;
	vector<vector<char>> keyMat = playfair.GenerateKeyMat();
	playfair.Display(keyMat);
	string plaintext = "balloon";
	cout << "plaintext:" << plaintext << endl;
	string ciphertext = playfair.Encryption(plaintext, keyMat);
	cout << "ciphertext:"<<ciphertext << endl;
	string decryption = playfair.Decryption(ciphertext, keyMat);
	cout << "the final result after processing decryption:"<<decryption << endl;
	system("pause");
	return 0;
}