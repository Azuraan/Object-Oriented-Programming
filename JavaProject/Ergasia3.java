
package TrithAskhsh;


public class Ergasia3 {

    public static void main(String[] args) {
	Plane airplane = new Plane("Bla Airways",350);
	SecurityEmployee secE = new SecurityEmployee("Ben");
	MaintenanceEmployee mE = new MaintenanceEmployee("Billy");
	CleaningEmployee clE = new CleaningEmployee("Sebastian");
	airplane.process(secE);
	airplane.process(mE);
	airplane.process(clE);
	secE.report();
	mE.report();
	clE.report();
	airplane.ready_check();
	System.out.println("Plane ready to take off");
    }
}
