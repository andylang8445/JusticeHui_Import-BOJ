#include <iostream>
#include <string>
using namespace std;

int main(){
	string str; cin >> str;
	int idx = 0;
	string chk = "";
	for (int i = 0; i < str.length(); i++){
		chk += str[i];
		if (chk.length() >= 4){
			char a, b, c, d;
			d = chk.back(); chk.pop_back();
			c = chk.back(); chk.pop_back();
			b = chk.back(); chk.pop_back();
			a = chk.back(); chk.pop_back();
			string now = ""; now += a; now += b; now += c; now += d;
			if (now != "PPAP"){
				chk += now;
			}
			else{
				chk += "P";
			}
		}

		else if (chk == "PPAP"){
			cout << "PPAP"; return 0;
		}
		//cout << "tmp :: " << chk << "\n";
	}
	if (chk == "P" || chk == "PPAP"){
		cout << "PPAP"; return 0;
	}
	cout << "NP";
}
