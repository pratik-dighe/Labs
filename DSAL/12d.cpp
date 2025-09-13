Package com.journaldev.ds;
public class MergeSort {
public static void main(String[] args) {
Int[] arr = { 70, 50, 30, 10, 20, 40, 60 };
Int[] merged = mergeSort(arr, 0, arr.length - 1);
For (int val : merged) {
System.out.print(val + "");
}
}
Public static int[] mergeTwoSortedArrays(int[] one, int[] two) {

Int[] sorted = new int[one.length + two.length];

Int I = 0;

Int j = 0;

Int k = 0;

While (I < one.length && j < two.length) 
{

If (one[i] < two[j]) {

Sorted[k] = one[i];

K++;

I++;

} else {

Sorted[k] = two[j];

K++;

J++;

}

}

If (I == one.length) {

While (j < two.length) {

Sorted[k] = two[j];

K++;

J++;

}

}

If (j == two.length) {

While (I < one.length) {

Sorted[k] = one[i];

K++;

I++;

}
}
Return sorted;
}

Public static int[] mergeSort(int[] arr, int lo, int hi) {

If (lo == hi) {

Int[] br = new int[1];

Br[0] = arr[lo];

Return br;

}

Int mid = (lo + hi) / 2;

Int[] fh = mergeSort(arr, lo, mid);

Int[] sh = mergeSort(arr, mid + 1, hi);

Int[] merged = mergeTwoSortedArrays(fh, sh);

Return merged;

}

}

