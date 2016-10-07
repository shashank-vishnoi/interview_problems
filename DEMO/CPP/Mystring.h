//------------------------------------------------------------
// Mystring.h
// MWolfe
// 15-Mar-1997
//
// This is the header file for a String class that we will
// use in X459.  It is a very useful class, and it illustrates
// many principles of class library design.
//
//------------------------------------------------------------

#ifndef _MYSTRING_H_
#define _MYSTRING_H_


//
// The Mystring class is a generic utility class that will
// allow the developer to use an efficient and easy-to-use
// replacement for the standard char* string.
//
class Mystring
{

private:
	// The string data, held internally.  Only accessible by
	// members of this class.  A char* is used, and the original
	// string functions (strlen, strcat) provided by string.h 
	// can be used, however the consumer of this class will not
	// have to worry about any of those details.
	char*	_strdata;

public:

	// Default constructor.  Called in code like:
	// Mystring s;
	//
	Mystring();


	// Constructor with a char*, called on:	
	// Mystring s = "Hello";
	//
	Mystring(const char* cstr);


	//
	// Construction of Mystring from an int
	//
	Mystring(int i);


	// Copy constructor, called when constructing one string
	// from another, such as:
	//
	// Mystring a;  
	// Mystring b(a);		// Called here
	//
	Mystring(const Mystring& mstr);


	// Assignment of a char* to a Mystring.  Called on:  
	//
	// Mystring a;  
	// a = "Hello";			// Called here
	//
	Mystring& operator=(const char* cstr);

	
	// Assignment operator.  Called on:
	//
	// Mystring a, b;  
	// b = a;				// Here
	//
	Mystring& operator=(const Mystring& mstr);

	
	// Allows concatenating two strings using the '+' operator.
	// returns a reference to the Mystring so that it can be
	// used on the RHS of an equation, such as:
	//
	// Mystring a, b, c;
	// a = (b = c);
	//
	Mystring operator+(const Mystring& mstr);


	//
	// Return the character at a given position
	//
	char& operator[](int pos);
	

	//
	// Return if a string is after this string in
	// alphanumeric order
	int operator<(const Mystring& mstr);
	int operator>(const Mystring& mstr);
	int operator==(const Mystring& mstr);


	// Return the string length
	//
	int length() const;

	
	// Destructor
	//
	~Mystring();


	// Print to an output stream.  This is a friend function,
	// so it is not a member of Mystring.
	//
	friend ostream& operator<<(ostream& s, const Mystring& mstr);


	// Read from an input stream. This is a friend function,
	// so it is not a member of Mystring.
	//
	friend istream& operator>>(istream& s, Mystring& mstr);

};

#endif _MYSTRING_H_
