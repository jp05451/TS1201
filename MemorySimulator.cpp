#include"MemorySimulator.h"
void Memory::setData(int size)
{
				data.resize(size,0);
}

void Memory::set()
{
				int pos;//position of data
				string type;//type of data

				/*getline(cin, type);
				cout << type << "\t";
				return ;*/

				cin >> pos >> type;
				if (type == "String")
								string_store(pos);
				else if (type == "char")
								char_store(pos);
				else if (type == "int")
								integer_store(pos);
				else if (type == "short")
								short_store(pos);
}

void Memory::get()
{
				int pos;//position of data
				string type;//type of data
				
			/*	getline(cin, type);
				cout << type << "\t";
				return;*/

				cin >> pos >> type;
				if (type == "String")
								string_read(pos);
				else if (type == "char")
								char_read(pos);
				else if (type == "int")
								integer_read(pos);
				else if (type == "short")
								short_read(pos);
}

void Memory::integer_store(int pos)
{
				long long int d;
				//int d;
				int count = 0;
				int mask = 255;
				cin >> d;

				if (4+ pos > data.size())
				{
								cout << "Violation Access." << endl;
				}
				while (count + pos < data.size()&&count<4&&d !=0)
				{
								data[count + pos] = d & mask;
								d >>=8;
								count++;
				}
}

void Memory::short_store(int pos)
{
				long long int s;
				//short s;
				int mask = 255;
				int count = 0;
				cin >> s;

				if (2 + pos > data.size())
				{
								cout << "Violation Access." << endl;
				}
				while (count + pos < data.size() && count < 2 && s != 0)
				{
								data[count + pos] = s & mask;
								s >>= 8;
								count++;
				}
}

void Memory::char_store(int pos)
{
				int c;
				cin >> c;
				if (pos < data.size())
				{
								data[pos] = c;
				}
				else
								cout << "Violation Access." << endl;
}

void Memory::string_store(int pos)
{
				string str;
				int count;
				count = 0;
				getchar();
				getline(cin, str);
				if (str.length() + pos > data.size())
				{
								cout << "Violation Access."<<endl;
				}
				// count>記憶體長度跳出&&str結束
				while (count + pos< data.size()&&count<str.length())
				{
								data[count+pos] = str[count];
								count++;
				}
				if (count + pos < data.size())
								data[count + pos] = '\0';

}

void Memory::integer_read(int pos)
{
				int temp=0;
				int mask = 255;
				if (pos + 4 > data.size())
				{
								cout << "Violation Access." << endl;
								return;
				}
				for (int count = 3; count>=0 ;count--)
				{
								
								if (pos + count < data.size())
								{
												temp <<= 8;
												temp += data[count + pos] & mask;
								}
				}
				cout << temp << endl;
}

void Memory::short_read(int pos)
{
				unsigned short temp = 0;
				int mask = 255;
				if (pos + 2 > data.size())
				{
								cout << "Violation Access." << endl;
								return;
				}
				for (int count = 1; count >= 0; count--)
				{
								if (count + pos < data.size())
								{
												temp <<= 8;
												temp += data[pos + count] & mask;
								}
				}
				cout << temp << endl;
}

void Memory::char_read(int pos)
{
				if (pos >= data.size())
				{
								cout << "Violation Access." << endl;
								return;
				}
//				cout << (int)data[pos] << endl;
				cout << data[pos]<<endl;
}

void Memory::string_read(int pos)
{
				int count = 0;
				if (pos >= data.size())
				{
								cout << "Violation Access." << endl;
								return;
				}
				while (count + pos < data.size())
				{
								if (data[count+pos] == '\0')
												break;
								cout << data[pos + count];
								count++;
				}
				cout << endl;
}

void Memory::output()
{
				
				/*for (int i = 0; i < data.size(); i++)
				{
								bitset<8> x((int)data[i]);
								cout << x << endl;
				}*/
				cout << hex;
				for (int i = 0; i < data.size(); i++)
				{
								

								cout <<(int) data[i]/16;
								cout << (int)data[i] % 16<<" ";
								if (i % 5 ==4)
												cout << endl;
				}
				cout << endl;
}