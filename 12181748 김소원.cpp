#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> match(string p) { //match ����
	int plength = p.length(); //������ ����
	vector <int> pi(plength); //pi�� ����
	pi[0] = 0; //�迭 pi�ʱ�ȭ
	int j = 0; //������ ���� ����ġ�� ��Ÿ���� ���� j
	for (int i = 1; i < plength; i++) //i�� ����ũ�⸸ŭ �� ��
	{
		while (j > 0 && p[i] != p[j]) //j�� 0���� ũ�� p[i]�� p[j]�� ���� �ʴٸ� 
		{
			j = pi[j - 1]; //����ġ�� �Ͼ
		}
		if (p[i] == p[j]) //p[i]�� p[j]�� ���ٸ�
		{
			pi[i] = j + 1; //prefix�� ���� ����ġ��ŭ pi�� ����
			j++; // (���� ���ڿ� �� ���ڰ� ���� ��) j ����
		}
		else
			pi[i] = 0; //�ƴҰ�� pi[i]�� 0
	}
	return pi; //pi�� ��ȯ
}

vector <int> KMP(string t, string p) //KMP ����
{
	auto pi = match(p); //match�������� ���� pi�迭 ���޹���
	vector <int> result;
	int j = 0;
	int tlength = t.length(); //�ؽ�Ʈ�� ����
	int plength = p.length(); //������ ����(����)
	for (int i = 0; i < tlength; i++) //i�� �ؽ�Ʈ�� �� ���̱��� �� ��
	{
		//char holdChar = t[i]; //Ư������, ���� �����ϰ� ����
		while (j > 0 && t[i] != p[j])//t�� ��ü �ؽ�Ʈ, p�� ã������ ����
		{
			j = pi[j - 1]; //���ڿ��� �ٸ� ��� �״������� ��
		}
		if (t[i] == p[j]) //�ؽ�Ʈ�迭�� ���� �迭�� ������(�� ���ϴ� ���ڿ��� ���� ��)
		{
			if (j == plength - 1)//������ ���ڿ����� ���ٸ�
			{
				result.push_back(i - plength + 1);//��ġ�� ����
				j = pi[j]; //���� ���� ���ڿ� ���� ������ ��
			}
			else
				j++;//�ϳ��� ����

		}
	}
	return result; //����� ��ȯ
}

int main() {
	string input; //��� �ؽ�Ʈ�� ��
	string t, p; //t�� �ؽ�Ʈ p�� ����
	cout << "�ؽ�Ʈ: ";

	while (getline(cin, t)) { //���ڿ�(�ؽ�Ʈ)�� �����ٷ� �Ѿ �� �ְ� ���� while��
		if (t == "^end") //���� �ؽ�Ʈ�� ^end������
			break; //����

		input += " " + t; //input�� ��� �ٿ� �ִ� ���ڿ�(�ؽ�Ʈ)
	}

	cout << "����: ";

	getline(cin, p);//�д� ��

	auto matched = KMP(input, p); //�ؽ�Ʈ�� input, ������ p 
	cout << "�ؽ�Ʈ�� ���Ե� ���� ����: " << matched.size() << endl;
	cout << endl;
	for (auto index : matched)
		cout << "�ؽ�Ʈ�� ���Ե� ���� ��ġ: " << index << endl;
	cout << endl;

}


