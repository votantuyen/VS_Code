#include <iostream>
#include <cmath>

using namespace std;
 
 /**
  * giai phuong trinh bat 2: ax2 + bx + c = 0
  * 
  * @param a: he so bat 2
  * @param b: he so bat 1 
  * @param c: so hang tu do
  */
 void giaiPTBac2 (float a, float b, float c)
 {
     // kiem tra he so
     if (a == 0)
     {
         if (b == 0)
         {
             printf("Phuong trinh vo nghiem!");
         }
         else
         {
             printf("Phuong trinh co mot nghiem: x = %f", (-c / b));
         }
         return;
     }
     // tinh delta
     float delta = b*b - 4*a*c;
     float x1;
     float x2;
     // tinh ngiem
     if (delta > 0)
     { 
      x1 = (float) ((-b + sqrt(delta)) / (2*a));
      x2 = (float) ((-b - sqrt(delta)) / (2*a));
      printf("Phuong trinh co hai nghiem la: x1 = %f va x2 = %f", x1, x2);   
     }
       else if (delta == 0)
       {
           x1 = (-b / (2 * a));
           printf("Phuong trinh co nghiem kep: x1 = x2 %f", x1);
       }
       else
       {
           printf ("phuong trinh vo nghiem!");
       }
       
 } 
 /**
  * ham main
  */
 int main()
 {
     float a, b, c;
     cout << "Nhap he so bat 2, a = ";
     cin >> a;
     cout << "Nhap he so bat 1, b = ";
     cin >> b;
     cout << "Nhap so tu do, c = ";
     cin >> c;
     giaiPTBac2(a, b, c);
     return 1;
 }