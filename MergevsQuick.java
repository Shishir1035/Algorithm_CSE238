import java.time.*;
import java.util.Random;

public class MergevsQuick{
    public static void main(String[] args) {
        QuickSort qsort = new QuickSort();
        MergeSort msort = new MergeSort();

        int i = 0;
        int [] num = new int[10000];
        long mtime=0, qtime=0;

        while (i++<=1000) {
            for (int j = 0; j < 1000; j++) {
                num[i] = (int)(Math.random()*1000);
            }
            long s = System.currentTimeMillis();
            qsort.Quick_Sort(num,0,1000-1);
            long e = System.currentTimeMillis();
            qtime += (e-s);
            
            s = System.currentTimeMillis();
            msort.Merge_Sort(num,0,1000-1);
            e = System.currentTimeMillis();
            mtime += (e-s);
        }
        
        System.out.println("Time taken  for quicksort = "+qtime+" miliseconds");
        System.out.println("Time taken  for mergesort = "+mtime+" miliseconds");
    }
}

/**

Time taken  for quicksort = 1358 miliseconds
Time taken  for mergesort = 38350 miliseconds

*/
