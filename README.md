ofxException
============

Useful tools for C++ exception


	/// exceptions will be catched from this line
	OFX_BEGIN_EXCEPTION_HANDLING
	
	/// some processes

    if (error) {
    	/// throw an exception with message
        ofxThrowException(ofxException, "Error message!");
    }
        
    /// some processes
        
    if (error) {
        /// throw an exception with format
        ofxThrowExceptionf(ofxException, "Error format! %d, %f", 123, 4.567);
    }
        
    /// to this line   
    OFX_END_EXCEPTION_HANDLING