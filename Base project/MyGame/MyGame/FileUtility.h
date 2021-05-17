
#pragma once

#define _USE_MATH_DEFINES // get access to constants like M_PI

#include <math.h>
#include <string>
using namespace std;

class FileUtility

{

public:

	FileUtility(string filename);

	void AddToFile(string line);

	void DumpFile();
	
	void SetContents(string line);

	string GetContents();

	void EncryptContents(int seed);

	void DecryptContents(int seed);

private:
	void ReadFile();

	string filename;
	string contents;
};