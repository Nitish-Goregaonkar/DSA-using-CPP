public class BinarySearch{
    static int search(int a[],int i, int j , int key){
        int mid=0;
        if(i<=j){
         mid=(i+j)/2;}
        if(a[mid]==key){
            return mid;
        }else if(a[mid]<key){
          return  search(a, mid+1, j, key);
        }
        else if(a[mid]>key){
             return search(a, mid-1, i, key);
        }
        return -1;
    }



public static void main(String[] args) {
    int arr[]={1,5,9,11,16,20};
    search(arr,0,5,20);
    System.out.println("index is "+search(arr, 0, 5, 20));
}

}

