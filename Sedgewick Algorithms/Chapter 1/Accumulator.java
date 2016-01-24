public class Accumulator
{
	private double total;
	private double s;
	private int N;
	
	public void addDataValue(double val)
	{
		N++;
		total += val;
		s += 1.0*(N - 1)/N * (val-mean()) * (val - mean());
	}
	
	public double mean()
	{
		return total/N; 
	}
	
	public double var(){
		return s / (N - 1);
	}
	
	public double stddev(){
		return Math.sqrt(var());
	}
	
	public String toString()
	{ 
		return "Mean (" + N + " values): " + String.format("%7.5f", mean()); 
	}
}