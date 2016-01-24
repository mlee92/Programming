
class Rational{
	public int numerator;
	public int denominator;
	
	public Rational(int num, int den){
		numerator = num;
		denominator = den;
	}
	
	
	public String toString(){
	    return "" + numerator + "/" + denominator;
	}
	public Rational add(Rational b){
		return new Rational(numerator * b.denominator + denominator * b.numerator, denominator * b.denominator);
	}
	
	public Rational subtract(Rational b){
		return new Rational(numerator * b.denominator - denominator * b.numerator, denominator * b.denominator);
	}
	
	
	public Rational multiply(Rational b){
		return new Rational(numerator * b.numerator, denominator * b.denominator);
	}
	
	
	public Rational divide(Rational b){
		return new Rational(numerator * b.denominator, denominator * b.numerator);
	}
	
	public static void main(String[] args){
	    Rational p = new Rational(3, 4);
	    Rational q = new Rational(2, 3);
	    
	    System.out.println(p.add(q).toString());
	    System.out.println(p.subtract(q).toString());
	  
	    System.out.println(p.multiply(q).toString());
	    System.out.println(p.divide(q).toString());	
	    
	}
}