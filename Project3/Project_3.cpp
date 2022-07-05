#include "objects.h"

using namespace std;

int main(){
	start();
	Plane airplane("Bla Airways",350);
	SecurityEmployee secE("Ben");
	MaintenanceEmployee mE("Billy");
	CleaningEmployee clE("Sebastian");
	airplane.process(secE);
	airplane.process(mE);
	airplane.process(clE);
	secE.report();
	mE.report();
	clE.report();
	airplane.ready_check();
	cout<<"Plane ready to take off"<<endl;
	clone_encrypt_and_print(airplane);
	return 0;
}