import java.util.Scanner;

public class QuickSort{

    static int n;

    static int partition(int[] num, int st, int en){
    boolean turn = true;
    while(st<en){
        if(num[st]<=num[en]) {
            if(turn)
                en --;
            else
                st++;
            }   
        
        else{
            int temp = num[st];
            num[st] = num[en];
            num[en] = temp;
            turn ^= true;
        }
    }
    return st;
    }

    static void Quick_Sort(int[] num, int st, int en){
        if(st >= en) return;
        int p = partition(num,st,en);
        Quick_Sort(num,st,p-1);
        Quick_Sort(num,p+1,en);
    }


    public static void main(String[] args) {
    int num[] = new int[1000];
    Scanner input = new Scanner(System.in);
    n = input.nextInt();

    for(int i=0; i<n; i++){
        int a;
        a = input.nextInt();
        num[i] = a;
    }
    Quick_Sort(num,0,n-1);

    for (int i=0;i<n;i++)
        System.out.print(num[i]+" ");
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