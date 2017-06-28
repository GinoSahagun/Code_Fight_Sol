

#include <vector>
#include <iostream>

using namespace std;
void reverseRows(std::vector<std::vector<int> > &a) {

	for (int i = 0; i < a.size(); i++)
	{
		std::reverse(a[i].begin(), a[i].end());
	}

}
void transpose(std::vector < std::vector<int> > &a)
{
	//std::swap(a[0], a[2]);
	for (int i = a.size() - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{

			std::swap(a[j][i], a[i][j]);

		}

	}
}
void displayMatrix(std::vector<std::vector<int> > a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{

			cout << a[i][j];

		}
		cout << endl;
	}
}
std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {

	transpose(a);
	reverseRows(a);
	displayMatrix(a);
	cout << endl;

	return a;
}