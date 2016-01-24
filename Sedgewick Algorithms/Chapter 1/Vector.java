import java.util.Arrays;

class Vector{
	private int dim;
	private double[] data;
	
	public Vector(int d, double[] _data){
		dim = d; 
		data = Arrays.copyOf(_data, _data.length);
	}
	
	public int getDimension(){
		return dim; 
	}
	
	public double getVectorData(int i){
		return data[i];
	}
	
	public double magnitude(){
		int sum = 0;
		for(int i = 0; i < dim; i++){
			sum += data * data;
		}
		return Math.sqrt(sum);
	}
	
	public double dotProduct(Vector v1, Vector v2){
		double sum = 0; 
		for(int i = 0; i < dim; i++){
			sum += v1.getVectorData(i)) * v2.getVectorData(i); 
		}
		return sum; 
	}
}