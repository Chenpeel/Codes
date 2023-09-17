public class RetuArr {
    public static void main(String[] args) {
        
        int[] arr1={1,2,3,4,5,6};
        int[] arr2={2,4,6,8,9};

        for (int i : getCommparedArr(arr1, arr2)) {
            if(i!=0) System.out.println(i);            
        }
    }


    public static int[] getCommparedArr(int[] arr1,int[] arr2){
        int arr3[] =  new int[arr1.length];
        int k = 0;
        
        for(int ai :arr1){
            for(int aj : arr2){
                if(ai==aj){
                    arr3[k]=ai;
                    k++;
                }
            }
        }
        return arr3;
    }

}
