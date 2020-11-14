package bsu;

public class Exponential extends Series {
    public Exponential(double first, double denominator){
        super(first,denominator);
    }
    @Override
    public double countElem(int j) throws IllegalArgumentException {
        if(j<=0)throw new IllegalArgumentException("Error");
        return first*Math.pow(denominator,j-1);
    }
}
