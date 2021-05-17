#include "FileUtility.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

FileUtility::FileUtility(string filename)
{
	this->filename = filename;
	ReadFile();
}

void FileUtility::SetContents(string line)
{
	contents = line;

	ofstream myfile(filename, ofstream::trunc);

	if (myfile.is_open())
	{
		myfile << contents;
		myfile.close();
	}
	else
	{
		cout << "could not open file: " << filename << endl;
	}
}

void FileUtility::AddToFile(string line)
{
	contents.append(line);
	contents.append("\n");

	ofstream myfile(filename, ofstream::trunc);

	if (myfile.is_open())
	{
		myfile << contents;
		myfile.close();
	}
	else
	{
		cout << "could not open file: " << filename << endl;
	}
}

void FileUtility::DumpFile()
{
	ifstream myfile(filename);

	if (myfile.is_open())
	{
		cout << contents;
		myfile.close();
	}
	else
	{
		cout << "could not open file: " << filename << endl;
	}
}

string FileUtility::GetContents()
{
	return contents;
}

void FileUtility::ReadFile()
{
	string line;
	ifstream myfile(filename);

	if (myfile.is_open())
	{
		contents = "";
		while (getline(myfile, line))
		{
			contents.append(line);
			contents.append("\n");
		}
		myfile.close();
	}
	else
	{
		cout << "could not open file: " << filename << endl;
	}
}

void FileUtility::EncryptContents(int seed)
{
	string encryptedcontents = contents;
	for (int i = 0; i < contents.length(); i++)
	{
		if (contents[i] >= ' ' && contents[i] <= '~')
		{
			int newval = contents[i] + seed;
			if (newval > '~')
			{
				newval -= 95;
			}
			encryptedcontents[i] = newval;
		}
	}
	SetContents(encryptedcontents);
}

void FileUtility::DecryptContents(int seed)
{
	string decryptedcontents = contents;
	for (int i = 0; i < contents.length(); i++)
	{
		if (contents[i] >= ' ' && contents[i] <= '~')
		{
			int newval = contents[i] - seed;
			if (newval < ' ')
			{
				newval += 95;
			}
			decryptedcontents[i] = newval;
		}
	}
	SetContents(decryptedcontents);
}
