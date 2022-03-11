package client;

import cylinder.shape.figure.Figure;
import cylinder.shape.Star;
import cylinder.shape.Circle;

public class MAIN {
    public static void main(String[] arg) {
        
        try
        {
            Figure c = new Circle(1);
            cylinder.Cylinder cyl = new cylinder.Cylinder(2, c);

            System.out.println(c.calc_square());
            System.out.println(cyl.calcValume());
        }
        catch(Exception e)
        {
            System.out.println( e.getMessage() );
        }
        
    }
}

