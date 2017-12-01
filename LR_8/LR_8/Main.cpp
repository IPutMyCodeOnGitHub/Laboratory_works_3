#include"Intln.h"
#include<vector>
#include<set>
#include<cstdlib>
#include<ctime>


void vec_intln_rand(vector<Intln>& v, int n)
{
	time_t t1, t2;
	t1 = clock();
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		char* str = new char[2];
		str[0] = rand()%10 + '0';
		str[1] = '\0';
		Intln num(1, str);
		v.push_back(num);
	}
	t2 = clock();
	cout << "time of filling intln_vector: " << t2 - t1 << endl;
}

void vec_int_rand(vector<int>& v, int n)
{
	time_t t1, t2;
	t1 = clock();
	v.reserve(n);
	for (int i = 0; i < n; i++)
		v.push_back(rand()%10);
	t2 = clock();
	cout << "time of filling int_vector: " << t2 - t1 << endl;
}

void mset_intln_rand(multiset<Intln>& ms, int n)
{
	time_t t1, t2;
	t1 = clock();
	for (int i = 0; i < n; i++)
	{
		char* str = new char[2];
		str[0] = rand() % 10 + '0';
		str[1] = '\0';
		Intln num(1, str);
		ms.insert(num);
	}
	t2 = clock();
	cout << "time of filling intln_multiset: " << t2 - t1 << endl;
}

void mset_int_rand(multiset<int> ms, int n)
{
	time_t t1, t2;
	t1 = clock();
	for (int i = 0; i < n; i++)
		ms.insert(rand() % 10);
	t2 = clock();
	cout << "time of filling int_multiset: " << t2 - t1 << endl;
}

template <class T>
inline void vec_show(vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
}


template <class T>
inline void ms_show(multiset<T>& ms)
{
	for (T iterator = ms.begin; iterator < ms.end(); i=ms. )
		cout << v[i] << ' ';
	cout << endl;
}

int main()
{
	srand(time(NULL));
	time_t t1, t2;
	vector<int> int_vec;
	vector<Intln> intln_vec;
	cout << "Size of vectors: ";
	int n;
	cin >> n;

	t1 = clock();
	vec_intln_rand(intln_vec, n);
	t2 = clock();
	cout << "infil of vector by intln: " << t2 - t1 << endl;

	t1 = clock();
	vec_int_rand(int_vec, n);
	t2 = clock();
	cout << "infil of vector by int: " << t2 - t1 <<endl;
	//cout << "Vector of int: " << endl;
	//vec_show(int_vec);
	//cout << "Vector of Intln: " << endl;
	//vec_show(intln_vec);

	t1 = clock();
	int_vec.clear();
	t2 = clock();
	cout << "deliting of int_vector: " << t2 - t1 << endl;

	t1 = clock();
	intln_vec.clear();
	t2 = clock();
	cout << "deleting of intln_vector: " <<  t2 - t1 << endl;

	multiset<Intln> intln_mset;
	multiset<int> int_mset;
	cout << endl << "Size of multiset: ";
	cin >> n;
	
	t1 = clock();
	mset_intln_rand(intln_mset, n);
	t2 = clock();
	cout << "infil of multiset by intln: " << t2 - t1 << endl;

	t1 = clock();
	mset_int_rand(int_mset, n);
	t2 = clock();
	cout << "infil of multiset by int: " << t2 - t1 << endl;

	t1 = clock();
	Intln i(1, "0");
	for ( ; i < n; i++)
	intln_mset.find(i);
	t2 = clock();
	cout << "finding of multiset of intln: " << t2 - t1 << endl;

	t1 = clock();
	for (int i = 0; i < n; i++)
		int_mset.find(i);
	t2 = clock();
	cout << "finding of multiset of int: " << t2 - t1 << endl;

	t1 = clock();
	intln_mset.clear();
	t2 = clock();
	cout << "deleting of multisetof intln: " << t2 - t1 << endl;

	t1 = clock();
	int_mset.clear();
	t2 = clock();
	cout << "deleting of ultiset of int: " << t2 - t1 << endl;

	system("pause");
	return 0;
}