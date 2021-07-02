#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	string iname, oname;
	if (argc = 1) {
		cin >> iname;
		cin >> oname;
	}
	else {
		iname = argv[1];
		oname = argv[1];
	}

	ifstream fin(iname, ifstream::in);
	ofstream fout(oname, ofstream::out | ofstream::trunc);

	if (!fin.is_open() or !fout.is_open()) {
		cout << "ERROR: files can not be opened\n";
	}
	else {
		cout << "Files was successfully opened\n";

		int m, n;
		fin >> m >> n;
		int i = 0, j = 0;
		int** a = new int*[n];
		for (i = 0; i < n; i++) {
			a[i] = new int[m];
		}

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fin >> a[j][i];
			}
		}
		fin.close();

		int* sum = new int[n];
		for (i = 0; i < n; i++) {
			sum[i] = 0;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				sum[i] = sum[i] + a[i][j];
			}
		}

		int min, k, i1, j1;
		for (i = 0; i < n - 1; i++) {
			k = i;
			for (j = i + 1; j < n; j++) {
				if (sum[j] < sum[k]) {
					k = j;
				}
			}
			swap(sum[i], sum[k]);
			for (j1 = 0; j1 < m; j1++) {
				swap(a[i][j1], a[k][j1]);
			}
		}

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				fout << a[j][i] << " ";
			}
			fout << endl;
		}
		fout.close();
		delete[]a;
		delete[]sum;
	}
}