#include <string>
#include <vector>
using namespace std;
class Playfair{
	private:
		string key;//������ܾ���Ĺؼ���
		string DividePlaintext(string plaintext);//��������
		string DivideCiphertext(string ciphertext);//���������������
		vector<int> FindRowIdColId(char c, vector<vector<char>> keyMat);
	public:
		Playfair(string str);
		vector<vector<char>> GenerateKeyMat();//���ɼ��ܾ���
		string Encryption(string plaintext, vector<vector<char>> keyMat);//�����㷨
		string Decryption(string ciphertext, vector<vector<char>> keyMat);//�����㷨
		void Display(vector<vector<char>> keyMat);
		
};