/*****Please include following header files*****/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
/***********************************************/

/*****Please use following namespaces*****/
using namespace std;
/*****************************************/

const int MaxStates = 6 * 50 + 10;
const int MaxChars = 26;

int Out[MaxStates];
int FF[MaxStates];
int GF[MaxStates][MaxChars];

int BuildMatchingMachine(const vector<string> &words, char lowestChar = 'a', char highestChar = 'z')
{
	memset(Out, 0, sizeof Out);
	memset(FF, -1, sizeof FF);
	memset(GF, -1, sizeof GF);

	int states = 1;

	for (int i = 0; i < words.size(); ++i)
	{
		const string &keyword = words[i];
		int currentState = 0;

		for (int j = 0; j < keyword.size(); ++j)
		{
			int c = keyword[j] - lowestChar;

			if (GF[currentState][c] == -1)
			{
				GF[currentState][c] = states++;
			}

			currentState = GF[currentState][c];
		}

		Out[currentState] |= (1 << i);
	}

	for (int c = 0; c < MaxChars; ++c)
	{
		if (GF[0][c] == -1)
		{
			GF[0][c] = 0;
		}
	}

	queue<int> q;
	for (int c = 0; c <= highestChar - lowestChar; ++c)
	{
		if (GF[0][c] != -1 && GF[0][c] != 0)
		{
			FF[GF[0][c]] = 0;
			q.push(GF[0][c]);
		}
	}

	while (q.size())
	{
		int state = q.front();
		q.pop();

		for (int c = 0; c <= highestChar - lowestChar; ++c)
		{
			if (GF[state][c] != -1)
			{
				int failure = FF[state];

				while (GF[failure][c] == -1)
				{
					failure = FF[failure];
				}

				failure = GF[failure][c];
				FF[GF[state][c]] = failure;
				Out[GF[state][c]] |= Out[failure];
				q.push(GF[state][c]);
			}
		}
	}

	return states;
}

int FindNextState(int currentState, char nextInput, char lowestChar = 'a')
{
	int answer = currentState;
	int c = nextInput - lowestChar;

	while (GF[answer][c] == -1)
	{
		answer = FF[answer];
	}

	return GF[answer][c];
}

vector<int> FindAllStates(string text, vector<string> keywords, char lowestChar = 'a', char highestChar = 'z') {
	BuildMatchingMachine(keywords, lowestChar, highestChar);

	int currentState = 0;
	vector<int> retVal;

	for (int i = 0; i < text.size(); ++i)
	{
		currentState = FindNextState(currentState, text[i], lowestChar);

		if (Out[currentState] == 0)
			continue;

		for (int j = 0; j < keywords.size(); ++j)
		{
			if (Out[currentState] & (1 << j))
			{
				retVal.insert(retVal.begin(), i - keywords[j].size() + 1);
			}
		}
	}

	return retVal;
}