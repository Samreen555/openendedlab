#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
vector<int> mergeArrays(const vector<int>& array1, const vector<int>& array2); //function prototype
vector<int> findCommonElements(const vector<int>& array1, const vector<int>&array2); // function prototype
bool isPalindrome(const string& str); // function prototype
int main()
{
	// step1: creating two arrays
	vector<int> array1, array2; // declaring a vector to add elements
	cout << "Enter 5 integers for array1:";
	for (int i = 0; i < 5; i++)
	{
		int value;
		cin >> value;
		array1.push_back(value);
	}
	cout << endl;
	cout << "Enter 7 integers for array2: ";
	for (int i = 0; i < 7; i++) {
		int value;
		cin >> value;
		array2.push_back(value);
	}
	// Step 2: Merge arrays maintaining ascending order
	vector<int> mergedArrays;
		mergedArrays = mergeArrays(array1, array2);
	// Step 3: Find common elements between the two arrays
	vector<int> commonElements = findCommonElements(array1, array2);
	// Step 4: Check if a sentence is a palindrome
	cin.ignore();
	cout << "Enter a sentence: ";
	string sentence;
	getline(cin, sentence);
	bool isPalindromeResult = isPalindrome(sentence);
	// Step 5: Display results
	cout << "\nMerged Array: ";
	for (const auto& elem : mergedArrays)
	{
		cout << elem << " ";
	}
	cout << "\nCommon Elements: ";
	for (const auto& elem : commonElements) {
		cout << elem << " ";
	}
	cout << "\nIs Palindrome: " << (isPalindromeResult ? "Yes" : "No") << std::endl;
	system("pause");
	return 0;
}
vector<int> mergeArrays(const vector<int>& array1, const vector<int>& array2) //function defination
{
	vector<int> mergeArrays = array1;
	mergeArrays.insert(mergeArrays.end(), array2.begin(), array2.end());
	sort(mergeArrays.begin(), mergeArrays.end());
	return mergeArrays;
}
vector<int> findCommonElements(const vector<int>& array1, const vector<int>& array2)  //function defination
{
	vector<int> commonElements;
	for (const auto& elem : array1)
	{
		if (find(array2.begin(), array2.end(), elem) != array2.end())
		{
			commonElements.push_back(elem);
		}
	}
	return commonElements;
}
bool isPalindrome(const string& str) // function defination
{
	string cleanedStr;
	copy_if(str.begin(), str.end(), back_inserter(cleanedStr), ::isalnum);
	transform(cleanedStr.begin(), cleanedStr.end(), cleanedStr.begin(), ::tolower);
	return cleanedStr == string(cleanedStr.rbegin(), cleanedStr.rend());
}