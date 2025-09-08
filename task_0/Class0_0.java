package task_0;

import java.util.*;
import java.io.*;

public class Class0_0 {
    public static void main(String[] args) throws IOException{
        Scanner scan = new Scanner(new FileReader("input.txt"));
        PrintWriter writer = new PrintWriter(new FileWriter("output.txt"));
        Set<Long> num = new HashSet<>();

        while(scan.hasNextLong()){
            num.add(scan.nextLong());
        }
        scan.close();

        Long[] arr = num.toArray(new Long[0]);

        long sum = 0;
        for(int i = 0; i < arr.length; i++){
            sum += arr[i];
        }

        writer.println(sum);
        writer.flush();
    }

}
