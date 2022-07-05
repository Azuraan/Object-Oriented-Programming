/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrithAskhsh;
import java.util.Random;

public class Plane {
    private String title;
    private int capacity;
    private CargoBay cargoComp;
    private EquipmentCompartment[] equipComps;
    private PassengerCompartment[] passComps;
    
    public Plane(String t,int p){
	title=t;
	capacity=p;
	cargoComp = new CargoBay();
        equipComps = new EquipmentCompartment[3];
	for(int i=0;i<3;i++)
		equipComps[i] = new EquipmentCompartment();
        Random rand = new Random();
	int numb = rand.nextInt(capacity);
	numb = numb%4 +2;
	passComps = new PassengerCompartment[numb+1];
	for(int i=0;i<numb;i++)
		passComps[i] = new PassengerCompartment();
	passComps[numb]=null;
	System.out.println("Plane just created!");
    }
    
    public String toString(){
	String description = "Plane :";
	description = description.concat(title);
	description.concat(" with capacity:" + Integer.toString(capacity));
	for(int i=0;passComps[i]!=null;i++)
		description.concat("\n"+ passComps[i].toString());
	for(int i=0;i<3;i++)
		description.concat("\n"+ equipComps[i].toString());
	description.concat("\n" + cargoComp.toString());
	return description;
    }
    
    public void ready_check(){
	System.out.println(this.toString());
	cargoComp.ready_check();
	for(int i=0;i<3;i++)
		equipComps[i].ready_check();
	for(int i=0;passComps[i]!=null;i++)
		passComps[i].ready_check();
	System.out.println("Plane OK!");
    }
    
    void process(SecurityEmployee E){
            cargoComp.process(E);
            for(int i=0;i<3;i++)
                    equipComps[i].process(E);
            for(int i=0;passComps[i]!=null;i++)
                    passComps[i].process(E);
    }
    
    void process(MaintenanceEmployee E){
            cargoComp.process(E);
            for(int i=0;i<3;i++)
                    equipComps[i].process(E);
    }
    
    void process(CleaningEmployee E){
            cargoComp.process(E);
            for(int i=0;passComps[i]!=null;i++)
                    passComps[i].process(E);
    }
    
    String getTitle(){
        return title;
    }
    
    int getCapacity(){
        return capacity;
    }
}
