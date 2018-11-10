
/*
!Lab No:04
! Title :To find smallest eigen value of matrix.
! Date: 29/08/2017
! Name : Bimlesh Kumar
! Roll No:150121011
!Email :k.bimlesh@iitg.ernet.in
*/

#include<stdio.h>
#include<cmath>
int main()
{
        int size;
        scanf("%d",&size);
        int i=0,j=0,k=0;
        double a[10][10],l[10][10],x[10],y[10],b[10];
        
        double temp=0.0,temp2=0.0,eps;

//taking input of matrix elements
         
        for(i=1;i<=size;i++)
        {
                for(j=1;j<=size;j++)
                {      
                        scanf("%lf\t",&a[i][j]);
                       
                }
               printf("\n");
        }
   
       scanf("%lf",&eps);
//computing upper triangular matrix

        for(k=1; k<=size-1; k++)
          {
                    for(i=k+1; i<=size; i++)
                    {
                              temp = a[i][k]/a[k][k];
                        l[i][k]=temp;
                              for(j=1; j<=size; j++)
                              {
                                a[i][j] = a[i][j] - a[k][j]*temp;
                              }
                    }
          }

//computing lower triangular matrix

        for(k=1;k<=size;k++)
        {
                l[k][k]=1;
        }
       
        



//computing inverse

        double I[size+1][size+1];
        for(i=1;i<=size;i++)
                for(j=1;j<=size;j++)        
        {
        if(i!=j)
                I[i][j]=0;
        else
                I[i][j]=1;
        }

//CODE for front substitution

            double x1[size+1][size+1];
            double y1[size+1];
        for(i=1;i<=size;i++)
            for(k=1;k<=size;k++)
        {
            y1[k]=0;
            for (j=k-1;j>=1;j--)
                {
                    y1[k]+=l[k][j]*x1[j][i];
                }
            x1[k][i]=((I[k][i]-y1[k])/l[k][k]);                

                }
        
        
//CODE for back substitution
            double z1[size+1][size+1];
            double s1[size+1];
    
        for(i=1;i<=size;i++)
            for(k=size;k>=1;k--)
        {
            s1[k]=0;
            for (j=k+1;j<=size;j++)
                {
                    s1[k]+=a[k][j]*z1[j][i];
                }
            z1[k][i]=((I[k][i]-s1[k])/a[k][k]);
        }

        double f[size+1][size+1];
        for(k=1;k<=size;k++)
        for(i=1;i<=size;i++)
           {f[i][k]=0;
                for(j=1;j<=size;j++)
                {
                        f[i][k]+=z1[i][j]*x1[j][k];
                }
           }
//printing inverse
        
        printf("\n INVERSE \n");
        for(i=1;i<=size;i++)
        {
                for(j=1;j<=size;j++)
                {
                        printf("%lf ",f[i][j]);
                }
                printf("\n");
        }

      //computing eigen value.
    double mat[15][15];
    for(i=1;i<=size;i++)
          {
                for(j=1;j<=size;j++)
                {
                   mat[i][j]=f[i][j];//coping inverse matrix.     
                }
                
          }
  
      double y2=0.0,eigenvalue=0.0,vec[10],evec[15];
      for(i=1;i<=size;i++)
         {
            evec[i]=1;
          }
     int m=0;
     do
       { y2=eigenvalue;
         m++;
         for(i=1;i<=size;i++)//eigen vector claculation
                {  vec[i]=0;
                   for(j=1;j<=size;j++)
                        {
                          vec[i]=vec[i]+mat[i][j]*evec[j];
                        }
                  
                }
          for(i=1;i<=size;i++)
              {
                 
              evec[i]=vec[i];
              }
          
          
          double max;
          max=evec[0];
          for(i=1;i<=size;i++)//finding max element from eigen vector;
                {
                  
                  if(fabs(max)<fabs(evec[i]))
                          {
                             max=evec[i];
                           }  
                      
                }
         
          for(i=1;i<=size;i++) //reduction of eigen vector to standard form.
                {
                   evec[i]=evec[i]/(max);
                }
          
         
          
          eigenvalue=max;
          printf("\neigen value in %d iteration is :%0.10lf",m,1/eigenvalue);
          printf("\n");    
                
        }while(fabs((y2)-(eigenvalue))>eps);
        printf("\nThe smallest eigen value of the given matrix is:: %0.10lf\t\n",1/eigenvalue);
        


        return 0;
}
