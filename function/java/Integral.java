
import  java.util.function.Function;

class Integral {

    public  static  double
    integral(Function<Double, Double> f, double a, double b, double h)
    {
        int n = (int)((b - a) / h);
        double  sum = 0.0;
        double  v1, v2;

        v2 = f.apply(a);
        for ( int i = 1; i < n; ++ i ) {
            v1  = v2;
            v2  = f.apply(a + i * h);
            double  daikei = (v1 + v2) * h / 2.0;
            sum += daikei;
        }
        return ( sum );
    }

    //  積分したい関数。    //
    public  static  double  func1(double x) { return ( x ); }
    public  static  double  func2(double x) {
        return ( Math.cos(x * Math.PI / 2.0) );
    }

    public  static void main(String[] args) {
        System.out.println(integral(Integral::func1, 0, 1, 0.001));
        System.out.println(integral(Integral::func2, 0, 1, 0.001));
    }
}

