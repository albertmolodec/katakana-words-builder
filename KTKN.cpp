#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <clocale>

using namespace std;

string GetAlphabet() {
	return "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
}

vector<string> GetSochet(string alphabet) {
	string temp;
	vector<string> v2;
	for (int i = 0; i<33; i++) {
		for (int j = 0; j<33; j++) {
			for (int k = 0; k<33; k++) {
				temp = alphabet[i];
				temp = temp + alphabet[j];
				v2.push_back(temp + alphabet[k]);

			}
		}
	}
	return v2;
}

int main()
{
	setlocale(LC_ALL, "ru_RU.utf8");
	vector<string> v;
	string temp;

	ifstream fi("words.txt");
	ofstream fo("output.txt", ios::app);
	fo << "Start.";

	while (!fi.eof()) {
		getline(fi, temp);
		v.push_back(temp);
	}
	fi.close();


	////////////////////////////
	string alphabet = GetAlphabet();
	vector<string> sochet = GetSochet(alphabet);
	////////////////////////////

	vector<string>::iterator it1, it2;
	int count = 0;
	vector<string> ResultWord;

	for (it1 = sochet.begin(); it1 != sochet.end(); it1++)
	{
		count = 0;
		ResultWord.clear();
		for (it2 = v.begin(); it2 != v.end(); it2++) {
			if ((*it2).find(*it1) != string::npos) {
				cout<<*it1<<") "<<*it2<<"\n";
				count++;
				ResultWord.push_back(*it2);
			}
		}

		if (count>2) {
			fo << "================\nСочетание: " << *it1 << "\n================\n";
			for (vector<string>::iterator w = ResultWord.begin(); w != ResultWord.end(); w++) {
				fo << *w << "\n";

			} fo << "================\n\n\n";
		}


	}
	fo.close();
	return 0;
}