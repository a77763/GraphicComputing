//
//  XMLParser.hpp
//  Project
//
//  Created by Trident on 16/03/2018.
//

#ifndef XMLParser_hpp
#define XMLParser_hpp

#include <stdio.h>

#include <sstream>
#include <iostream>
#include <fstream>
#include "tinyxml2.h"
#include "Controls.hpp"
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif



using namespace std;
using namespace tinyxml2;
int loadXML(const char*, Controls*);
#endif /* XMLParser_hpp */
