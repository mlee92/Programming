/* 

Print N random values in (min, max).

*/

import java.util.Random; 
import java.util.Scanner;

class RandomSeq
{
	public static void main(String[] args)
	{ 
		Random r = new Random(); 
		Scanner sc = new Scanner(System.in); 
		int N = sc.nextInt();
		double min = sc.nextDouble();
		double max = sc.nextDouble(); 
		
		for (int i = 0; i < N; i++){
		    double x = r.nextDouble() * max; 
			while(!inRange(x, min, max)){
                x = r.nextDouble() * max; 		
            }
			System.out.format("%.2f\n", x); // format to .00 precision-float 
		}
	}
	
	public static boolean inRange(double x, double min, double max){
	    if(min <= x && x <= max){
	        return true; 
	    }    else {
	        return false;
	    }
	}
	
}