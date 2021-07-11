#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> match(string p) { //match 벡터
	int plength = p.length(); //패턴의 길이
	vector <int> pi(plength); //pi의 길이
	pi[0] = 0; //배열 pi초기화
	int j = 0; //패턴의 현재 비교위치를 나타내는 변수 j
	for (int i = 1; i < plength; i++) //i가 패턴크기만큼 돌 때
	{
		while (j > 0 && p[i] != p[j]) //j가 0보다 크고 p[i]가 p[j]랑 같지 않다면 
		{
			j = pi[j - 1]; //불일치가 일어남
		}
		if (p[i] == p[j]) //p[i]가 p[j]랑 같다면
		{
			pi[i] = j + 1; //prefix가 같은 가중치만큼 pi를 정함
			j++; // (현재 문자와 전 문자가 같을 때) j 증가
		}
		else
			pi[i] = 0; //아닐경우 pi[i]는 0
	}
	return pi; //pi값 반환
}

vector <int> KMP(string t, string p) //KMP 벡터
{
	auto pi = match(p); //match과정에서 만든 pi배열 전달받음
	vector <int> result;
	int j = 0;
	int tlength = t.length(); //텍스트의 길이
	int plength = p.length(); //패턴의 길이(갯수)
	for (int i = 0; i < tlength; i++) //i가 텍스트의 총 길이까지 돌 때
	{
		//char holdChar = t[i]; //특수문자, 숫자 가능하게 만듦
		while (j > 0 && t[i] != p[j])//t는 전체 텍스트, p는 찾으려는 패턴
		{
			j = pi[j - 1]; //문자열이 다를 경우 그다음부터 비교
		}
		if (t[i] == p[j]) //텍스트배열과 패턴 배열이 같을때(즉 비교하는 문자열이 같을 때)
		{
			if (j == plength - 1)//마지막 문자열까지 같다면
			{
				result.push_back(i - plength + 1);//위치를 저장
				j = pi[j]; //맞지 않은 문자열 다음 열부터 비교
			}
			else
				j++;//하나씩 증가

		}
	}
	return result; //결과값 반환
}

int main() {
	string input; //모든 텍스트의 값
	string t, p; //t는 텍스트 p는 패턴
	cout << "텍스트: ";

	while (getline(cin, t)) { //문자열(텍스트)이 다음줄로 넘어갈 수 있게 만든 while문
		if (t == "^end") //만약 텍스트가 ^end나오면
			break; //종료

		input += " " + t; //input은 모든 줄에 있는 문자열(텍스트)
	}

	cout << "패턴: ";

	getline(cin, p);//패던 값

	auto matched = KMP(input, p); //텍스트는 input, 패턴은 p 
	cout << "텍스트에 포함된 패턴 갯수: " << matched.size() << endl;
	cout << endl;
	for (auto index : matched)
		cout << "텍스트에 포함된 패턴 위치: " << index << endl;
	cout << endl;

}


