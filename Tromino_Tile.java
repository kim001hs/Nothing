import java.io.IOException;
import java.util.Scanner;

public class Main{
    static int[][] arr;
    static int num=0;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        //k를 받아 n을 2의 k제곰으로 둔다
        int k=sc.nextInt();
        int n=1;
        for(int i=0;i<k;i++){
            n*=2;
        }

        arr = new int[n+1][n+1];
        //y와x를 받는다
        int x=sc.nextInt();
        int y=sc.nextInt();
        //빈칸에 -1을 넣는다
        arr[y][x]=-1;
        //재귀함수를 돌린다
        solve(1,1,n);
        //출력
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void solve(int y, int x, int size){
        num++;
        //half_size를 만들고 4등분을 한다
        int half_size=size/2;
        //4등분중 빈칸이 있는칸을 제외한 세칸이 인접하는 칸에 num을 넣는다
        if(isInside(y, x, half_size))arr[y+half_size-1][x+half_size-1]=num;
        if(isInside(y+half_size, x, half_size))arr[y+half_size][x+half_size-1]=num;
        if(isInside(y, x+half_size, half_size))arr[y+half_size-1][x+half_size]=num;
        if(isInside(y+half_size, x+half_size, half_size))arr[y+half_size][x+half_size]=num;
        //size가 2이면 더이상 나눌수 없으므로 return
        if(size==2)return;
        //다시 4등분을 한다
        solve(y, x, half_size);
        solve(y, x+half_size, half_size);
        solve(y+half_size, x, half_size);
        solve(y+half_size, x+half_size, half_size);

    }
    public static boolean isInside(int y, int x, int size){
        //받은 정사각형에 빈칸이 있다면 false를 반환
        for(int i=y;i<y+size;i++){
            for(int j=x;j<x+size;j++){
                    if(arr[i][j]!=0){
                        return false;
                }
            }
        }
        return true;
    }
}