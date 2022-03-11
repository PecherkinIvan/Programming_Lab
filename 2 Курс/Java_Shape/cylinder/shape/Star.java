package cylinder.shape;

import cylinder.shape.figure.Figure;

public class Star implements Figure {

    private double d;

    private Star(double new_d, boolean x) {

        d = new_d;
    
    }

    public Star(double new_d) throws Exception {

        if( new_d > 0){
            d = new_d;
        }
        else throw new Exception("Ќеверное значение длинны основани€ луча!");

    }

    public double calc_square() {
        
        double AreaPentagon = (5 * d * d) / (4 * Math.tan(Math.PI/5) );  
       
        double c = ( 1+Math.sqrt(5) )/2 * d;           

        double p = (d+c+c) / 2;  

        double AreaTriangle = Math.sqrt( p * (p-c)*(p-c)*(p-d) ); 

        return AreaPentagon + AreaTriangle * 5;

    }
    public Figure clone() {
        
        return new Star(d, true);
    }

}