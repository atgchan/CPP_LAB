
class MyString
{
public:
	int len;
	char * str;
public:
	MyString();
	MyString(const char* s);
	MyString(const MyString& s);
	~MyString();

	MyString& operator=(const MyString& s);
	MyString& operator+=(const MyString& s);
	bool operator==(const MyString& s);
	MyString operator+(const MyString& s);

	friend ostream& operator<<(ostream& os, const MyString& s);
	friend istream& operator>>(istream& os, MyString& s);

};