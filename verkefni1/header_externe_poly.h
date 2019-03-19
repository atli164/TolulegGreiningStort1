/* le header pour le calcul de la cinematique directe
a l'aide de la formule polynomiale */
#define pi (4*atan2(1.,1.))
#define degre 180.0
#define dg degre/pi
#define rad pi/degre
extern double xa[6], ya[6], za[6]; /*coordonnes des articulations sur fixe*/
extern double x[6], y[6], z[6]; /*coordonnes des articulations sur mobile*/


extern int n_max,n_min,flag_max;
extern int debug;
extern double ro1,ro2,ro3,ro4,ro5,ro6;
extern double ro1_2,ro2_2,ro3_2,ro4_2,ro5_2,ro6_2;
extern double ap,mp,m,GAMMA,ap2,invap;
extern double singamma2,cosgamma2; /*sin(GAMMA)^2,cos(GAMMA)^2 */
extern double singamma,cosgamma; /*sin(GAMMA)^2,cos(GAMMA)^2 */
extern double xa2,xa3,ya3,ya2,xa2_2,invxa2,xa3_2,ya3_2,ya2_2;
extern double p12,p34,p56;
extern double K11,K21,K22,K32,K33;
extern double K11_2,K21_2,K22_2,K32_2,K33_2;
extern double L11,L21,L22,L32,L33;
extern double L11_2,L21_2,L22_2,L32_2,L33_2;
extern double M11,M21,M22,M32,M33;
extern double M11_2,M21_2,M22_2,M32_2,M33_2;
extern double I1,I2,I3,H1,H2,H3;
extern double N1,N2,N3,N4,N5,N6;
extern double I1H2,I1H3,I2H3;
extern double eq1[5],eq2[5],eq3[5];
extern double a_poly[9],b_poly[9],c_poly[9],d_poly[9],e_poly[9],f_poly[9];
extern double q_poly[32],r_poly[32],s_poly[37],T[25];
extern double t[500];

extern double sp_0,sp_2,sp_4,sp_6,sp_8,sp_10,sp_12,sp_14;
extern double sp_16,sp_18,sp_20,sp_24,sp_26,sp_30,sp_36;



extern double K22L32;
extern double K33L21;
extern double K32L21;
extern double K21L32;
extern double L32L33;
extern double K33L22;
extern double K22L33;
extern double K21L33;
extern double K32L22;


extern double aM33M22a;
extern double aM33M21a;
extern double aM11M33a;
extern double aM22M33a;
extern double aM11M32a;
extern double aM21M22a;
extern double aM22M32a;
extern double aM32M22a;
extern double aM11M21a;
extern double aM11M22a;
extern double aM32M33a;
extern double invap2;
extern double invxa2_2;
extern double ro1_4,ro2_4,ro3_4,ro4_4,ro5_4,ro6_4;

extern double M33_3,M22_3,M11_3,M21_4,M22_4;
extern double M32_2_21,M32_32_2,M22_2_33_2,M11_2_22_2,M21_2_32_2,M11_21_2;
extern double M32_21_1,M21_22_3,M21_22_2,M21_11_2,M21_21_2,M21_2M33_2,M22_2M32_2;
extern double M22_2aM11M33a,M22_2aM11M32a,aM11M22aM33_2,aM21M22aM33_2,M22_2aM32M33a;
extern double aM11M22aM32M33a,aM11M21aM33_2,aM21M22aM32M33a,M21_2aM11M33a;
extern double aM11M21aM32M33a,M21_2aM11M32a,aM11M22aM32_2,aM21M22aM11M33a;
extern double aM21M22aM11M32a,aM11M21aM32_2,M21_2aM32M33a,aM21M22aM32_2,M21_2aM22M32a;

extern double M32_32_2_21,M11_21_21_2;


extern double r12,r34,r56;
extern double o12x,o12y,o34x,o34y,o56x,o56y;


extern double a12,a34,a56;
extern double A[12],B[12],C[13];
