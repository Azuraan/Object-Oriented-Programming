#include "objects.h"

static int idtable[1000];
void start(){
for(int i=0;i<1000;i++)
	idtable[i]=0;
srand(time(NULL));
}

Object::Object(){
	for(id = rand()%1000; idtable[id]!=0; id =rand()%1000);
	idtable[id] = 1;
	cout<< "Object just created!"<<endl;	
}

Object::~Object(){
	cout<< "Object to be destroyed!"<<endl;
	idtable[id] = 0;
}

void String::updateAt(int pos,char c){
	if(pos >= str.length())
		cout<<"There is no character in this position"<<endl;
	else{
		cout<<"Changing character '"<< str[pos] <<"' with '"<< c <<"'"<<endl;
		str[pos] = c;
	}				
}

PassengerCompartment::PassengerCompartment(){
	if(rand()%5 <= 3)
		internalPasComp=NULL;
	else
		internalPasComp = new PassengerCompartment();
	cout<<"Passenger Compartment just created!"<<endl;
}

PassengerCompartment::~PassengerCompartment(){
	cout<<"Passenger Compartment to be destroyed!"<<endl;
	if(internalPasComp!=NULL)
		delete internalPasComp;
}

String PassengerCompartment::toString(){
	String description("Object, ");
	description.concat("ID=" + to_string(getID()));
	description.concat(", Plane Component:");
	description.concat("Passenger Compartment with ");
	description.concat((internalPasComp!=NULL)? "Internal Compartment" : "No Internal Compartment");
	return description;
}

void PassengerCompartment::ready_check(){
	(this->toString()).print();
	cout<< "Passenger Compartment OK!"<<endl;
	if(internalPasComp!= NULL)
		internalPasComp->ready_check();
}

String PrivateCompartment::toString(){
	String description("Object, ");
	description.concat("ID=" + to_string(getID()));
	description.concat(", Plane Component:");
	description.concat("Private Compartment");
	return description;	
}

void PrivateCompartment::ready_check(){
	(this->toString()).print();
	cout<<"Private Compartment OK!"<<endl;
}

String EquipmentCompartment::toString(){
	String description("Object, ");
	description.concat("ID=" + to_string(getID()));
	description.concat(", Plane Component:");
	description.concat("Private Equipment Compartment");
	return description;	
}

void EquipmentCompartment::ready_check(){
	(this->toString()).print();
	cout<<"Equipment Compartment OK!"<<endl;
}

CargoBay::CargoBay(){
	internalEqComp = new EquipmentCompartment();
	cout<<"Cargo Bay just created!"<<endl;
}

CargoBay::~CargoBay(){
	cout<<"Cargo Bay to be destroyed!"<<endl;
	delete internalEqComp;
}

String CargoBay::toString(){
	String description("Object, ");
	description.concat("ID=" + to_string(getID()));
	description.concat(", Plane Component:");
	description.concat("Private Compartment, Cargo Bay with Internal Equipment Compartment");
	return description;	
}

void CargoBay::ready_check(){
	(this->toString()).print();
	cout<< "Cargo Bay OK!"<<endl;
	internalEqComp->ready_check();
}

Plane::Plane(string t,int p){
	title=t;
	capacity=p;
	cargoComp = new CargoBay();
	for(int i=0;i<3;i++)
		equipComps[i] = new EquipmentCompartment();
	int numb = rand()%capacity;
	numb = numb%4 +2;
	passComps = new PassengerCompartment *[numb+1];
	for(int i=0;i<numb;i++)
		passComps[i] = new PassengerCompartment();
	passComps[numb]=NULL;
	cout<<"Plane just created!"<<endl;
}

Plane::~Plane(){
	cout<<"Plane to be destroyed!"<<endl;
	delete cargoComp;
	for(int i=0;i<3;i++)
		delete equipComps[i];
	for(int i=0;passComps[i]!=NULL;i++)
		delete passComps[i];
	delete[] passComps;
}

String Plane::toString(){
	String description("Object, ");
	description.concat("ID=" + to_string(getID()));
	description.concat(", Plane :");
	description.concat(title);
	description.concat(" with capacity:" + to_string(capacity));
	for(int i=0;passComps[i]!=NULL;i++)
		description.concat("\n"+ (passComps[i]->toString()).getSTR());
	for(int i=0;i<3;i++)
		description.concat("\n"+ (equipComps[i]->toString()).getSTR());
	description.concat("\n" + (cargoComp->toString()).getSTR());
	return description;	
}

void Plane::ready_check(){
	(this->toString()).print();
	cargoComp->ready_check();
	for(int i=0;i<3;i++)
		equipComps[i]->ready_check();
	for(int i=0;passComps[i]!=NULL;i++)
		passComps[i]->ready_check();
	cout<<"Plane OK!"<< endl;
}

Object* Plane::clone(){
	Plane* cln = new Plane(title,capacity);
	delete cln->cargoComp;
	cln->cargoComp = (CargoBay *)cargoComp->clone();
	for(int i=0;i<3;i++){
		delete cln->equipComps[i];
		cln->equipComps[i] = (EquipmentCompartment *)equipComps[i]->clone();
	}
	for(int i=0;cln->passComps[i]!=NULL;i++)
		delete cln->passComps[i];
	delete[] cln->passComps;
	int j=0;
	for(int i=0;passComps[i]!=NULL;i++)
		j++;
	cln->passComps = new PassengerCompartment *[j+1];
	for(int i=0;i<j;i++)
		cln->passComps[i] = (PassengerCompartment *)passComps[i]->clone();
	cln->passComps[j]=NULL;
	cln->setID(getID());
	return cln;	
}

String SecurityEmployee::toString(){
	String description("Object, ");
	description.concat("ID=" + to_string(getID()));
	description.concat(", Employee:");
	description.concat("SecurityEmployee with name: ");
	description.concat(getName());
	return description;
}

String MaintenanceEmployee::toString(){
	String description("Object, ");
	description.concat("ID=" + to_string(getID()));
	description.concat(", Employee:");
	description.concat("MaintenanceEmployee with name: ");
	description.concat(getName());
	return description;
}

String CleaningEmployee::toString(){
	String description("Object, ");
	description.concat("ID=" + to_string(getID()));
	description.concat(", Employee:");
	description.concat("CleaningEmployee with name: ");
	description.concat(getName());
	return description;
}

void clone_encrypt_and_print(Object& ob){
	Object &new_ob = *(ob.clone());
	new_ob.equal(ob);
	new_ob.identical(&ob);
	String str_new_ob = new_ob.toString();
	String str_ob = ob.toString();
	for(int i=0;i<3;i++)
		str_new_ob.updateAt(rand()%(str_new_ob.length()+1),'A');
	str_ob.print();
	str_new_ob.print();
	str_ob.concat(str_new_ob.getSTR());
	cout << "Length of String = "<< str_ob.length() << endl;
	cout <<"Middle character(s) of string: ";
	if(str_ob.length()%2==0)
		cout<<str_ob.at(str_ob.length()/2)<<str_ob.at(str_ob.length()/2 +1)<<endl;
	else
		cout<<str_ob.at(str_ob.length()/2)<<endl;
	str_ob.clear();
	cout << "Length of String = "<< str_ob.length() << endl;
	new_ob.dstr_clone();
}