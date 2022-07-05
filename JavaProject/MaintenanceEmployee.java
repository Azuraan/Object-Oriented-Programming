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
public class MaintenanceEmployee extends Employee{
    public MaintenanceEmployee(String n){
        super(n);
        System.out.println("MaintenanceEmployee just created!");
    }
    @Override
    public void workOn(PlaneComponent station){
	System.out.println("Maintenance Employee:"+this.getName()+" is working on "+station.toString());
    }
    @Override
    public void report(){
	System.out.println("Keeping everything working smoothly and taking good care of the equipment and the cargo");
    }
}
