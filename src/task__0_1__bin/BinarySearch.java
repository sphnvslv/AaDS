package task__0_1__bin;

import java.io.*;
import java.util.StringTokenizer;

public class BinarySearch {

    public static int lowerInd(int[] arr, int x) {
        if (arr.length == 0)
            return 0;

        int leftLim = -1;
        int rightLim = arr.length;

        while (rightLim - leftLim > 1) {
            int mid = leftLim + (rightLim - leftLim) / 2;
            if (arr[mid] < x) {
                leftLim = mid;
            } else {
                rightLim = mid;
            }
        }
        return rightLim;
    }

    public static int upperInd(int[] arr, int x) {
        if (arr.length == 0)
            return 0;

        int leftLim = -1;
        int rightLim = arr.length;

        while (rightLim - leftLim > 1) {
            int mid = leftLim + (rightLim - leftLim) / 2;
            if (arr[mid] <= x) {
                leftLim = mid;
            } else {
                rightLim = mid;
            }
        }
        return rightLim;
    }

    public static int safeParseInt(String st) {
        if (st == null)
            return 0;
        try {
            return Integer.parseInt(st.trim());
        } catch (NumberFormatException e) {
            return 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter write = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = 0;
        String line = read.readLine();
        if (line != null) {
            n = safeParseInt(line);
        }

        int[] arr = new int[n];

        if (n > 0) {
            line = read.readLine();
            if (line != null) {
                StringTokenizer st = new StringTokenizer(line);
                for (int i = 0; i < n; i++) {
                    if (st.hasMoreTokens()) {
                        arr[i] = safeParseInt(st.nextToken());
                    }
                }
            }
        }

        int k = 0;
        line = read.readLine();
        if (line != null) {
            k = safeParseInt(line);
        }

        int[] request = new int[k];

        if (k > 0) {
            line = read.readLine();
            if (line != null) {
                StringTokenizer st = new StringTokenizer(line);
                for (int i = 0; i < k; i++) {
                    if (st.hasMoreTokens()) {
                        request[i] = safeParseInt(st.nextToken());
                    }
                }
            }
        }

        for (int i = 0; i < k; i++) {
            int x = request[i];
            int l = lowerInd(arr, x);
            int r = upperInd(arr, x);

            boolean exist = (l < n && arr[l] == x);
            int b = exist ? 1 : 0;

            write.write(b + " " + l + " " + r);
            write.newLine();
        }

        write.flush();
    }
}