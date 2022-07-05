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
public abstract class Employee {

    private String name;

    public Employee(String n){
        name = n;
    System.out.println("Employee just created!");
    }
    public abstract void workOn(PlaneComponent station);
    public abstract void report();
    public String getName(){
	return name;
    }    
}
