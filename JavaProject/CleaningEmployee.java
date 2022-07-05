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
public class CleaningEmployee extends Employee{
    public CleaningEmployee(String n){
        super(n);
        System.out.println("CleaningEmployee just created!");
    }
    @Override
    public void workOn(PlaneComponent station){
	System.out.println("Cleaning Employee:"+this.getName()+" is working on "+station.toString());
    }
    @Override
    public void report(){
	System.out.println("Cleaning my compartment");
    }
}
