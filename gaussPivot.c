//Naive-Gauss elimination method to calculate solutions of system of equations.


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
  int n;
  printf("Enter the no.of total equation:");
  scanf("%d",&n);

 int i,j,k;
 float a[10][10];
 printf("Enter the coefficient of agumented matrix(row_wise):\n");
 for(i=0;i<n;i++)
     { for(j=0;j<n+1;j++)
          {printf("a[%d][%d]=",i+1,j+1);
          scanf("%f",&a[i][j]);
           }
       }


//uppertriangular matrix with partial pivoting
      
       for(k=0;k<n-1;k++)
           
         {
            for(i=k+1;i<n;i++)
               {  if(abs(a[i][k])>abs(a[k][k]))
                        {
                           for(j=0;j<=n;j++)
                               {
                                 float temp=a[k][j];
                                  a[k][j]=a[i][j];
                                  a[i][j]=temp;
                               }
                        }
                
                  float factor=a[i][k]/a[k][k];
                  {
                      for(j=0;j<=n;j++)
                         a[i][j]=a[i][j]-factor*a[k][j];
                  }
                  
                }
          }

   
    

      printf("The uppertriangular matrix is:\n");
      for(i=0;i<n;i++)
          {
             for(j=0;j<=n;j++)
                printf(" %0.2f ",a[i][j]);
             printf(" \n ");

          }

//back substitutions;

      float x[10]={0,0,0,0,0,0,0,0,0,0};
 
     
         for(i=n-1;i>=0;i--)

             {   x[i]=a[i][n];
                 for(j=0;j<n;j++)
                     if(i!=j)
                        {

                          x[i]=x[i]-a[i][j]*x[j];
                          }
                x[i]=x[i]/a[i][i];
              }
  //print solution
   printf("\n\nThe solution of above equations are as follows:\n");
   for(i=0;i<n;i++)
          {
           printf("x%d->%0.2f",i+1,x[i]);
           printf("\n\n");
       
          }
}
