import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;


public class MazeData {

    public static final char ROAD = ' ';                    // ·�� ������
    public static final char WALL = '#';                    // ǽ�� ������

    private int entranceX, entranceY;                       // �Թ���� (entranceX, entranceY)
    private int exitX, exitY;                               // �Թ����� (exitX, exitY)

    private int N, M;                                       // N���Թ�����   M���Թ�����
    private char[][] maze;                                  // �����Թ�
    public boolean[][] visited;                             // ��������
    public boolean[][] path;                                // ̽��ʱ�洢·��
    public boolean[][] result;                              // ���ջ������·��

    // �� maze_101_101.txt �ж�ȡ�Թ�
    public MazeData(String filename){
        // �ļ�������
        if(filename == null)
            throw new IllegalArgumentException("Filename can not be null!");

        Scanner scanner = null;
        try{
            File file = new File(filename);
            if(!file.exists())
                throw new IllegalArgumentException("File " + filename + " doesn't exist");

            FileInputStream fis = new FileInputStream(file);
            scanner = new Scanner(new BufferedInputStream(fis), "UTF-8");

            // ��ȡ��һ��  �õ��Թ�  ����  ����
            String nmline = scanner.nextLine();
            String[] nm = nmline.trim().split("\\s+");

            N = Integer.parseInt(nm[0]);
            M = Integer.parseInt(nm[1]);

            maze = new char[N][M];
            visited = new boolean[N][M];
            path = new boolean[N][M];
            result = new boolean[N][M];

            // ��ȡ������N��
            for(int i = 0 ; i < N ; i ++){
                String line = scanner.nextLine();
                // ÿ�б�֤��M���ַ�
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

    // ��ȡ ��Ӧ(x,y)�Թ�������
    public char getMaze(int i, int j){
        if(!inArea(i,j))
            throw new IllegalArgumentException("i or j is out of index in getMaze!");
        return maze[i][j];
    }

    // �ж� (x,y) �Ƿ����Թ���
    public boolean inArea(int x, int y){
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    // ���Եķ��� �����Ƿ���ȷ�Ĵ��ı��ж����Թ�
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