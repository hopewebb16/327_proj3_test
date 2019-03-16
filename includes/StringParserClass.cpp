/*
 * StringParserClass.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: Hope
 */
#include <string>
#include <string.h>

#include "../327_proj3_test/includes/StringParserClass.h"
#include "../327_proj3_test/includes/constants.h"

using namespace KP_StringParserClass;


//dont forget to initialize member variables
StringParserClass::StringParserClass():pStartTag(0),pEndTag(0),areTagsSet(false){
}

StringParserClass::~StringParserClass(){
}

//
//		//call cleanup to release any allocated memory
//		virtual ~StringParserClass(void);

		//these are the start tag and the end tags that we want to find,
		//presumably the data of interest is between them, please make a
		//COPY of what pStartTag and pEndTag point to.  In other words
		//DO NOT SET pStartTag = pStart
		//returns:
		//SUCCESS
		//ERROR_TAGS_NULL if either pStart or pEnd is null
		int setTags(const char *pStart, const char *pEnd){
			if(pStart == NULL || pEnd == NULL){
				return ERROR_TAGS_NULL;
			}
			int lenStart = strlen(pStart) + 1;
			int lenEnd= strlen(pEnd)+1;

			pStartTag = new char(lenStart);
			strncpy(pStartTag, pStart, lenStart);

			pEndTag = new char(lenEnd);
			strncpy(pEndTag, pEnd, lenEnd);

			return SUCCESS;

		}

		//First clears myVector
		//going to search thru pDataToSearchThru, looking for info bracketed by
		//pStartTag and pEndTag, will add that info only to myVector
		//returns
		//SUCCESS  finished searching for data between tags, results in myVector (0 or more entries)
		//ERROR_TAGS_NULL if either pStart or pEnd is null
		//ERROR_DATA_NULL pDataToSearchThru is null
		int getDataBetweenTags(char *pDataToSearchThru, std::vector<std::string> &myVector){

			if(pStartTag == NULL || pEndTag == NULL) {
				return ERROR_TAGS_NULL;
			}
			if(pDataToSearchThru == NULL){
				return ERROR_DATA_NULL;
			}

			int length = strlen(pDataToSearchThru);

			for(int i =0; i < length; i++){
				if(*(pDataToSearchThru +i) == *pStartTag) {
					for(int j = i; j <= length; j++){
						if(*(pDataToSearchThru +j) ==*pEndTag && strncmp((pDataToSearchThru +j), pEndTag, length)){
								break;
						}
							myVector.push_back((pDataToSearchThru + j));
					}
				}
					return SUCCESS;
			}
		}
