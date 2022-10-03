import java.util.*;
class JumpSearchAlgorithm {

  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter the size of array:" );
    int n=sc.nextInt();
    int[] arr = new int[n];
    System.out.println("Enter the elements of array:" );
    for(int i=0;i<n;i++)
    {
        arr[i]=sc.nextInt();
    }
    System.out.println("Enter the element to be searched:" );
    int ele = sc.nextInt();

    int foundIndex = jumpSearch(arr, ele);
    System.out.println(foundIndex > 0 ? "Found at index : " + foundIndex : "Element Not Found");
  }

  public static int jumpSearch(int[] arr, int ele) {

    int prev = 0;
    int n = arr.length;
    int step = (int) Math.floor(Math.sqrt(n));

    //loop until current element is less than the given search element
    while (arr[Math.min(step, n) - 1] < ele) {
      prev = step;
      step += (int) Math.floor(Math.sqrt(n));
      if (prev >= n) return -1;
    }

    //perform linear search prev index element to given element
    while (arr[prev] < ele) {
      prev++;
      if (prev == Math.min(step, n)) return -1;
    }

    // Return index if element is found
    if (arr[prev] == ele) return prev;

    return -1;
  }
}