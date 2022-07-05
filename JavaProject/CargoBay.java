/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrithAskhsh;

public class CargoBay extends PrivateCompartment{
    private EquipmentCompartment internalEqComp;
    public CargoBay(){
        internalEqComp = new EquipmentCompartment();
        System.out.println("Cargo Bay just created!");
    }
    @Override
    public String toString(){
	String description = "Plane Component:";
	description =description.concat("Private Compartment, ");
        description =description.concat("Cargo Bay with internal Equipment Compartment");
	return description;
    }
    @Override
    public void ready_check(){
	System.out.println(this.toString());
        internalEqComp.ready_check();
	System.out.println("Cargo Bay OK!");
    }
    @Override
    public void process(Employee E){
	E.workOn(this);
    }
}
