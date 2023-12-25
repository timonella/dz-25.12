#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;
class rsa {
public:

	long p, q, n, m;
	int max;

	int crete_n() {
		n = q * p;
		return n;
	}
	int crete_m() {
		m = (p - 1) * (q - 1);
		return m;
	}


	void generate() {

		srand(time(NULL));
		p = rand() % 100;
		q = rand() % 100;
		
		for (int i{}; i < 100; i++) {
			int bobr = p;
			chek(bobr);
		}		
		for (int i{}; i < 100; i++) {
			int bobr = q;
			chek(bobr);
		}
		if (p < q) {
			max = p;
		}
		else
			max = q;
		crete_m();
		crete_n();

	}
	bool chek(int bobr) {
		for (int i{2}; i < max; i++) {
			if (bobr % i == 0 and bobr!=i) {
				return false;
			}
		}			
		return true;
		
	}
	int find_e(int m) {
		long e = 3;
		for (int i{ 1 }; i < m; i++) {
			if (m % i != 0 || e % i != 0)
				continue;
			e++;
			i = 1;
		}
		return e;
	}
	int find_d(int E, int m) {
		srand(time(NULL));
		long d = rand() % 100;
		while (true)
		{
			if (d * E % m == 1)
				break;
			else
				d++;
		}
		return d;
	}
	
	int E;
string chifr() {
	generate();
	int e = find_e(m);
	E = e;
	string textic="bobr";
	string chifro_bobr = "";
	int temp;
	for (auto c : textic) {
		temp = pow(c, e); 
		temp %= n;
		chifro_bobr += temp;
	}
	textic = char(temp);
	cout << chifro_bobr << endl;
	return chifro_bobr;
}
	void raschifrovka() {
		generate();
		string textic = chifr();
		int e = find_d(E, m);

	
		string raschifro_bobr;
		int temp;
		for (auto c : textic) {
			temp = pow(c, e);
			temp %= n;
			raschifro_bobr += char(temp);
		}
		textic = char(temp);
		cout << raschifro_bobr <<endl;
	}
};
int main()
{
	rsa a;
	a.raschifrovka();
}