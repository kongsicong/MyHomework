#include "Playfair.h"
#include <iostream>

Playfair::Playfair(string str){
	key = str;
}
vector<vector<char>> Playfair::GenerateKeyMat(){
	vector<char> keyVector;
	vector<vector<char>> result;
	keyVector.reserve(25);
	int i;
	for (i = 0; i < key.length() && i<25; i++){
		if (key[i] == 'j')key[i] = 'i';
		string sub = key.substr(0, i);
		if (sub.find(key[i]) == string::npos)keyVector.push_back(key[i]);
	}
	for (i = 97; i <= 122; i++){
		if (i == 106)continue;
		if (key.find((char)i) == string::npos)keyVector.push_back((char)i);
	}
	for (i = 0; i < 5; i++){
		vector<char> item;
		for (int j = 0; j < 5; j++){
			item.push_back(keyVector[i*5+j]);
		}
		result.push_back(item);
	}
	return result;
}
void Playfair::Display(vector<vector<char>> keyMat){
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			cout << keyMat[i][j] << " ";
		}
		cout << endl;
	}
}
string Playfair::DividePlaintext(string plaintext){
	string result="";
	for (int i = 0; i < plaintext.length(); i+=2){
		if (plaintext[i] == 'j')plaintext[i] == 'i';
		if (plaintext[i+1] == 'j')plaintext[i+1] == 'i';
		if (plaintext[i] != plaintext[i + 1]&&plaintext[i+1]!='\0'){
			result = result + plaintext[i] + plaintext[i + 1];
		}
		else if (plaintext[i] != plaintext[i + 1] && plaintext[i + 1] == '\0')result = result + plaintext[i] + 'x';
		else if (plaintext[i] == plaintext[i + 1]){
			result =result + plaintext[i] + 'x';
			i--;
		}
	}
	return result;
}
string Playfair::Encryption(string plaintext,vector<vector<char>> keyMat){
	string pre_text = DividePlaintext(plaintext);
	cout << pre_text << endl;
	string result = "";
	for (int i = 0; i < pre_text.length()-1; i+=2){
		int r1 = FindRowIdColId(pre_text[i], keyMat)[0]; 
		int c1 = FindRowIdColId(pre_text[i], keyMat)[1];
		int r2 = FindRowIdColId(pre_text[i+1], keyMat)[0]; 
		int c2 = FindRowIdColId(pre_text[i+1], keyMat)[1];
		if (r1==r2 && c1 != c2){
			result = result + keyMat[r1][(c1 + 1) % 5]  + keyMat[r1][(c2 + 1) % 5];
		}
		else if (c1 == c2 && r1 != r2){
			result = result + keyMat[(r1+1)%5][c1]  + keyMat[(r2+1)%5][c1];
		}
		else{
			result = result + keyMat[r1][c2] + keyMat[r2][c1];
		}
	}
	return result;
}
vector<int> Playfair::FindRowIdColId(char c, vector<vector<char>> keyMat){
	vector<int> result;
	result.reserve(2);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (keyMat[i][j] == c){
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
}
string Playfair::Decryption(string ciphertext, vector<vector<char>> keyMat){
	string result = "";
	for (int i = 0; i < ciphertext.length() - 1; i += 2){
		int r1 = FindRowIdColId(ciphertext[i], keyMat)[0];
		int c1 = FindRowIdColId(ciphertext[i], keyMat)[1];
		int r2 = FindRowIdColId(ciphertext[i + 1], keyMat)[0];
		int c2 = FindRowIdColId(ciphertext[i + 1], keyMat)[1];
		if (r1 == r2 && c1 != c2){
			result = result + keyMat[r1][(c1 +4) % 5] + keyMat[r1][(c2 +4) % 5];
		}
		else if (c1 == c2 && r1 != r2){
			result = result + keyMat[(r1 +4) % 5][c1] + keyMat[(r2 +4) % 5][c1];
		}
		else{
			result = result + keyMat[r1][c2] + keyMat[r2][c1];
		}
	}
	return result;
}
string Playfair::DivideCiphertext(string ciphertext){

}