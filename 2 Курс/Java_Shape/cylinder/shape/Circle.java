package cylinder.shape;

import cylinder.shape.figure.Figure;

public class Circle implements Figure {
    
    private double r;

    private Circle(double new_r, boolean x) {
        
        r = new_r;
    }

    public Circle(double new_r) throws Exception{

        if( new_r > 0) {
            r = new_r;
        }
        else {

            throw new Exception("Неверное значение радиуса!");
        }
    }

    public double calc_square() {

        return r*r * Math.PI;
    }
    
    public Figure clone() {

        return new Circle(r, true);
    }

}