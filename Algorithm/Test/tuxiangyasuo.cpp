//
//#include <iostream>
//using namespace std;
//
//const int N = 7;
//
//int length(int i);
//void Compress(int n,int p[],int s[],int l[],int b[]);
//void Tracebace(int n,int& i,int s[],int l[]);
//void Output(int s[],int l[],int b[],int n);
//
//int main()
//{
//    int p[] = {0,10,12,15,255,1,2};//ͼ��Ҷ����� �±��1��ʼ����
//    int s[N],l[N],b[N];
//
//    cout<<"ͼ��ĻҶ�����Ϊ��"<<endl;
//
//    for(int i=1;i<N;i++)
//    {
//        cout<<p[i]<<" ";
//    }
//    cout<<endl;
//
//    Compress(N-1,p,s,l,b);
//    Output(s,l,b,N-1);
//    return 0;
//}
//
//void Compress(int n,int p[],int s[],int l[],int b[])
//{
//    int Lmax = 256,header = 11;
//    s[0] = 0;
//    for(int i=1; i<=n; i++)
//    {
//        b[i] = length(p[i]);//�������ص�p��Ҫ�Ĵ洢λ��
//        int bmax = b[i];
//        s[i] = s[i-1] + bmax;
//        l[i] = 1;
//
//        for(int j=2; j<=i && j<=Lmax;j++)
//        {
//            if(bmax<b[i-j+1])
//            {
//                bmax = b[i-j+1];
//            }
//
//            if(s[i]>s[i-j]+j*bmax)
//            {
//                s[i] = s[i-j] + j*bmax;
//                l[i] = j;
//            }
//        }
//        s[i] += header;
//    }
//}
//
//int length(int i)
//{
//    int k=1;
//    i = i/2;
//    while(i>0)
//    {
//        k++;
//        i=i/2;
//    }
//    return k;
//}
//
//void Traceback(int n,int& i,int s[],int l[])
//{
//    if(n==0)
//        return;
//    Traceback(n-l[n],i,s,l);
//    s[i++]=n-l[n];//����Ϊs[]���鸳ֵ�������洢�ֶ�λ��
//}
//
//void Output(int s[],int l[],int b[],int n)
//{
//    //�����s[n]�洢λ����s[]���������¸�ֵ�������洢�ֶε�λ��
//    cout<<"ͼ��ѹ�������С�ռ�Ϊ��"<<s[n]<<endl;
//    int m = 0;
//    Traceback(n,m,s,l);
//    s[m] = n;
//    cout<<"��ԭ�Ҷ����зֳ�"<<m<<"�����ж�"<<endl;
//    for(int j=1; j<=m; j++)
//    {
//        l[j] = l[s[j]];
//        b[j] = b[s[j]];
//    }
//    for(int j=1; j<=m; j++)
//    {
//        cout<<"�γ��ȣ�"<<l[j]<<",����洢λ��:"<<b[j]<<endl;
//    }
//}