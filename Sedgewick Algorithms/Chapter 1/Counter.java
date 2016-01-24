
class Counter{
	String name;
	int count; 
	
	public Counter(String _name){
		name = _name;
	}
	
	public void increment() {
        count++;
    } 
	
	public int getCount() {
        return count;
    } 
}