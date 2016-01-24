/*   
   Reads in a list of strings and prints them in random order.
   The Knuth (or Fisher-Yates) shuffling algorithm guarantees
   to rearrange the elements in uniformly random order, under
   the assumption that Math.random() generates independent and
   uniformly distributed numbers between 0 and 1.
*/

class KnuthShuffle{
    public static void shuffle(Object[] a) {
        int N = a.length;
        for (int i = 0; i < N; i++) {
            int r = i + (int) (Math.random() * (N - i));
            Object swap = a[r];
            a[r] = a[i];
            a[i] = swap;
        }
    }	
}