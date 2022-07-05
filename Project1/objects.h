#include <iostream>


using namespace std;

class date{
		int day;int month;int year;
	public:
		date(int,int,int);
		void print();
		void setdate(int,int,int);
};

class post{
	private:
		int id;
		string title;
		string creator;
		date cdate;
		string text;
	public:
		post(int ,string , string, date , string);
		~post();
		void print();
		int cmpId(int);
};

class thread{
	private:
		string theme;
		string creator;
		date cdate;
		post **posts;
	public:
		thread(string ,string, date);
		~thread();
		void printTheme();
		void print();
		int cmpTitle(string);
		int search(int);
};

class forum{
	private:
		string title;
		thread **threads;
	public:
		forum(string);
		~forum();
		void print();
		void tsearch(string);
		void psearch(int);
};