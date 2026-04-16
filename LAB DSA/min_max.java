public class min_max {
    static int minmax(int arr[],int start, int end, boolean isMax){
        if(start==end){
            return arr[start];
        }
        //divide
        int mid=(start+end)/2;
        //conquerr
        int left=minmax(arr, start, end, !isMax);
        int right=minmax(arr, mid+1, end, !isMax);
        //combine
        if(isMax){
            if(left>right)
                return left;
            
            else
                return right;
        }
            else
                if(left<right)
                    return left;
                else
                    return right;
            }

       
    public static void main(String[] args) {
        int arr[]={3,2,5,9};
        int result=minmax(arr, 0, arr.length-1,true);
        System.out.println("answer:- "+result);
    }}