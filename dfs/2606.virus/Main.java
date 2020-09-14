
import java.util.*;

class DFS{
    private int com;
    private int adj[][];
    private boolean virus[];

    public DFS(int com) {
        // init
        this.com=com;
        this.adj=new int[this.com+2][this.com+2];
        this.virus=new boolean[this.com+2];

    }

    public void put(int x,int y) {
        this.adj[x][y]=this.adj[y][x]=1;
    }

    public void initvirus(int com) {
        for(int i = 1;i<=com;i++) {
            this.virus[i]=false;
        }

        this.virus[1]=true;

    }
    public boolean isInfected(int com) {
        if(this.virus[com]==true) {
            return true;
        }
        else if(this.virus[com]==false) {
            return false;
        }
        else {
            return false;
        }
    }
    public void doInfect(int index) {
        for(int i=1;i<=this.com;i++) {
            if(this.adj[index][i]==1) {
                //예시로 , 1번 컴퓨터와 i 컴퓨터가 연결된 상태라면?
                // i번 컴퓨터를 감염
                //index번 컴퓨터가 모든컴퓨터와의 연결관계를 탐색

                this.virus[i]=true;
            }
        }
    }

}

public class Main {
    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);
        int com = sc.nextInt();
        int node = sc.nextInt();
        int i=0;
        int nodex=0;
        int nodey=0;
        DFS dfs=new DFS(com);//생성자

        int answer=0;

        if(com>1 && node>0) {
            // 양방향 노드
            for(i=0;i<node;i++) {
                nodex=sc.nextInt();
                nodey=sc.nextInt();
                dfs.put(nodex, nodey);

            }
            //virus 초기화(1번 컴퓨터만 감염으로)
            dfs.initvirus(com);
            // 감염

            for(i=1;i<=com;i++) {
                if(dfs.isInfected(i)==true) {

                    dfs.doInfect(i);

                }

            }

            //감염된 컴퓨터 출력

            for(i=2;i<=com;i++) {

                if(dfs.isInfected(i)) {
                    answer++;
                }
            }

            System.out.println(answer);

        }
        else if(com<2||node==0) {
            System.out.println(0);
        }

        sc.close();

    }
}


