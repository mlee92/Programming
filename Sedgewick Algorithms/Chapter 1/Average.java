// Print out average of sequence of integers 

import java.util.Scanner; 

class Average{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int sum = 0;
		int n = 0; 
		
		while(sc.hasNextInt()){
			sum += sc.nextInt(); 
			n ++; 
		}
		double avg = sum / n ;
		System.out.format("%.2f \n", avg);
	}
}