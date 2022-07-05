#include <iostream>
#include <string>
#include <cstdlib>
#include "objects.h"
#include <ctime>

extern int idgen;

using namespace std;
int main(){
int numb;

srand(time(NULL));


forum oop("Αντικειμενοστραφής Προγραμματισμός");

oop.print();

oop.tsearch("Κανόνες Και Χρήσιμες Πληροφορίες");

cout<<"How many random posts do you want to print:";
cin>>numb;

for(int i=0;i<numb;i++)
	oop.psearch( rand() %(idgen-63194) + 63194);
cout<<endl<<"End of Random Printing"<<endl;


}

