import java.util.Scanner;

public class MergeSort{

    static int n;
    static void Merge(int[] num,int st, int mid, int en) {

        int copy[] = new int[100000];
        for (int i = 0; i < n; i++) {
            copy[i] = num[i];
        }

        int first_len = mid-st+1;       //first partition len
        int second_len = en - mid;      //second partition len
        int i=0, j=0,cur=st;

        //comparing both partition
        while(i<first_len && j<second_len)
        {
            if(copy[st+i] <= copy[mid+1+j])
                num[cur++] = copy[st+i++];

            else
                num[cur++] = copy[mid+1+j++];
        }

        //for leftovers
        while(i<first_len)
            num[cur++]=copy[st+i++];

        while(j<second_len)
            num[cur++]=copy[mid+1+j++];
    }

    static void Merge_Sort(int[] num, int st, int en) {
        if(st >= en) return;
        int mid = (st+en)/2;        
        Merge_Sort(num, st, mid);       //partition 1   
        Merge_Sort(num, mid+1, en);     //partition 2
        Merge(num, st, mid, en);        //merge partition 1&2
    }

    public static void main(String[] args) {
        int num[] = new int[100000];
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        for(int i=0; i<n; i++){
            int a;
            a = input.nextInt();
            num[i] = a;
        }
        Merge_Sort(num,0,n-1);

        for (int i=0;i<n;i++) {
            System.out.print(num[i]+" ");
        }
        input.close();
    }
}

/*
5 
4 0 9 -2 1
*/
/*
-2 0 1 4 9
*/