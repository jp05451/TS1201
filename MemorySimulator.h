#include<iostream>
#include<string>
#include<vector>
#include <bitset>

#pragma once
using namespace std;

class Memory
{
public:
				void setData(int size);
				void set();
				void get();
				void integer_store(int pos);
				void short_store(int pos);
				void string_store(int pos);
				void char_store(int pos);

				void integer_read(int pos);
				void short_read(int pos);
				void string_read(int pos);
				void char_read(int pos);
				void output();
private:
				vector<unsigned char> data;
};
