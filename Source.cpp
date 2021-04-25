// Assign2_2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <map>
#include <sstream>

using namespace std;

string dir = "C:\\Users\\Stefan\\source\\repos\\Assignment2\\Assign2FIles\\";

string FNAME1 = "A2Part1a.txt";
string FNAME1e = "A2Part1err.txt";
string FNAME2 = "A2Part2a.txt";
string FNAME2e = "A2Part2err.txt";
string FNAME3 = "A2Part3a.txt";
string FNAME3e = "A2Part3err.txt";
string FNAME4 = "A2Part4a.txt";
string FNAME4e = "A2Part4err.txt";
string FNAME5 = "A2Part5a.txt";
string FNAME5e = "A2Part5err.txt";
string FNAMET = "A2Test.txt";

string fileName = "";

bool debug1 = false;
bool debug2 = false;
bool debug3 = false;
bool debug4 = false; // trace 
bool debug5 = false; // around = 

vector<string> fileStringList = {};

map<string, float> keyValueList = {};

string errGlobal = "";
bool hasError = false;
int errLineNum = 0;
string errLine = "";


string trim(const string& str,
	const std::string& whitespace = " \t")
{
	// from h ttps://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	//
	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

void showVector(vector<string>& printVector)
{
	int i = 0;
	cout << "\nThis is the input file\n";
	cout << "----------------------\n";
	for (string value : printVector)
	{
		cout << "line " << ++i << " is:" << value << endl;
	}
	cout << "\n";
}

void addFileLinesToVector(string fileNameZ, vector<string>& stringVectorReference)
{
	stringVectorReference.clear();
	ifstream myFile(fileNameZ);

	if (!myFile.is_open())
	{
		cout << "Error File not found ->" << fileNameZ << "<-\n\n";
		return;
	}

	// Assign values temporarily to fileLineString while reading file
	string fileLineString;

	int i = 0;
	while (getline(myFile, fileLineString))
	{
		if (debug1) cout << "DEBUG1 - line " << ++i << " is:" << fileLineString << endl;
		fileLineString = trim(fileLineString);
		
		if (fileLineString[0] != '/') {
			stringVectorReference.push_back(fileLineString);
		}

		cout << "Read line: " << fileLineString << endl;
	}

	showVector(stringVectorReference);
}

// Print out maps
void showMap(map<string, float>& m)
{
	int i = 0;
	map<string, float>::iterator iter;  // construct an iterator
	cout << "\n";
	cout << "These are the variables at the end of the run\n";
	cout << "---------------------------------------------\n";

	for (iter = m.begin(); iter != m.end(); ++iter) // these should be sorted
	{
		cout << "m[" << iter->first << "]=" << iter->second << '\n';
	}
	cout << "\n";
}


void doP6(vector<string>& inVec, map<string, float>& keyValueList)
{

}

void doP5(vector<string>& inVec, map<string, float>& keyValueList)
{
	keyValueList.clear();
	cout << "This is the result of the P5 run\n";
	cout << "--------------------------------\n";

}

void doP4(vector<string>& inVec, map<string, float>& keyValueList)
{
	cout << "This is the result of the P4 run\n";
	cout << "--------------------------------\n";



}

void doP3(vector<string>& inVec, map<string, float>& keyValueList)
{
	cout << "This is the result of the P3 run\n";
	cout << "--------------------------------\n";

}

void doP2(vector<string>& inVec, map<string, float>& keyValueList)
{
	cout << "This is the result of the P2 run\n";
	cout << "--------------------------------\n";

}

string deserialiseStringByEquals(string serialisedString) {
	stringstream stringStream(serialisedString);
	string response;

	getline(stringStream, response, '=');

	// TODO: Test if response has value if not throw no equals error

	return response;
}

void doP1(vector<string>& fileLineVector, map<string, float>& keyValueListRef)
{
	keyValueList.clear();

	string key;
	string stringValue;

	for (string value : fileLineVector) {

		key = deserialiseStringByEquals(value);

		int keyLength = key.length() + 1;
		int valueLength = value.length() - 1;

		string stringNumber = value.substr(keyLength, valueLength);

		float numberValue = stof(stringNumber);

		keyValueListRef.insert(make_pair(key, numberValue));
	}

	cout << "This is the result of the P1 run\n";
	cout << "--------------------------------\n";
	cout << "(No output except errors it just sets the values)\n";
}



int main()
{
	std::cout << "ST2 Assigment2 \n";

	FNAME1 = dir + FNAME1; // "A2Part1a.txt";
	FNAME1e = dir + FNAME1e; // "A2Part1err.txt";
	FNAME2 = dir + FNAME2; // "A2Part2a.txt";
	FNAME2e = dir + FNAME2e; // "A2Part2err.txt";
	FNAME3 = dir + FNAME3; // "A2Part3a.txt";
	FNAME3e = dir + FNAME3e; // "A2Part3err.txt";
	FNAME4 = dir + FNAME4; // "A2Part4a.txt";
	FNAME4e = dir + FNAME4e; //"A2Part4err.txt";
	FNAME5 = dir + FNAME5; // "A2Part5a.txt";
	FNAME5e = dir + FNAME5e; // "A2Part5err.txt";
	FNAMET = dir + FNAMET; // "A2Test.txt";

	string opt = " ";
	while (toupper(opt[0]) != 'E')
	{
		std::cout << "Assign2 2021 Menu\n";
		if (debug4) std::cout << "Debug trace on\n";
		std::cout << "E(xit) -   Exit\n";
		std::cout << "P1  - Create map of values \n";
		std::cout << "P1e - Create map of values (with error input) \n";
		std::cout << "P2  - Parse Strings  \n";
		std::cout << "P2e - Parse Strings  (with error input)\n";
		std::cout << "P3  - Parse Strings including variables  \n";
		std::cout << "P3e - Parse Strings including variables (with Errors) \n";
		std::cout << "P4  - Make them statements with an =   \n";
		std::cout << "P4e - Make them statements with an = (with Errors) \n";
		std::cout << "P5  - Add divide and multiply  \n";
		std::cout << "P5e - Add divide and multiply  (with Errors)\n";
		std::cout << "T   - Temporary for testing (not part of assessment)\n";
		std::cout << "D   - set unset debug4  (not part of assessment)\n";
		// std::cout << "M1   - Run file A2Part1m.txt\n";
		// std::cout << "M2   - Run file A2Part2m.txt\n";
		// std::cout << "M3   - Run file A2Part3m.txt\n";
		// std::cout << "M4   - Run file A2Part4m.txt\n";
		// std::cout << "M5   - Run file A2Part5m.txt\n";

		cin >> opt;
		std::cout << "Option selected:" << opt << endl;
		for (auto& c : opt) c = toupper(c);

		// Run option 1 - Serialise file lines into map
		if (opt == "P1") {
			addFileLinesToVector(FNAME1, fileStringList);

			doP1(fileStringList, keyValueList);
			showMap(keyValueList);
		}

		if (opt == "P1E") { addFileLinesToVector(FNAME1e, fileStringList); showVector(fileStringList); doP1(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "P2") { addFileLinesToVector(FNAME2, fileStringList); showVector(fileStringList); doP2(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "P2E") { addFileLinesToVector(FNAME2e, fileStringList); showVector(fileStringList); doP2(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "P3") { addFileLinesToVector(FNAME3, fileStringList); showVector(fileStringList); doP3(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "P3E") { addFileLinesToVector(FNAME3e, fileStringList); showVector(fileStringList); doP3(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "P4") { addFileLinesToVector(FNAME4, fileStringList); showVector(fileStringList); doP4(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "P4E") { addFileLinesToVector(FNAME4e, fileStringList); showVector(fileStringList); doP4(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "P5") { addFileLinesToVector(FNAME5, fileStringList); showVector(fileStringList); doP5(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "P5E") { addFileLinesToVector(FNAME5e, fileStringList); showVector(fileStringList); doP5(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "T") { addFileLinesToVector(FNAMET, fileStringList); showVector(fileStringList); doP1(fileStringList, keyValueList); showMap(keyValueList); }
		if (opt == "D") debug4 = !debug4;
		//if (opt == "M1")  // example for students
		//{ 
		//	FNAME1 = dir + "A2Part1m.txt";
		//	readFileVec(FNAME1, inVec); showVector(inVec); doP1(inVec, keyValueList); showMap(keyValueList); 
		//}

		std::cout << endl;
	}
	std::cout << "Program Exits\n";
}