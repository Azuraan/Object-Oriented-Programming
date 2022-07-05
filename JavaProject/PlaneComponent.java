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
public abstract class PlaneComponent {
    public PlaneComponent(){
        System.out.println("PlaneComponent just created!");
    }
    @Override
    public abstract String toString();
    public abstract void ready_check();
    public abstract void process(Employee E);    
}
