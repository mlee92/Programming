
class EuclidGCD{
	
	public static void main(String[] args){
		System.out.println(compute_gcd(25, 30));
	}
	
	public static int compute_gcd(int p, int q) {
        if (q == 0) return p;
        else return gcd(q, p - (p / q) * q);
    }

}