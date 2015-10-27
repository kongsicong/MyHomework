#include <stdlib.h>
#include "Playfair.h"
#include<iostream>
int main(){
	Playfair playfair("cipher");
	vector<vector<char>> keyMat = playfair.GenerateKeyMat();
	playfair.Display(keyMat);
	string plaintext = "balloon";
	string ciphertext = playfair.Encryption(plaintext, keyMat);
	cout << ciphertext << endl;
	string decription = playfair.Decryption(ciphertext, keyMat);
	cout << decription << endl;
	system("pause");
	return 0;
}