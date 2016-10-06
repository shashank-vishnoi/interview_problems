#include<iostream>


using namespace std;




class String{
	public:
	char *data;
	int len;
	int size()
	{
		return len;
	}
	String():data(0),len(0)
	{
	}
	~String()
	{
		if(data)
			delete []data;
//		cout<<"Memory released!!\n";
	}
	String(const char *str)
	{
		len = strlen(str);
		data = new char[len+1];
		strcpy(data,str);
	}
	String(const String& str)//copy ctor
	{
		//deep copy is required
		data = new char[str.len + 1];
		strcpy(data, str.data);		
	}
	String& operator=(const char* str)
	{
		if(data)
			delete []data;
		len = strlen(str);
		data = new char[len+1];
		strcpy(data,str);
		return *this;
	}
	String& operator=(String& str)
	{
		cout<<"operator=(String& str)\n";
		len = str.len;
		data = new char[len+1];
		strcpy(data,str.data);
		return *this;
	}

};

String operator+(const String& str, const char* c)
{
	String s;
	s.len = str.len + strlen(c);
	s.data = new char[s.len + 1];
	sprintf(s.data,"%s%s",str.data,c);
	return s;
}
String operator+(const char* c, const String& str)
{
	String s;
	s.len = str.len + strlen(c);
	s.data = new char[s.len + 1];
	sprintf(s.data,"%s%s",c,str.data);
	return s;
}
String operator+(const String& str1, const String& str2)
{
	String s;
	s.len = str1.len + str2.len;
	s.data = new char[s.len + 1];
	sprintf(s.data,"%s%s",str1.data,str2.data);
	return s;
}
/*
String operator=(const String& str1, const String& str2)
{
	if(this)
		delete this;
	String s;
	s.len = str1.len + str2.len;
	s.data = new char[s.len + 1];
	sprintf(s.data,"%s%s",str1.data,str2.data);
	return s;
}*/

ostream& operator<<(ostream& str, const String& s)
{
	str<<s.data;
	return str;
}


int main()
{
	String s1;
	String s2("hello!!");
	s1="i am s1"; //s1.operator=();
//	cout<<s1<<endl;
//	cout<<s2<<endl;

	String s3="i am s3, mind it";
//	cout<<s3<<endl;

	String s4=s1;//copy ctor
//	cout<<s4<<endl;

	//concatenation

	String s5 = s1 + " i am also s5";
	cout<<s5<<endl;
	//s5=s2+ "i am sssss5";
	//cout<<s5<<endl;
	String s6 =  " i am  s6 + " + s2;
	cout<<s6<<endl;

	s5 + s6;
	//s1=s5 + s6; //don't know why it is not working ????
	cout<<s1<<endl;


}
