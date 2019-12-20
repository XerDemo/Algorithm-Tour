////3d11-1 ���Ŷ��������� ��̬�滮
//#include <iostream>
//using namespace std;
//
//const int N = 3;
//
//void OptimalBinarySearchTree(double a[],double b[],int n,double **m,int **s,double **w);
//void Traceback(int n,int i,int j,int **s,int f,char ch);
//
//int main()
//{
//    double a[] = {0.15,0.1,0.05,0.05};
//    double b[] = {0.00,0.5,0.1,0.05};
//
//    cout<<"���򼯵ĸ��ʷֲ�Ϊ��"<<endl;
//    for(int i=0; i<N+1; i++)
//    {
//        cout<<"a"<<i<<"="<<a[i]<<",b"<<i<<"="<<b[i]<<endl;
//    }
//
//    double **m = new double *[N+2];
//    int **s = new int *[N+2];
//    double **w =new double *[N+2];
//
//    for(int i=0;i<N+2;i++)
//    {
//        m[i] = new double[N+2];
//        s[i] = new int[N+2];
//        w[i] = new double[N+2];
//    }
//
//    OptimalBinarySearchTree(a,b,N,m,s,w);
//    cout<<"������������Сƽ��·��Ϊ��"<<m[1][N]<<endl;
//    cout<<"��������Ŷ�����Ϊ:"<<endl;
//    Traceback(N,1,N,s,0,'0');
//
//    for(int i=0;i<N+2;i++)
//    {
//        delete m[i];
//        delete s[i];
//        delete w[i];
//    }
//    delete[] m;
//    delete[] s;
//    delete[] w;
//    system("pause");
//    return 0;
//}
//
//void OptimalBinarySearchTree(double a[],double b[],int n,double **m,int **s,double **w)
//{
//    //��ʼ���������ڲ��ڵ�����
//    for(int i=0; i<=n; i++)
//    {
//        w[i+1][i] = a[i];
//        printf("\nw[%d][%d] = %lf", i + 1, i, w[i + 1][i]);
//        m[i+1][i] = 0;
//    }
//
//    for(int r= 1; r<=n; r++)//r������ֹ�±�Ĳ�
//    {
//        for(int i=1; i<=n-r+1; i++)//iΪ��ʼԪ���±�
//        {
//            int j = i+r-1;//jΪ��ֹԪ���±�
//
//            //����T[i][j] ��дw[i][j],m[i][j],s[i][j]
//            //��ѡi��Ϊ������������Ϊ�գ�������Ϊ�ڵ�
//            w[i][j]=w[i][j-1]+a[j]+b[j];
//            m[i][j]=m[i+1][j];
//            s[i][j]=i;
//
//            //��ѡi��Ϊ������kΪ�������k=i+1������j
//            //������Ϊ�ڵ㣺i,i+1����k-1,������Ϊ�ڵ㣺k+1,k+2,����j
//            for(int k=i+1; k<=j; k++)
//            {
//                double t = m[i][k-1]+m[k+1][j];
//
//                if(t<m[i][j])
//                {
//                    m[i][j]=t;
//                    s[i][j]=k;//���ڵ�Ԫ��
//                }
//            }
//            m[i][j]+=w[i][j];
//        }
//    }
//}
//
////C:\Users\XerDemo\Desktop\Algorithm\cmake-build-debug\Algorithm.exe
////        ���򼯵ĸ��ʷֲ�Ϊ��
////a0=0.15,b0=0
////a1=0.1,b1=0.5
////a2=0.05,b2=0.1
////a3=0.05,b3=0.05
////
////w[1][0] = 0.150000
////w[2][1] = 0.100000
////w[3][2] = 0.050000
////w[4][3] = 0.050000������������Сƽ��·��Ϊ��1.5
////��������Ŷ�����Ϊ:
////Root��1 (i:j):(1,3)
////R of 1:2 (i:j):(2,3)
////R of 2:3 (i:j):(3,3)
////�밴���������. . .
//
//void Traceback(int n,int i,int j,int **s,int f,char ch)
//{
//    int k=s[i][j];
//    if(k>0)
//    {
//        if(f==0)
//        {
//            //��
//            cout<<"Root��"<<k<<" (i:j):("<<i<<","<<j<<")"<<endl;
//        }
//        else
//        {
//            //����
//            cout<<ch<<" of "<<f<<":"<<k<<" (i:j):("<<i<<","<<j<<")"<<endl;
//        }
//
//        int t = k-1;
//        if(t>=i && t<=n)
//        {
//            //����������
//            Traceback(n,i,t,s,k,'L');
//        }
//        t=k+1;
//        if(t<=j)
//        {
//            //����������
//            Traceback(n,t,j,s,k,'R');
//        }
//    }
//}