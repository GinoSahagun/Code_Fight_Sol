
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
using namespace std;
double min(double a, double b) {
	return a < b ? a : b;
}

double max(double a, double b) {
	return a > b ? a : b;
}

///**
//* Check wether there is road between them.
//* @return true if there is road(s) between a and b.
//*/
bool isInBetween(double a, double b) {
	if (a < 0.0 && b > 0.0) return true;
	if (a > 0.0 && b < 0.0) return true;
	if (floor(a) != floor(b)) return true;
	return false;
}
//
//double abs(double input) {
//	if (input > 0.0) return input;
//	return 0.0 - input;
//}
//
//double floor(double input) {
//	double result = input - (input % 1.0);
//	return result;
//}
//
//double ceil(double input) {
//	if (input % 1.0 == 0.0) {
//		return input;
//	}
//	return floor(input) + 1;
//}
double minorDistance(double a, double b) {
	if (a == b) return 0;

	if (!isInBetween(a, b)) {
		double left = floor(a);
		left = (a - left) + (b - left);
		double right = ceil(a);
		right = (right - a) + (right - b);

		double result = left < right ? left : right;
		//result = result % 1.0;

		return result;
	}
	else {

		double mins = min(a, b);
		double maxs = max(a, b);
		double minRight = ceilf(mins);

		double result = (minRight - mins) + (maxs - minRight);
		//result = result = result % 1.0;

		return result;
	}
}
//double perfectCity(std::vector<double> departure, std::vector<double> destination) {
//
//	if (departure.size() == 0 && destination.size() == 0)
//		return 0;
//
//	double sum = 0;
//	double path = 0;
//	double mis = 0;
//	const int seg = 1;
//	for (int i = 0; i < departure.size(); i++)
//	{
//		if (departure[i] >= seg || destination[i] >= seg) {
//			if (departure[i] <= destination[i])
//				path = destination[i] - departure[i];
//			else
//				path = departure[i] - destination[i];
//		}
//		else
//		{
//			path += seg - departure[i];
//			path += seg - destination[i];
//			if (path > seg)
//			{
//				if (departure[i] <= destination[i])
//					path = destination[i] - departure[i];
//				else
//					path = departure[i] - destination[i];
//
//				path = seg - path;
//
//			}
//		}
//
//		sum += path + mis;
//		path = 0;
//
//	}
//	cout << sum;
//
//	return sum;
//
//}
double perfectCity(std::vector<double> departure, std::vector<double>  destination) {
	double minorVert = 0;
	double minorHor = 0;

	minorVert = minorDistance(departure[1], destination[1]);
	minorHor = minorDistance(departure[0], destination[0]);

	return minorVert + minorHor;
}
bool parkingFit(int x, int x1, int y, int y1, std::vector<int> carDimensions)
{
	bool flag;
	if ((y - x + 1) == carDimensions[0] &&
		(y1 - x1 + 1) == carDimensions[1])
	{
		flag = true;
	}
	else if (y - x + 1 == carDimensions[1] &&
		y1 - x1 + 1 == carDimensions[0])
	{
		flag = true;
	}
	else {
		flag = false;
	}

	if (!flag)
		return false;
}

bool upEntrance(std::vector<int> luckySpot, std::vector<std::vector<int>> parkingLot)
{
	std::vector<int> ob;

	for (int i = luckySpot[0] - 1; i >= 0; i--)
	{
		for (int j = luckySpot[1]; j <= luckySpot[3]; j++)
		{
			if (parkingLot[i][j] == 1)
				return false;
		}
	}

	return true;

}
bool leftEntrance(std::vector<int> luckySpot, std::vector<std::vector<int>> parkingLot)
{
	std::vector<int> ob;

	for (int i = luckySpot[0]; i <= luckySpot[2]; i++)
	{
		for (int j = luckySpot[1] - 1; j < luckySpot[3]; j++)
		{
			if (parkingLot[i][j] == 1)
				return false;
		}
	}

	return true;
}
bool rightEntrance(std::vector<int> luckySpot, std::vector<std::vector<int>> parkingLot)
{
	std::vector<int> ob;

	for (int i = luckySpot[2]; i < parkingLot[0].size(); i++)
	{
		for (int j = luckySpot[3] + 1; j <= parkingLot[0].size(); j++)
		{
			if (parkingLot[i][j] == 1)
				return false;
		}
	}

	return true;
}
bool downEntrance(std::vector<int> luckySpot, std::vector<std::vector<int>> parkingLot)
{
	std::vector<int> ob;

	for (int i = luckySpot[2] + 1; i < parkingLot.size(); i++)
	{
		for (int j = luckySpot[1]; j <= luckySpot[3] + 1; j++)
		{
			if (parkingLot[i][j] == 1)
				return false;
		}
	}

	return true;
}
bool parkingSpot(std::vector<int> carDimensions, std::vector<std::vector<int>> parkingLot, std::vector<int> luckySpot) {

	bool flag;
	if ((luckySpot[2] - luckySpot[0] + 1) == carDimensions[0] &&
		(luckySpot[3] - luckySpot[1] + 1) == carDimensions[1])
	{
		flag = true;
	}
	else if (luckySpot[2] - luckySpot[0] + 1 == carDimensions[1] &&
		luckySpot[3] - luckySpot[1] + 1 == carDimensions[0])
	{
		flag = true;
	}
	else
		flag = false;


	if (!flag)
		return false;

	// Parking Spot Exists
	for (int i = luckySpot[0]; i <= luckySpot[2]; i++)
	{
		for (int j = luckySpot[1]; j <= luckySpot[3]; j++)
		{
			if (parkingLot[i][j] == 1)
				return false;
		}
	}

	//check entrances
	if (upEntrance(luckySpot, parkingLot) || leftEntrance(luckySpot, parkingLot) || downEntrance(luckySpot, parkingLot) || rightEntrance(luckySpot, parkingLot)) {
		return true;
	}

	return false;

}
