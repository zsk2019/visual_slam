#include <iostream>
using namespace std;
#include <ctime>
// Eigen 部分
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等）
#include <Eigen/Dense>
using namespace Eigen;

  int main(int argc, char **argv)
  {
    Matrix<float, 10, 10> matrixf_10_10=Matrix<float, 10, 10>::Random();
     Matrix<float,3,3> matrix3_3;
    cout<<"matrixf_10_10= \n"<<matrixf_10_10<<endl;

    int i,j;
    for( i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           matrix3_3(i,j)=matrixf_10_10(i,j);

        }
    }
    cout<<"matrix3_3= \n"<<matrix3_3<<endl;
     Matrix<float,3,1> v;
     v<<1,3,5;
     Matrix<double,3,1> v1;
     Quaterniond q;
     q.x()=1;
     q.y()=2;
     q.z()=3;
     q.w()=0;
     v1=q*(v.cast<double>());
     cout<<"v1= \n"<<v1<<endl;
     //Ax=b   求解
     Matrix3d A;
         A<<1,1,1,
            2,2,2,
            3,3,3;
         Eigen::Matrix<double, 3, 1> b;
         b<<1,2,3;
         cout<<"行列式为："<<A.determinant()<<endl;    //看一下行列式的值是否为０，确保可逆
         cout<<"x="<<A.inverse()*b<<endl;             //直接求逆来解，速度会慢
         cout<<"x="<<A.colPivHouseholderQr().solve(b)<<endl;  //ＱＲ分解，速度快，注意调用格式

         Matrix3d R_cw,R_wc;
         Vector3d  p_w,p_c,p_c2;
         Quaterniond q1={0.2,0.3,0.1,0.35};
         Quaterniond q2={0.4,-0.1,0.2,-0.5};
         Vector3d t1={0.3, 0.1, 0.1};
         cout<<"t1= \n"<<t1<<endl;
         Vector3d t2={-0.1, 0.5, 0.3};
         q1.normalize();
         q2.normalize();
         R_cw=q1.toRotationMatrix();
         cout<<"R_cw= \n"<<R_cw<<endl;
         Isometry3d T1,T2;
         T1=Isometry3d::Identity();
         T2=Isometry3d::Identity();
         T1.rotate(R_cw);
         T1.pretranslate(t1);
         p_c={0.5, 0, 0.2};
         p_w=T1.inverse()*p_c;
         R_wc=q2.toRotationMatrix();
         cout<<"R_wc= \n"<<R_wc<<endl;
         T2.rotate(R_wc);
         T2.pretranslate(t2);
         cout<<"T2= \n"<<T2.matrix()<<endl;
         p_c2=T2*p_w;
         cout<<"p_c2= \n"<<p_c2<<endl;









         return 0;



  }
