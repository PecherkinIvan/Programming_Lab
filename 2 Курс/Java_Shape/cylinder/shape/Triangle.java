package cylinder.shape;

import cylinder.shape.figure.Figure;

public class Triangle implements Figure {

    private double a,b,c;

    private boolean check(double new_a, double new_b, double new_c) {

        if( new_c < new_a+new_b && new_a < new_b+new_c && new_b < new_c+new_a) {
            return true;
        }
        else {
            return false;
        }
     
    }

    private Triangle(double new_a, double new_b, double new_c, boolean x) {

        a=new_a;
        b=new_b;
        c=new_c;
    }

    public Triangle(double new_a, double new_b, double new_c) throws Exception{

        if( check(new_a,new_b,new_c) )
        {
            a=new_a;
            b=new_b;
            c=new_c;
        }
        else throw new Exception("Значения треугольника неверные!");

    }
    public double calc_square() {

        double p = (a+b+c)/2;   
        return Math.sqrt( p*(p-a)*(p-b)*(p-c) );

    }
    public Figure clone() {
        
        return new Triangle(a, b, c, true);
    }
}