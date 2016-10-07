#include<iostream>


using namespace std;

#define INITIAL_SIZE 15

class String{
	char *buffer;
	int count;
	public:
		String()
		{
			buffer = new char[INITIAL_SIZE];
			memset(buffer,'\0', INITIAL_SIZE);
			count=0;
		}
		String(char* str)
		{
			buffer = new char[strlen(str)+1];
			memset(buffer,'\0',strlen(str)+1);
			memcpy(buffer, str, strlen(str));
			count=strlen(str);
		}
		String(const String& str)
		{
				this->buffer = new char[str.count+1];
				memset(this->buffer,'\0',str.count+1);
				memcpy(this->buffer, str.buffer, str.count);
				this->count=str.count;
		}
		String& operator+(const char* str)
		{
			int len = strlen(str);
			if(count + len + 1 < INITIAL_SIZE)
			{
				strcat(buffer,str);
			}
			else{
			}

			return *this;
		}
		~String()
		{
			delete []buffer;
		}
		int size()
		{
			return count;
		}
		char* data()
		{
			return buffer;
		}	
};



int main()
{
	String str("hello");
	cout<<str.data()<<endl;
	str = str + " dear, how are you ! thanks a lot ";
	cout<<str.data()<<endl;
}
