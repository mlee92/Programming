
class Exercises1_2{
	public static void main(String[] args){
		System.out.println(isRotation("ACTGACG", "TGACGAC"));
	}
	
	public static boolean isRotation(String s1,String s2) { // completes the cycle and finds the substring
		return (s1.length() == s2.length()) && ((s1+s1).indexOf(s2) != -1);
	}

}

