//
//  ofxException.cpp
//  MOTIONER
//
//  Created by Onishi Yoshito on 1/2/13.
//
//

#include "ofxException.h"
#include <vector>
#include <sstream>
#include "ofUtils.h"

//----------------------------------------------------------------------------------------
ofxException::ofxException(const std::string &message) :
mMessage(message)
{
}

//----------------------------------------------------------------------------------------
ofxException::ofxException(const char *file,
                           const char *function,
                           const int line,
                           const std::string &message) :
mFileName(file),
mFunctionName(function),
mLine(line),
mMessage(message)
{
    createDetails();
}

//----------------------------------------------------------------------------------------
ofxException::ofxException(const char *file,
                           const char *function,
                           const int line,
                           const char *format,
                           ...) :
mFileName(file),
mFunctionName(function),
mLine(line)
{
    va_list args;
    va_start(args, format);
    std::vector<std::string> lines = ofSplitString(ofVAArgsToString(format, args), "\n");
    std::ostringstream oss;
    for (int i=0; i<lines.size(); i++)
        oss << lines.at(i) << endl;
    mMessage = oss.str();
    va_end(args);
    
    createDetails();
}

//----------------------------------------------------------------------------------------
ofxException::~ofxException() throw()
{
}

//----------------------------------------------------------------------------------------
const char* ofxException::what() const throw()
{
    return mDetails.c_str();
}

//----------------------------------------------------------------------------------------
std::string ofxException::getDetails() const
{
    return mDetails;
}

//----------------------------------------------------------------------------------------
std::string ofxException::getMessage() const
{
    return mMessage;
}

//----------------------------------------------------------------------------------------
std::string ofxException::getFileName() const
{
    return mFileName;
}

//----------------------------------------------------------------------------------------
std::string ofxException::getFunctionName() const
{
    return mFunctionName;
}

//----------------------------------------------------------------------------------------
const int ofxException::getLineNumber() const
{
    return mLine;
}

//----------------------------------------------------------------------------------------
void ofxException::createDetails()
{
    std::ostringstream oss;
    oss << "ofxException raised" << endl <<
    "File: " << mFileName << endl <<
    "Function: " << mFunctionName << endl <<
    "Line: " << mLine << endl <<
    "Message: " << mMessage;
    mDetails = oss.str();
}
