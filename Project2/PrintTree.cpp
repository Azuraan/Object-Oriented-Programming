#include <string>
#include <cstdlib>
#include "objects.h"

using namespace std;

Tree::Tree(thread &t){
	int i=0;
	post *pptr=NULL;
		if((pptr = t.get_post_ptr(i))!=NULL){
			creator = pptr->get_creator();
			clist = new list_of_posts(*pptr);
			apaidi = NULL;
			dpaidi = NULL;
			for(i=1;(pptr = t.get_post_ptr(i))!=NULL;i++)
				TreeInsert(*pptr);
		}
		else{
			cout<<"Error:There's no post to insert into a BSTree in this thread"<<endl;
			exit(1);
		}
}

Tree::Tree(post &p){
		creator = p.get_creator();
		clist = new list_of_posts(p);
		apaidi = NULL;
		dpaidi = NULL;
}

void Tree::TreeInsert(post &p){
	string pcreator = p.get_creator();
		if(pcreator < creator)
			if(apaidi!=NULL)
				apaidi->TreeInsert(p);
			else
				apaidi = new Tree(p);
		else if(pcreator > creator)
			if(dpaidi!=NULL)
				dpaidi->TreeInsert(p);
			else
				dpaidi = new Tree(p);
		else if(pcreator == creator){
			listptr temp=clist;
			while(temp->npost!=NULL)
				temp = temp->npost;
			temp->npost = new list_of_posts(p);
		}

}

Tree::~Tree(){
	delete clist;
	if(apaidi!=NULL)
		delete apaidi;
	if(dpaidi!=NULL)
		delete dpaidi;
}

void Tree::printTree(){
	if(this!=NULL){
		apaidi->printTree();
		if(clist!=NULL)
			clist->print();
		dpaidi->printTree();
	}
}

void Tree::TreeEnhance(Tree* t){
	if(t==NULL){
		cout<<"Error:There's no tree to enhance the first BSTree"<<endl;
		exit(1);
		}
	if(t->apaidi!=NULL)
		this->TreeEnhance(t->apaidi);
	if(t->dpaidi!=NULL)
		this->TreeEnhance(t->dpaidi);
	t->apaidi = NULL;
	t->dpaidi = NULL;
	TreePositionToInsert(t);
}

void Tree::TreePositionToInsert(Tree *t){
	if(t->creator < creator){
		if(apaidi!=NULL)
			apaidi->TreePositionToInsert(t);
		else
			apaidi = t;
	}
	else if(t->creator > creator){
		if(dpaidi!=NULL)
			dpaidi->TreePositionToInsert(t);
		else
			dpaidi = t;
	}
	else{
			listptr tmp1=clist, tmp2=t->clist;
			while(tmp1->npost!=NULL)
				tmp1 = tmp1->npost;
			while(tmp2!=NULL){
				tmp1->npost = new list_of_posts(*(tmp2->lpost));
				tmp1 = tmp1->npost;
				tmp2 = tmp2->npost;
			}
			delete t;
	}
}

list_of_posts::list_of_posts(post& p){
	lpost = new post(p);
	npost = NULL;
}

list_of_posts::~list_of_posts(){
		if(npost!=NULL)
			delete npost;
		delete lpost;
}

void list_of_posts::print(){
	lpost->print();
	if(npost!=NULL)
		npost->print();
}