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
public class SecurityEmployee extends Employee {
    public SecurityEmployee(String n){
        super(n);
	System.out.println("SecurityEmployee just created!");
    }
    @Override
    public void workOn(PlaneComponent station){
        /*String wplace = station.toString();
        String identity = this.getName();*/
	System.out.println("Security Employee:"+this.getName()+" is working on "+station.toString());
    }
    @Override
    public void report(){
	System.out.println("Making sure everything is okay and providing a safe trip");
    }
}
