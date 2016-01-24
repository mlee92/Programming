import java.util.*; 

/* 
The binary search algorithm begins by comparing the target value to the value of the middle element of the sorted array. If the target value is equal to the middle element's value, then the position is returned and the search is finished. If the target value is less than the middle element's value, then the search continues on the lower half of the array; or if the target value is greater than the middle element's value, then the search continues on the upper half of the array. This process continues, eliminating half of the elements, and comparing the target value to the value of the middle element of the remaining elements - until the target value is either found (and its associated element position is returned), or until the entire array has been searched (and "not found" is returned).
*/

class BinarySearch{
	public static int rank(int src, int[] a){
		int min = 0;
		int max = a.length - 1; 
		while(min <= max){
			int mid = min + (max - min) / 2; 
			if(src < a[mid])
				max = mid - 1; 
			else if(src > a[mid])
				min = mid + 1; 
			else 
				return mid; 
		}
		
		return -1; 
	}
	
   public static int recursiveRank(int x, int[ ] a, int low, int high) {
      if (low > high) return -1;
	  System.out.println(low + ", " + high);
      int mid = (low + high)/2;
      if (a[mid] == x) return mid;
      else if (a[mid] < x)
         return recursiveRank(x, a, mid+1, high);
      else 
         return recursiveRank(x, a, low, mid-1);
   }
	
	public static int bruteForceSearch(int x, int[] a){
	    int index = -1;
		for(int i  = 0; i < a.length; i++){
			if(x == a[i])
				index = i; 
				break;
		}
		return index;
	}
	
	public static void main(String[] args){
		int[] arr = {0, 2, 3, 5, 7, 9}; 
		int tar = 2; 
		
		int pos = rank(tar, arr);
		int pos2 = recursiveRank(tar, arr, 0, arr.length - 1); 
		
		System.out.println(tar + " is in position " + pos); 
		System.out.println(tar + " is in position " + pos2); 
	}
	
}