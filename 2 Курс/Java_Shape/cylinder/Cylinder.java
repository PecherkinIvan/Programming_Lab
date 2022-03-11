package cylinder;

import cylinder.shape.figure.Figure;

public class Cylinder {

    private Figure f;
    private double h;

    public Cylinder(double new_h, Figure new_f) throws Exception{

        h = new_h;
        f = new_f.clone();
    }

    public double calcValume() {

        return h * (f.calc_square());
    }
}