import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;


public class MazeData {

    public static final char ROAD = ' ';                    // 路： 可以走
    public static final char WALL = '#';                    // 墙： 不能走

    private int entranceX, entranceY;                       // 迷宫入口 (entranceX, entranceY)
    private int exitX, exitY;                               // 迷宫出口 (exitX, exitY)

    private int N, M;                                       // N：迷宫行数   M：迷宫列数
    private char[][] maze;                                  // 创建迷宫
    public boolean[][] visited;                             // 访问数组
    public boolean[][] path;                                // 探测时存储路径
    public boolean[][] result;                              // 存放栈方法的路径

    // 从 maze_101_101.txt 中读取迷宫
    public MazeData(String filename){
        // 文件不存在
        if(filename == null)
            throw new IllegalArgumentException("Filename can not be null!");

        Scanner scanner = null;
        try{
            File file = new File(filename);
            if(!file.exists())
                throw new IllegalArgumentException("File " + filename + " doesn't exist");

            FileInputStream fis = new FileInputStream(file);
            scanner = new Scanner(new BufferedInputStream(fis), "UTF-8");

            // 读取第一行  得到迷宫  行数  列数
            String nmline = scanner.nextLine();
            String[] nm = nmline.trim().split("\\s+");

            N = Integer.parseInt(nm[0]);
            M = Integer.parseInt(nm[1]);

            maze = new char[N][M];
            visited = new boolean[N][M];
            path = new boolean[N][M];
            result = new boolean[N][M];

            // 读取后续的N行
            for(int i = 0 ; i < N ; i ++){
                String line = scanner.nextLine();
                // 每行保证有M个字符
                if(line.length() != M)
                    throw new IllegalArgumentException("Maze file " + filename + " is invalid");
                for(int j = 0 ; j < M ; j ++){
                    maze[i][j] = line.charAt(j);
                    visited[i][j] = false;
                    path[i][j] = false;
                    result[i][j] = false;
                }
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
        finally {
            if(scanner != null)
                scanner.close();
        }
        entranceX = 1;
        entranceY = 0;
        exitX = N - 2;
        exitY = M - 1;
    }

    public int N(){ return N; }
    public int M(){ return M; }
    public int getEntranceX() { return entranceX; }
    public int getEntranceY() { return entranceY; }
    public int getExitX() { return exitX; }
    public int getExitY() { return exitY; }

    // 获取 对应(x,y)迷宫的内容
    public char getMaze(int i, int j){
        if(!inArea(i,j))
            throw new IllegalArgumentException("i or j is out of index in getMaze!");
        return maze[i][j];
    }

    // 判断 (x,y) 是否在迷宫内
    public boolean inArea(int x, int y){
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    // 测试的方法 看看是否正确的从文本中读入迷宫
    public void print(){
        System.out.println(N + " " + M);
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < M ; j ++)
                System.out.print(maze[i][j]);
            System.out.println();
        }
        return;
    }

}