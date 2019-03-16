/*
 * FileIO.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: Hope
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

//trys to open filename, and return its contents in contents
	//it will strip out only \n's (char return\line feed)
	//returns:
	//SUCCESS all worked, contents string contains all in the file
	//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
	int getFileContents(const std::string &filename, std::string &contents){
	ifstream myfile;
	myfile.open(filename.c_str(), ios::in);
	if (!myfile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_READ;

	}

	string line = "";
	while (!myfile.eof()){
		getline(myfile,line);
		contents.append(line);
	}
		return SUCCESS;
	}

	//trys to pen filename, and serialize  myEntryVector contents to it
	//returns:
	//SUCCESS all worked, filename contains myEntryVector strings
	//COULD_NOT_OPEN_FILE_TO_WRITE
	int writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector){
		ofstream myfile;
		myfile.open(filename.c_str(),ios::out);
		if(!myfile.is_open()) {
			return COULD_NOT_OPEN_FILE_TO_WRITE;

		}
		for (int i=0; i < myEntryVector.size(); i++){
			myfile << myEntryVector[i] << endl;
		}
		myfile.close();
		return SUCCESS;
}

