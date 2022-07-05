#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class String;

class Object{
	private:
		int id;
	public:
		Object();
		virtual ~Object();
		void equal(Object &t){
			if(id == t.id)
			 cout<<"Objects are equal"<<endl;
			else
			 cout<<"Objects are not equal"<< endl;
		};
		void identical(Object *t){
			if(this == t) 
				cout<<"Objects are identical"<<endl;
			else
				cout<<"Objects are not identical" << endl;
		};
		virtual Object* clone()=0;
		virtual void dstr_clone()=0; 
		virtual String toString()=0;
		int getID(){
			return id;
		};
		void setID(int i){
			id=i;
		};
};

class String : public Object{
	private:
		string str;
	public:
		String(string s){
			str = s;
			cout<<"String just created!"<<endl;
		};
		~String(){
			cout<<"String to be destroyed!"<<endl;
		};
		int length(){
			return str.length();
		};
		void clear(){
			str.clear();
		};
		void concat(string str2){
			str = str + str2;
		};
		char at(int pos){
			if(pos<=length())
				return str[pos];
			else
				cout<<"Error! : Trying to access non existant position of string"<<endl;
			return 0;
		};
		void updateAt(int ,char);
		void print(){
			cout << str <<endl;
		};
		String toString(){
			String description("Object, ");
			description.concat("ID = "+to_string(getID()) + "String");
			return description;
		};
		Object* clone(){
			String *cln = new String(str);
			cln->setID(getID());
			return cln;
		};
		void dstr_clone(){
			delete this;
		};
		string getSTR(){
			return str;
		};
};

class Employee;

class PlaneComponent : public Object{
	public:
		PlaneComponent(){
			cout<<"PlaneComponent just created!"<<endl;
		};
		virtual ~PlaneComponent(){
			cout<<"PlaneComponent to be destroyed!"<<endl;
		};
		virtual String toString()=0;
		virtual void ready_check()=0;
		virtual void process(Employee &) =0;
		virtual Object* clone()=0;
		virtual void dstr_clone()=0;
};

class Employee : public Object{
	private:
		string name;
	public:
		Employee(string n){
			name = n;
			cout<<"Employee just created!"<<endl;
		};
		virtual ~Employee(){
			cout<<"Employee to be destroyed!"<<endl;
		};
		virtual void workOn(PlaneComponent &station) =0;
		virtual void report() =0;
		virtual String toString() =0;
		string getName(){
			return name;
		};
		virtual Object* clone() =0;
		virtual void dstr_clone()=0;
};

class SecurityEmployee : public Employee{
	public:
		SecurityEmployee(string n):Employee(n){
			cout<<"SecurityEmployee just created!"<<endl;
		};
		~SecurityEmployee(){
			cout<<"SecurityEmployee to be destroyed!"<<endl;
		};
		void workOn(PlaneComponent &station){
			cout<< "Security Employee with ID:"<< getID() <<" is working on "<< (station.toString()).getSTR() <<endl;
		};
		void report(){
			cout<< "Making sure everything is okay and providing a safe trip"<<endl;
		};
		String toString();
		Object* clone(){
			SecurityEmployee *cln = new SecurityEmployee(getName());
			cln->setID(getID());
			return cln;
		};
		void dstr_clone(){
			delete this;
		};
};

class MaintenanceEmployee : public Employee{
	public:
		MaintenanceEmployee(string n):Employee(n){
			cout<<"MaintenanceEmployee just created!"<<endl;
		};
		~MaintenanceEmployee(){
			cout<<"MaintenanceEmployee to be destroyed!"<<endl;
		};
		void workOn(PlaneComponent &station){
			cout<< "Maintenance Employee with ID:"<< getID() << " is working on "<< (station.toString()).getSTR() << endl;
		};
		void report(){
			cout<< "Keeping everything working smoothly and taking good care of the equipment and the cargo" << endl;
		};
		String toString();
		Object* clone(){
			MaintenanceEmployee *cln = new MaintenanceEmployee(getName());
			cln->setID(getID());
			return cln;
		};
		void dstr_clone(){
			delete this;
		};
};

class CleaningEmployee : public Employee{
	public:
		CleaningEmployee(string n):Employee(n){
			cout<<"CleaningEmployee just created!"<<endl;
		};
		~CleaningEmployee(){
			cout<<"CleaningEmployee to be destroyed!"<<endl;
		};
		void workOn(PlaneComponent &station){
			cout<< "Cleaning Employee with ID:"<< getID() << " is working on " << (station.toString()).getSTR() << endl;
		};
		void report(){
			cout<< "Cleaning my compartment" << endl;
		};
		String toString();
		Object* clone(){
			CleaningEmployee *cln = new CleaningEmployee(getName());
			cln->setID(getID());
			return cln;
		};
		void dstr_clone(){
			delete this;
		};
};

class PassengerCompartment : public PlaneComponent{
	private:
		PassengerCompartment* internalPasComp;
	public:
		PassengerCompartment();
		~PassengerCompartment();
		String toString();
		void ready_check();
		void process(Employee &E){
			E.workOn(*this);
		};
		Object* clone(){
			PassengerCompartment *cln = new PassengerCompartment();
			if(cln->internalPasComp!=NULL)
				delete cln->internalPasComp;
			if(internalPasComp!=NULL)
				cln->internalPasComp = (PassengerCompartment*)internalPasComp->clone();
			else
				cln->internalPasComp = NULL;
			cln->setID(getID());
			return cln;
		};
		void dstr_clone(){
			delete this;
		};
};

class PrivateCompartment : public PlaneComponent{
	public:
		PrivateCompartment(){
			cout<<"Private Compartment just created!"<<endl;
		};
		~PrivateCompartment(){
			cout<<"Private Compartment to be destroyed!"<<endl;
		};
		virtual String toString();
		virtual void ready_check();
		virtual void process(Employee &E){
			E.workOn(*this);
		};
		virtual Object* clone(){
			PrivateCompartment *cln = new PrivateCompartment();
			cln->setID(getID());
			return cln;
		};
		virtual void dstr_clone(){
			delete this;
		};
};

class EquipmentCompartment : public PrivateCompartment{
	public:
		EquipmentCompartment(){
			cout<<"Equipment Compartment just created!"<<endl;
		};
		~EquipmentCompartment(){
			cout<<"EquipmentCompartment to be destroyed!"<<endl;
		};
		String toString();
		void ready_check();
		void process(Employee &E){
			E.workOn(*this);
		};
		Object* clone(){
			EquipmentCompartment *cln = new EquipmentCompartment();
			cln->setID(getID());
			return cln;
		};
		void dstr_clone(){
			delete this;
		};
};

class CargoBay : public PrivateCompartment{
	private:
		EquipmentCompartment *internalEqComp;
	public:
		CargoBay();
		~CargoBay();
		String toString();
		void ready_check();
		void process(Employee &E){
			E.workOn(*this);
		};
		Object* clone(){
			CargoBay *cln = new CargoBay();
			delete cln->internalEqComp;
			cln->internalEqComp = (EquipmentCompartment *)internalEqComp->clone();
			cln->setID(getID());
			return cln;
		};
		void dstr_clone(){
			delete this;
		};
};

class Plane : public Object{
	private:
		string title;
		int capacity;
		CargoBay *cargoComp;
		EquipmentCompartment *equipComps[3];
		PassengerCompartment **passComps;
	public:
		Plane(string, int);
		~Plane();
		String toString();
		void ready_check();
		void process(SecurityEmployee &E){
			cargoComp->process(E);
			for(int i=0;i<3;i++)
				equipComps[i]->process(E);
			for(int i=0;passComps[i]!=NULL;i++)
				passComps[i]->process(E);
		};
		void process(MaintenanceEmployee &E){
			cargoComp->process(E);
			for(int i=0;i<3;i++)
				equipComps[i]->process(E);
		};
		void process(CleaningEmployee &E){
			cargoComp->process(E);
			for(int i=0;passComps[i]!=NULL;i++)
				passComps[i]->process(E);
		};
		string getTitle(){
			return title;
		};
		int getCapacity(){
			return capacity;
		};
		Object* clone();
		void dstr_clone(){
			delete this;
		};
};


void clone_encrypt_and_print(Object& );
void start();