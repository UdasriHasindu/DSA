public class Main{

    // linear search method
    public static int linearSearch(int[] arr, int target){

        int n = arr.length;
        for(int i=0; i<n; i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1; // if target is not found
    }

    // binary search method
    public static int binarySearch(int[] arr, int target){
        int n = arr.length;
        int start = 0;
        int end = n-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if (arr[mid] < target) {
                // search right half of the number set
                start = mid + 1;
            }
            else {
                // search the left half of the number set
                end = mid - 1;
            }
        }
        return -1;
    }



    public static void main(String[] args) {

        int[] numList = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
        int[] unsortedList = {5, 31, 19, 33, 27, 23, 25, 11, 9, 7, 39, 17, 3, 13, 29, 21, 37, 15, 1, 35};

        int index1 = linearSearch(numList, 33);
        System.out.println("Target element is at index: " + index1);

        int index2 = binarySearch(numList, 33);
        System.out.println("Target element is at index: " + index2);

    }
}