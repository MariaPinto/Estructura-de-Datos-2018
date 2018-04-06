#include <vector>
#include <map>
#include <cstdio>
#include "linked_list.h"
#include <iostream>
//#define linked_list std::vector	// use your implementation of linked_list
//#define insert_back push_back	// use your implementation of linked_list

#define N 19	// size of hash table
using namespace std;
template <class K, class V>
class hash_table // hash table by chaining
{
	typedef linked_list<K, V> chain;	
	typedef int (*hash_f) (const K &);	// hash function
	
	private:
		chain * table;
		int size;
		hash_f f;	// hash function
	
	public:
		hash_table(const int & _size, hash_f _f): size(_size), f(_f)
		{
			table = new chain[size];
		}
		
		~hash_table()
		{
			delete [] table;
		}
	
		void insert(const K & key, const V & value)
		{
			int i = f(key);
			table[i].insert_back(key, value);
		}
		
		void remove(const K &key)
		{
			for(int i=0;i<size;i++)
				table[i].remove(key);
		}

		bool find (const K&key)
		{
			for(int i=0;i<size;i++)
				table[i].find(key);
		}
		void print()
		{
			for(int i = 0; i < size; i++)
			{
				printf("[%d] ", i);
				table[i].print();
				
				printf("\n");
			}
		}
};

int hash_int(const int & k)
{
	return k % N;
}

int main()
{
	hash_table<int, char> hash(N, hash_int);
	hash.insert(2, 'a');
	hash.insert(21, 'd');
	hash.insert(43, 'd');
	hash.insert(21, 'c');
	hash.insert(32, 'b');
	hash.print();
	hash.remove(2);
//	hash.find(2);
	return 0;
}
