//
//#include <iostream>
//#include <string.h>
//#include <sstream>
//#include <vector>
//#include <set>
//#include <stack>
//#include <queue>
//#include <map>
//#include <unordered_map>
//using namespace std;
//
////std::vector<int> tasksTypes(std::vector<int> deadlines, int day) {
////
////	int upcoming = day + 1;
////	int later = day + 7;
////
////	std::vector<int> labels(3, 0);
////	for (int i = 0; i < deadlines.size(); i++)
////	{
////		if (deadlines[i] > later)
////		{
////			labels[2] += 1;
////		}
////		else if (upcoming <= deadlines[i] && deadlines[i] <= later)
////		{
////			labels[1] += 1;
////		}
////		else
////		{
////			labels[0] += 1;
////		}
////	}
////
////	return labels;
////
////}
////std::string smartAssigning(std::vector<std::string> names,
////	std::vector<bool> statuses,
////	std::vector<int> projects,
////	std::vector<int> tasks)
////{
////	struct Worker
////	{
////		Worker(std::string nm, int tasks, int projects)
////			: name(nm), workload(tasks, projects)
////		{}
////		std::string name;
////		std::pair<int, int> workload; // (tasks, projects)
////									  // As defined in the description.
////		bool operator<(const Worker& other) const { return workload < other.workload; }
////	};
////
////	// Gather the people that are available.
////	std::vector<Worker> staff;
////	for (int i = 0; i < names.size(); ++i)
////	{
////		// Ignore people on vacation.
////		if (!statuses[i])
////		{
////			staff.emplace_back(names[i], tasks[i], projects[i]);
////		}
////	}
////	// Sort by availability
////	std::qsort(staff.begin(), staff.end());
////	// And we're done.
////	return staff[0].name;
////}
//
///* INCOMPLETE */
//struct date {
//	date(int d, int m, int y) : day(d), month(d), year(y) { }
//	int day;
//	int month;
//	int year;
//
//
//};
//
//std::vector<string> split(std::string firstDate)
//{
//	int day;
//	int month;
//	int year;
//	std::vector<string> p;
//	string t = "";
//	for (int i = 0; i < firstDate.size(); i++)
//	{
//		if (firstDate.at(i) <= '9' && firstDate.at(i) >= '0')
//		{
//			t += firstDate.at(i);
//		}
//		else {
//			p.push_back(t);
//			t = "";
//		}
//	}
//	if (t != "")
//	{
//		p.push_back(t);
//		t = "";
//	}
//	day = atoi(p[0].c_str());
//	month = atoi(p[1].c_str());
//	year = atoi(p[2].c_str());
//
//	return p;
//}
//const std::vector<string> dayOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
//std::vector<int> monthLengths(date p)
//{
//	int year = p.year;
//	int month = p.month;
//	int day = p.day;
//
//	std::vector<int> lengths = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (year % 4 == 0 && !(year % 100 == 0) || year % 400 == 0)
//	{
//		lengths = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	}
//
//	return lengths;
//
//
//}
//
//std::string createDate(int year, int month, int day)
//{
//	string d = "";
//	string m = "";
//	string y = "";
//	string t;
//	//padding needed
//	if (day < 10)
//	{
//		d = "0";
//		d += NumberToString(day);
//		d += "/";
//	}
//	else
//	{
//		d += NumberToString(day);
//		d += "/";
//	}
//	if (month < 10)
//	{
//		m = "0";
//		m += NumberToString(month);
//		m += "/";
//	}
//	else {
//		m += NumberToString(month);
//		m += "/";
//	}
//	y = NumberToString(year);
//	t = d + m + y;
//
//	return t;
//
//}
//bool daysContainsIdx(std::vector<string> days, string idx) {
//	for (string day : days)
//		if (idx == day)
//			return true;
//	return false;
//}
//std::vector<std::string> recurringTask(std::string firstDate, int k, std::vector<std::string> daysOfTheWeek, int n) {
//
//	std::vector<string> datePart = split(firstDate);
//	date p(atoi(datePart[0].c_str()), atoi(datePart[1].c_str()), atoi(datePart[2].c_str()));
//	string create;
//	std::vector<int> monthLen = monthLengths(p);
//	std::vector<string> dates;
//	std::queue<date> nextDate;
//	int period = k * 7;
//	while (p.year >= 0 && n != dates.size())
//	{
//		for (int i = p.month; i <= 12; i++)
//		{
//			for (int j = 1; j <= monthLen[i]; j++)
//			{
//				int check = (j - 1) % 7;
//				if (daysContainsIdx(daysOfTheWeek, dayOfWeek[check]))
//				{
//					if (nextDate.size() < daysOfTheWeek.size())
//					{
//						create = createDate(p.year, i, check + 1);
//						dates.push_back(create);
//						int temp = i;
//						std::vector<int> temLen = monthLen;
//						date t = p;
//						while (period > temLen[temp])
//						{
//							period = period - temLen[temp];
//							temp++;
//							if (temp > 12)
//							{
//								t.year++;
//								temLen = monthLengths(t);
//								temp = 1;
//							}
//						}
//						t.month = temp;
//						t.day = period + j;
//						nextDate.push(t);
//					}
//					else
//					{
//						date temporal = nextDate.front();
//						if (j == temporal.day && i == temporal.month && p.year == temporal.year)
//						{
//							create = createDate(p.year, i, check + 1);
//							dates.push_back(create);
//							int temp = i;
//							std::vector<int> temLen = monthLen;
//							date t = p;
//							while (period > temLen[temp])
//							{
//								period = period - temLen[temp];
//								temp++;
//								if (temp > 12)
//								{
//									t.year++;
//									temLen = monthLengths(t);
//									temp = 1;
//								}
//							}
//							t.month = temp;
//							t.day = period + j;
//							nextDate.push(t);
//						}
//					}
//				}
//
//				if (n == dates.size())
//				{
//					break;
//				}
//			}
//			if (n == dates.size())
//			{
//				break;
//			}
//		}
//
//		p.year++;
//		monthLen = monthLengths(p);
//	}
//
//	return dates;
//}
