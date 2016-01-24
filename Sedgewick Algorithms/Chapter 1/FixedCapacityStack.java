 /* 
 
 The instance variables are an array a[] that holds the items in
the stack and an integer N that counts the number of items in the stack. To remove an
item, we decrement N and then return a[N]; to insert a new item, we set a[N] equal to
the new item and then increment N. These operations preserve the following properties:
The items in the array are in their insertion order.
The stack is empty when N is 0.
The top of the stack (if it is nonempty) is at a[N-1].

*/

class FixedCapacityStack{
	public String[] data; 
	public int N; 
	
	public Stack(int cap){
		data = new String[cap};
	}
	
	public boolean isEmpty() { return N == 0; }
	public int size() { 
		return N; 
	}
	public String peek(){
		return data[N]; 
	}
	public void push(String item)
	{ 
		a[N++] = item; 
	}
	public String pop()
	{ 
		return a[--N]; 
	}
	public boolean isFull(){
		return N == data.length; 
	}
}