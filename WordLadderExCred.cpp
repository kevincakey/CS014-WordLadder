#include "WordLadderExCred.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

WordLadder::WordLadder(const string& name)
{
	ifstream fin;
	fin.open(name);

	if (!fin.is_open())
		{
        cout << "Error opening " << name << endl;
        return;
	}

	if (fin.fail())
	{
		cout << "Error opening " << name << endl;
		return;
	}

	string input = "";
	while (fin >> input)
	{
		dict.push_back(input);
	}

	fin.close();
}

void WordLadder::outputLadder(const string& start, const string& end, const string& outputFile)
{
	ofstream fout;
	fout.open(outputFile);
	if (!fout.is_open())
	{
		cout << "Error opening " << outputFile << endl;
		return;
	}

	if (fout.fail())
	{
		cout << "Error opening " << outputFile << endl;
		return;
	}

	list<string>::iterator i;
	bool startExists = false;
	bool endExists = false;
	for (i = dict.begin(); i != dict.end(); i++)
	{
		if (start == *i)
		{
			startExists = true;
		}
		if(end == *i)
		{
			endExists = true;
		}
	}
	if(!startExists || !endExists){

		cout << "Words don't exist" << endl;
		return;
	}

	stack<string> l;
	l.push(start);

	queue<stack<string>> qos;
	qos.push(l);

		if (start == end) 
		{
				
			fout << start;
			return;
		}

	while (!qos.empty()) 
	{
		string wordOnTop = qos.front().top();
		for (i = dict.begin(); i != dict.end(); i++)//list<string>::iterator i = dict.begin();
		{
			if (shift(qos.front().top(),*i))
			{
				stack<string> n = qos.front();
				n.push(*i);
				if (*i == end)
				{
					stack<string> done;
					while (!n.empty())
					{
						done.push(n.top());
						n.pop();
					}

					while(!done.empty()){
						fout << done.top() << ' ';
						done.pop();
					}
					fout.close();
					cout << "comparisons: " << comparisons << endl;
					return; //put into outputFile
				}
				else
				{
					qos.push(n);
					dict.erase(i);
					i--;
				}
			}
		}
		qos.pop();
	}
	fout << "No Word Ladder Found." << endl;
	fout.close();
	return;
}

bool WordLadder::shift(const string& curr, const string& next){

	//cout << "curr: " << curr << "          next: " << next << endl;

	int track = 0;

	for (unsigned int i = 0; i < next.size(); ++i) {
		if(next.at(i) != curr.at(i)){
			track++;
			comparisons++;
		}
	}

	if(track >1){
		return false;
	}
	return true;
}

