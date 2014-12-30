#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

/*
 This code uses RK4 solver and I added different applications for it for the last 3 problems of last written assignment
 */
void RK4(int N, double t, double h, const double X[],
         void (*F)(double t, const double X[], double R[]),
         double R[]) {
  double K1[N];
  F(t,X,K1);

  double T[N], K2[N];
  for (int i = 0; i < N; i++)
    T[i] = X[i] + h/2*K1[i];
  F(t+h/2,T,K2);

  double K3[N];
  for (int i = 0; i < N; i++)
    T[i] = X[i] + h/2*K2[i];
  F(t+h/2,T,K3);

  double K4[N];
  for (int i = 0; i < N; i++)
    T[i] = X[i] + h*K3[i];
  F(t+h,T,K4);

  for (int i = 0; i < N; i++)
    R[i] = X[i] + h/6*(K1[i] + 2*(K2[i] + K3[i]) + K4[i]);
}

void Airy(double t, const double X[], double R[]){
  R[0] = X[1];
  R[1] = t*X[0];
}

void Fbaseball(double t, const double X[], double R[]){
  const double k = 0.25;
  const double g = 32.0;
  R[0] = X[1];
  //R[1] = -k*sqrt(X[1]*X[1] + X[3]*X[3]);
  R[1] = -k*X[1];
  R[2] = X[3];
  //R[3] = -k*sqrt(X[1]*X[1] + X[3]*X[3]) - g;
  R[3] = -k*X[3] -g;
}

void Mercury(double t, const double X[], double R[]){
  const double msun = 1.9891e30;
  const double mmer = 3.3022e23;
  const double G = 6.67384e-11;
  const double r = sqrt(X[0]*X[0] + X[2]*X[2]);
  const double F = (mmer*msun*G)/(r*r);
  const double Fx = F*X[0]/r;
  const double Fy = F*X[2]/r;
  R[0] = X[1];
  R[1] = -Fx/mmer;
  R[2] = X[3];
  R[3] = -Fy/mmer;
}

int main(){

 /**
  COMPUTER PROBLEM 16
  double t = 0.0;
  double h = 0.1;
  double X[2] = {0.355028053887817, -0.258819403792807};

  for (int i = 0; i < 100; i++, t += h){
    printf("%0.10f %0.10f\n", t, X[0]);
    RK4(2, t, h, X, Airy, X);
    }
  **/

  /**BASEBALL PROBLEM OFF EZEKIEL*/
  double t = 0.0;
  double h = 0.1;
  double v = 208.0;
  double theta = 43*M_PI/180;
  double X[4];
  X[0] = 0.0;
  X[1] = v*cos(theta);
  X[2] = 3.0;
  X[3] = v*sin(theta);
  for (int n = 0; (t < 6.47859) && (n < 100); n++, t += h){
    printf("%0.10f %0.10f\n", X[0], X[2]);
    RK4(4, t, h, X, Fbaseball, X);
    }

  /**MERCURY PROBLEM OFF EZEKIEL
  double t = 0.0; //t in seconds for this problem
  double h = 100.0; //no time step given in problem
  double X[4] = {46001200000.0, 0.0, 0.0, 58980.0};
  for (; t <= 7600521.6; t += h){
    printf("%0.10f %0.10f\n", X[0], X[2]);
    RK4(4, t, h, X, Mercury, X);
    }
  **/
}
