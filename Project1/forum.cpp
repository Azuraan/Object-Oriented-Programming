#include <iostream>
#include <string>
#include <cstdlib>
#include "objects.h"

using namespace std;
int idgen = 63194;

date::date(int d,int m, int y)
	:day(d),month(m),year(y){}

void date::print(){
	cout<< day <<"/"<<month<<"/"<<year;
}

void date::setdate(int d=0,int m=0,int y=0){
	day = d;
	month = m;
	year = y;
}

forum::forum(string n_title) : title(n_title){
	date today(27,11,2019);
	int size,i,d,m,y;
	string theme,creator;
	cout<<"Insert number of threads(at least one thread) :";
	cin>>size;
	if(size==0){
		cout<<"At least one thread is required"<<endl;
		exit(1);
	}
	threads = new thread*[size+1];
	threads[0] = new thread("Κανόνες Και Χρήσιμες Πληροφορίες","Professor",today);
	for(i=1;i<size;i++){
		cout<<"Insert the subject and the name of the creator of current thread: ";
		cin>> theme >> creator;
		cout<<"Insert day,month and year of creation: ";
		cin>> d >> m >> y;
		today.setdate(d,m,y);
		threads[i] = new thread(theme,creator,today);
	}
	threads[i]=NULL;
	cout<<"Forum with title: "<< title <<"has just been created!"<< endl;
}

forum::~forum(){
	int i;
	cout<<"Forum with title: "<< title <<"is about to be destroyed"<<endl;
	for(i=0;threads[i]!=NULL;i++)
		delete threads[i];
	delete threads;
}

void forum::print(){
	int i=0;
	cout<<"Printing forum "<< title <<" :"<<endl;
	while(threads[i]!=NULL){
		threads[i]->printTheme();
		i++;
	}
}

void forum::tsearch(string str){
	int i=0;
	while(threads[i]!=NULL && threads[i]->cmpTitle(str))
		i++;
	if(threads[i]!=NULL)
		threads[i]->print();
	else
		cout<<"There's no thread with this subject in this forum"<<endl;
}

void forum::psearch(int numb){
	int i=0;
	while(threads[i]!=NULL && threads[i]->search(numb))
		i++;
	if(threads[i]==NULL)
		cout<<"ID not found"<< endl;
}

post::post(int n_id,string n_title, string n_creator, date n_date, string n_text)
: id(n_id), title(n_title), creator(n_creator), cdate(n_date), text(n_text){
	cout<<"Created post: ID: "<< id <<", Title: "<< title <<", Creator: "<< creator <<", Date: ";
	cdate.print();
	cout<< endl << "\tText : "<< text << endl;
}

post::~post(){
	cout<<"Post number: " << id <<" is about to be destroyed"<<endl;
}


void post::print(){
	cout<<"ID: "<< id <<" Title: "<< title <<" Creator: "<< creator <<" Date: ";
	cdate.print();
	cout<<endl<<"\tText: "<< text << endl;

}

int post::cmpId(int numb){
		return id==numb;
}

thread::thread(string n_theme, string n_creator,date n_date)
:theme(n_theme),creator(n_creator),cdate(n_date){
	srand(time(NULL));

	date today(27,11,2019);
	int size,d,m,y,i;
	string ttle,creat,text;
	string available_txts[10]={"Black And White","Yellow bird","Red riot","White eagle","Blue sky","Purple","Roses","Brown Sugar","Green Arrow","Grey"};
	cout<<"Insert number of posts:";
	cin>>size;
	posts = new post*[size+1];
	for(i=0;i<size;i++){
		cout<<"Insert the title and the name of the creator of the post:";
		cin>> ttle>> creat;
		cout<<"Insert day,month and year of creation: ";
		cin>> d >> m >> y;
		today.setdate(d,m,y);
		text = available_txts[rand()%10];
		cout<<"Inserted text"<<endl;
		posts[i]=new post(idgen,ttle,creat,today,text);
		idgen++;
	}
	posts[i]=NULL;
	cout<<"Thread with subject: "<< theme<<" has just been created!"<<endl;
}

thread::~thread(){
	int i;
	cout<<"Thread with subject: "<< theme <<" is about to be destroyed"<<endl;
	for(i=0;posts[i]!=NULL;i++)
		delete posts[i];
	delete posts;

}

void thread::printTheme(){
	cout<< theme <<endl;
}

void thread::print(){
	int i=0;
	cout<<"Printing thread "<< theme <<" Creator: "<< creator<<" Date: ";
	cdate.print();
	cout<< endl <<"Posts: "<<endl;
	while(posts[i]!=NULL){
		posts[i]->print();
		i++;
	}
}

int thread::cmpTitle(string str){
	return !(str==theme);
}

int thread::search(int numb){
	int i=0;
	while(posts[i]!=NULL && !(posts[i]->cmpId(numb)))
		i++;
	if(posts[i]!=NULL){
		posts[i]->print();
		return 0;
	}else
		return 1;
}