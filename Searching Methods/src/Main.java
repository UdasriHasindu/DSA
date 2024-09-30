public class Main{

    // function for linear search method
    public static int linearSearch(int[] arr, int target){

        int n = arr.length;
        for(int i=0; i<n; i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1; // if target is not found
    }


    public static void main(String[] args) {

        int[] numList = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
        int[] unsortedList = {5, 31, 19, 33, 27, 23, 25, 11, 9, 7, 39, 17, 3, 13, 29, 21, 37, 15, 1, 35};

        int index = linearSearch(numList, 21);
        System.out.println("Target element is at index: " + index);

    }
}