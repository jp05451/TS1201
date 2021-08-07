#include"MemorySimulator.h"

int main()
{
				/*int mask = 255;
				int test = -100;
				bitset<32> x(test);
				cout << x << endl;
				int recieve = 0;
				if (test < 0)
								recieve=~recieve;
				recieve = mask | test;
				
				return 0;*/

				Memory m;
				int length;
				int times;
				string command;
				cin >> length;
				cin>>times;

				//cout << length << " " << times << ":";

				m.setData(length);
				int count = 0;
				while (count<times)
				{
								//getline(cin, command);
								//cout << command << " ";
								cin >> command;
								if (command == "Get")
								{
												m.get();
								}
								else if (command == "Set")
								{
												m.set();
								}
								count++;
				}
				//m.output();
}
