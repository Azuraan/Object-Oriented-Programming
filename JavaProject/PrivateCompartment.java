/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrithAskhsh;

/**
 *
 * @author George
 */
public class PrivateCompartment extends PlaneComponent{
    public PrivateCompartment(){
        System.out.println("Private Compartment just created!");
    }
    @Override
    public String toString(){
	String description = "Plane Component:";
	description =description.concat("Private Compartment");
	return description;
    }
    @Override
    public void ready_check(){
	System.out.println(this.toString());
	System.out.println("Private Compartment OK!");
    }
    @Override
    public void process(Employee E){
	E.workOn(this);
    }
}
