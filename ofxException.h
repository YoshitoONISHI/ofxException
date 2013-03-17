//
//  ofxException.h
//  ofxException
//
//  Created by Onishi Yoshito on 12/4/12.
//
//

#ifndef __ofxException_ofxException_h__
#define __ofxException_ofxException_h__

#include <exception>
#include <string>

//----------------------------------------------------------------------------------------
class ofxException : public std::exception {
public:
    //--------------------
    ofxException(const std::string &message);
    ofxException(const char *file,
                 const char *function,
                 const int line,
                 const std::string &message);
    ofxException(const char *file,
                 const char *function,
                 const int line,
                 const char *format,
                 ...);
    
    //--------------------
    virtual ~ofxException() throw();
    
    //--------------------
    std::string getDetails() const;
    std::string getMessage() const;
    std::string getFileName() const;
    std::string getFunctionName() const;
    const int getLineNumber() const;
    
    //--------------------
    virtual const char *what() const throw();
    
private:
    //--------------------
    void createDetails();
    
    //--------------------
    std::string mDetails;
    std::string mMessage;
    std::string mFileName;
    std::string mFunctionName;
    int mLine;
    
};


//----------------------------------------------------------------------------------------
#define ofxThrowException(EXCEPTION_TYPE, message) \
throw EXCEPTION_TYPE(__FILE__, __PRETTY_FUNCTION__, __LINE__, message)

//----------------------------------------------------------------------------------------
#define ofxThrowExceptionf(EXCEPTION_TYPE, format, ...) \
throw EXCEPTION_TYPE(__FILE__, __PRETTY_FUNCTION__, __LINE__, format, __VA_ARGS__)


/// exception handler
//----------------------------------------------------------------------------------------
#define OFX_BEGIN_EXCEPTION_HANDLING try {

//----------------------------------------------------------------------------------------
#define OFX_END_EXCEPTION_HANDLING }\
catch (std::exception &e) {\
ofLogError() << e.what();\
}\
catch (...) {\
ofLogError() << "Unknown exception catched!";\
}

//----------------------------------------------------------------------------------------
#define OFX_ASSERT_END_EXCEPTION_HANDLING }\
catch (std::exception &e) {\
assert(!e.what());\
}\
catch (...) {\
assert(!"Unknown exception catched!");\
}


#endif
