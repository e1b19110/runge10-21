#include <stdio.h>
#include <math.h>


//太陽までの距離 r=1.5×10^11 m


#define r 1.0 //1.5e11

//太陽の質量 M=2.0×10^30 kg

#define M 1.0 //2.0e30


//万有引力定数 G=6.7×10^-11 N⋅m2/kg2

#define G 1.0 //6.7e-11

//地球の公転速度 107208000 m/h


#define N   100000//分割数

//太陽までの距離rを返す関数//
/*double r(){
    int i;
    double a=1.5;
    for(i=0; i<8; i++){
    a*=10;
    }
return a;
}*/


/*太陽の質量Mを返//す関数//
double M(){
     int i;
    double a=2.0;
    for(i=0; i<30; i++){
    a*=10;
    }
return a;

}*/


//万有引力定数Gを返す関数//
/*double G(){
     int i;
    double a=6.7;
    for(i=0; i<11; i++){
    a*=0.1;
    }
return a;

}*/

//d(vx)/dtを返す関数//
double X(double x,double y) {
    return -(G*M*x)/(sqrt(x*x+y*y)*sqrt(x*x+y*y)*sqrt(x*x+y*y));
}

//d(vy)/dtを返す関数//
double Y(double x,double y) {
    return -(G*M*y)/(sqrt(x*x+y*y)*sqrt(x*x+y*y)*sqrt(x*x+y*y));
}

//初速度を返す関数
double Vf(){
   double vf= sqrt((G*M)/r);
return vf;

}

int main(void) {
    
    int cnt=0;
    double vx = 0.0;   //x方向初速度 
    double vy = Vf(); //y方向初速度 
    double x = r; //x軸初期位置 
    double y = 0.0; //y軸初期位置
    double h = 0.001; //刻み幅
    
    double k1;
    double k2;
    double k3;
    double k4;
  
    for(double i=0; i<N; i++) {
        /*まずはvxを*/
        double x1=x;
        double vx1 = vx;
        k1 = h * X(x1,y);
        k2 = h * X(x1+ k1/2.0,y);
        k3 = h * X(x1+ k2 / 2.0,y);
        k4 = h * X(x1+ k3,y);
        vx = vx1 + (k1 + 2.0*k2 + 2.0*k3 + k4) / 6.0;
        /*ここからはxを*/
        k1 = h * (vx1);
        k2 = h * (vx1 + k1/2.0);
        k3 = h * (vx1 + k2 / 2.0);
        k4 = h * (vx1 + k3);
        x = x1 + (k1 + 2.0*k2 + 2.0*k3 + k4) / 6.0;
     
        
        /*まずはvyを*/
        double y1=y;
        double vy1 = vy;
         k1 = h * Y(x1,y1);
         k2 = h * Y(x1,y1+ k1/2.0);
         k3 = h * Y(x1,y1+ k2 / 2.0);
         k4 = h * Y(x1,y1+ k3);
         vy = vy1 + (k1 + 2.0*k2 + 2.0*k3 + k4) / 6.0;
      
         /*ここからはyを*/
         k1 = h * (vy1);
         k2 = h * (vy1 + k1/2.0);
         k3 = h * (vy1 + k2 / 2.0);
         k4 = h * (vy1 + k3);
         y = y1 + (k1 + 2.0*k2 + 2.0*k3 + k4) / 6.0;
        
        
        if(cnt==1){
        printf("%5.5lf %5.5lf \n", x, y);cnt=0;}
        cnt++;
        
}
}



