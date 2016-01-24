
import java.util.Random;

class Experiments{
	public static void main(String[] args){
		dice_trial(500);
	}

	public static double dice_distribution(int sum){
		int SIDES = 6; 
		double[] dist = new double[2 * SIDES + 1];
		for(int i  = 1; i <= SIDES; i++){
			for(int j = 1; j <= SIDES; j++){
				dist[i + j] += 1.0;
			}
		}
		
		for(int k = 2; k <= 2*SIDES; k++){
			dist[k] /= 36.00;
		}
		
		return dist[sum]; 
	}
	
	public static void dice_trial(int N){
		Random ran = new Random();
		double[] dist = new double[2 * 6 + 1];
		for(int i = 0; i < N; i++){
			int side1 = ran.nextInt(6) + 1;
			int side2 = ran.nextInt(6) + 1;
			System.out.println(side1 + ", " + side2);
			dist[side1 + side2] += 1.0; 
		}
		
		for(int i = 1; i < 2*6; i++){
			dist[i] /= N; 
			double expected = dice_distribution(i); 
			System.out.println("Sum = " + i + ", Expected = " + expected + ", Trial = " + dist[i]); 
		}
	}
	
	
}