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
		post(const post&);
		~post();
		void print();
		int cmpId(int);
		string get_creator(){
			return creator;
		};
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
		post* get_post_ptr(int);

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
		void print_sorted();
};

struct list_of_posts{
		post* lpost;
		list_of_posts *npost;

		list_of_posts(post&);
		~list_of_posts();
		void print();
};

typedef list_of_posts * listptr;

class Tree{
	private:
		string creator;
		listptr clist;
		Tree *apaidi;
		Tree *dpaidi;
	public:
		Tree(thread&);
		Tree(post&);
		~Tree();
		void TreeInsert(post&);
		void printTree();
		void TreeEnhance(Tree *);
		void TreePositionToInsert(Tree *);
};
