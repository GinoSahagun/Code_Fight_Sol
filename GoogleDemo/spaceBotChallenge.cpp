

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>


using namespace std;

/*Space Bot Challenges*/
/*Try to find out if the system name correspondly increase in step numbers by each same system name*/
bool launchSequenceChecker(std::vector<std::string> systemNames, std::vector<int> stepNumbers) {

	std::map<std::string, int> map;
	int step;
	for (int i = 0; i < systemNames.size(); i++)
	{
		if (map.find(systemNames[i]) == map.end())
		{
			map[systemNames[i]] = stepNumbers[i];
		}
		else
		{
			if (map[systemNames[i]] >= stepNumbers[i])
				return false;
			else
				map[systemNames[i]] = stepNumbers[i];
		}
	}

	return true;

}

//Find all of the packets a transfered message if possible
std::string packetDescrambler(std::vector<int> seq, std::vector<char> fragmentData, int n) {

	int percent = 0;
	std::string temp = "";
	std::map<char, int> map;
	std::map<int, char> sequence;
	int count = INT16_MAX;
	//Plaecs Treshold Sequence items into second Map
	for (int i = 0; i < seq.size(); i++)
	{
		if (i != 0 && seq[i] != seq[i - 1])
			map.clear();
		map[fragmentData[i]] = 1 + map[fragmentData[i]];
		if ((double)map[fragmentData[i]] / n > 0.50)
			sequence[seq[i]] = fragmentData[i];

	}
	//Check for gaps and get beginning sequence number
	for (int i = 0; i < seq.size(); i++)
	{
		if (sequence.find(seq[i]) == sequence.end())
			return "";
		if (count >= seq[i])
			count = seq[i];
	}

	//Check for Gaps again and build string
	for (auto kv : sequence)
	{
		if (count != kv.first)
			return "";
		count++;
		temp += kv.second;

	}
	//Check if # is found anywhere else other than last element
	for (int i = 0; i < temp.size() - 1; i++)
	{
		if (temp[i] == '#')
			return "";
	}

	//check if # is last fragment
	if (temp[temp.size() - 1] != '#')
		return "";

	return temp;
}

//Space Bot Challenge Replicate an assembly styled code
int branch(std::vector<string> s, std::map<string, uint32_t> &map)
{
	if (s[0] == "MOV")
	{
		if (s[1].find("R") != std::string::npos && s[2].find("R") != std::string::npos)
		{
			//TODO CHECK FOR REGISTERS EXISTING
			map[s[2]] = map[s[1]];
		}
		else {
			map[s[2]] = stol(s[1]);
		}
	}
	if (s[0] == "ADD")
	{
		map[s[1]] = (map[s[1]] + map[s[2]]);
	}
	if (s[0] == "DEC")
	{
		if (map[s[1]] == 0)
		{
			map[s[1]] = 4294967295;
		}
		else
			map[s[1]]--;
	}
	if (s[0] == "INC")
	{
		if (map[s[1]] == 4294967295)
		{
			map[s[1]] = 0;
		}
		else
			map[s[1]]++;
	}
	if (s[0] == "INV")
	{
		map[s[1]] = ~map[s[1]];
	}
	if (s[0] == "JMP")
	{
		return stoul(s[1]);
	}
	if (s[0] == "JZ")
	{

		if (map["R00"] == 0)
			return stoul(s[1]);

	}

	return -1;
}

std::vector<string> partEmulator(std::string s)
{
	string temp = "";
	std::vector<string> parts;
	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) == ' ' || s.at(i) == ',')
		{
			parts.push_back(temp);
			temp = "";

		}
		else {
			temp.push_back(s.at(i));
		}
	}
	if (temp != "")
		parts.push_back(temp);
	return parts;
}
//std::string cpuEmulator(std::vector<std::string> subroutine) {
//	std::map<string, uint32_t> map;
//	int jumped;
//	map["R00"] = 0;
//	for (int i = 0; i < subroutine.size(); i++)
//	{
//		std::vector<string> temp = partEmulator(subroutine[i]);
//
//		jumped = branch(temp, map);
//
//		if (jumped > -1)
//			i = jumped - 2;
//
//	}
//
//	if (map.find("R42") != map.end())
//		return NumberToString(map["R42"]);
//
//	return "0";
//}