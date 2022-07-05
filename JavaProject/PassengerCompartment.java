/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrithAskhsh;
import java.util.Random;

public class PassengerCompartment extends PlaneComponent{
    private PassengerCompartment internalPasComp;
    public PassengerCompartment(){
        Random rand = new Random();
	if(rand.nextInt(5)<= 3)
		internalPasComp= null;
	else
		internalPasComp = new PassengerCompartment();
	System.out.println("Passenger Compartment just created!");
    }
    @Override
    public String toString(){
	String description = "Plane Component:";
	description =description.concat("Passenger Compartment with ");
	description = description.concat((internalPasComp!=null)? "Internal Compartment" : "No Internal Compartment");
	return description;
    }
    @Override
    public void ready_check(){
	System.out.println(this.toString());
	System.out.println("Passenger Compartment OK!");
	if(internalPasComp!= null)
		internalPasComp.ready_check();
    }
    @Override
    public void process(Employee E){
	E.workOn(this);
    }
}
