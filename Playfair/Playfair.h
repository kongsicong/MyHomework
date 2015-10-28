#include <string>
#include <vector>
using namespace std;
class Playfair{
	private:
		string key;//构造加密矩阵的关键词
		string DividePlaintext(string plaintext);//整理明文
		string DivideCiphertext(string ciphertext);//处理解密所得明文
		vector<int> FindRowIdColId(char c, vector<vector<char>> keyMat);
	public:
		Playfair(string str);
		vector<vector<char>> GenerateKeyMat();//生成加密矩阵
		string Encryption(string plaintext, vector<vector<char>> keyMat);//加密算法
		string Decryption(string ciphertext, vector<vector<char>> keyMat);//解密算法
		void Display(vector<vector<char>> keyMat);
		
};