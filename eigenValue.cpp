/*
!Lab No:04
! Title :To find Largest eigen value of matrix.
! Date: 29/08/2017
! Name : Bimlesh Kumar
! Roll No:150121011
!Email :k.bimlesh@iitg.ernet.in
*/


#include<stdio.h>
#include<cmath>

int main()
{
  double mat[20][20];
  double evec[20],product[10][10];
  double y,x,eps;
  int i,j,k,n,m=0;
  scanf("%d",&n);//takes size of matrix
  for(i=0;i<n;i++)
         {
           for(j=0;j<n;j++)                    //input of matrix
                   { 
                     scanf("%lf\t",&mat[i][j]);
                     
                   }
           printf("\n");
         } 
  scanf("%lf",&eps);//takes value of epsilon

  //initial eigen vector guess.
  for(i=0;i<n;i++)
         evec[i]=1;
   int count=0;
   double y1=0,eigenvalue=0,vec[10];
     do
       { y1=eigenvalue;
         m++;
         for(i=0;i<n;i++)//eigen vector claculation
                {  vec[i]=0;
                   for(j=0;j<n;j++)
                        {
                          vec[i]=vec[i]+mat[i][j]*evec[j];
                        }
                  
                }
          for(i=0;i<n;i++)
              {
                 
              evec[i]=vec[i];
              }
          
          
          double max;
          max=evec[0];
          for(i=1;i<n;i++)//finding max element from eigen vector;
                {
                  
                  if(fabs(max)<fabs(evec[i]))
                          {
                             max=evec[i];
                           }  
                      
                }
         
          for(i=0;i<n;i++) //reduction of eigen vector to standard form.
                {
                   evec[i]=evec[i]/(max);
                }
           printf("Eigen Vector after %d iteration is:\n",m);
           for(i=0;i<n;i++)
              {
                 printf("\n%0.10lf",evec[i]);
                 printf("\n");
              }
         
          
          eigenvalue=max;
          printf("\neigen value in %d iteration is :%0.10lf",m,eigenvalue);
          printf("\n");    
                
        }while(fabs((y1)-(eigenvalue))>eps);
        printf("\nThe largest eigen value of the given matrix is:: %0.10lf\t\n",eigenvalue);
        
      



 return 0;
 


}
