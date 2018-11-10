//Gauss-Jordan method to calculate solutions of system of equations.

#include<stdio.h>

int main()
{
  int n;
  printf("Enter the no.of total equation:");
  scanf("%d",&n);

 int i,j,k;
 float a[10][10];
 printf("\nEnter the coefficient of agumented matrix(row_wise):\n");
 for(i=0;i<n;i++)                                                //input of matrix.
     { for(j=0;j<n+1;j++)
          {printf("a[%d][%d]=",i+1,j+1);
          scanf("%f",&a[i][j]);
           }
      }
   for( k=0; k<n; k++)
        {
       
           for( i=0; i<n ; i++)
            {
            if(i!=k)
            {
                if (a[k][k]==0 && k<n-1)
                {
                    for ( j=k; j<n+1; j++)
                        a[k][j] += a[k+1][j];
                }
                float constant = a[i][k]/a[k][k];
                for (j=k; j<n+1;j++)
                {
                    a[i][j] = a[i][j] - constant * a[k][j];
                }
            }
        }

    }
      /*
       //gauss-jordan calculation
         

    
       for(k=0;k<n-1;k++)
           
         {
            for(i=k+1;i<n;i++)
                {
                  float factor=a[i][k]/a[k][k];
                  {
                      for(j=0;j<=n;j++)
                         a[i][j]=a[i][j]-factor*a[k][j];//upper triange
                  }
                  
                }
          }

    
         for(k=n-1;k>0;k--)
           
         {
            for(i=k-1;i>=0;i--)
                {
                  float factor=a[k][k]/a[i][k];
                  {
                      for(j=k;j<=n;j++)
                         a[i][j]=a[k][j]-a[i][j]*factor;//lower triange
                  }
                  
                }
          }*/
   //main diagonal not in standard form
           printf("The Gauss-Jordan  matrix not in standard form:\n");
      for(i=0;i<n;i++)
          {
             for(j=0;j<=n;j++)
                printf(" %0.2f ",a[i][j]);
             printf(" \n ");

          }


//reduce to standard form
         float m[10];
         for(i=0;i<n;i++)
               {
                  for(j=0;j<n+1;j++)
                         if(i==j)
                            m[i]=a[i][j];
                 }

       for(i=0;i<n;i++)
           {        for(j=0;j<=n;j++)
                    {   if(i==j || j==n)
                       a[i][j]=a[i][j]/a[i][i];//divide
                     }
             }
    
      for(i=0;i<n;i++)
         {
            a[i][n]=a[i][n]/m[i];
           }


//gauss-jordan matrix print
   printf("The Gauss-Jordan  matrix :\n");
      for(i=0;i<n;i++)
          {
             for(j=0;j<=n;j++)
                printf(" %0.2f ",a[i][j]);
             printf(" \n ");

          }


 //print solution
   printf("\n\nThe solution of above equations are as follows:\n");
   for(i=0;i<n;i++)
        {
          
          { 
           printf("x%d->%0.2f",i+1,a[i][n]);
           printf("\n\n");
       
          }

        }

return 0;
}




