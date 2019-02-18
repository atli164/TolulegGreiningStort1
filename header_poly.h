/* le header pour le calcul de la cinematique directe
a l'aide de la formule polynomiale */

#define pi (4*atan2(1.,1.))
#define degre 180.0
#define dg degre/pi
#define rad pi/degre
double xa[6], ya[6], za[6]; /*coordonnes des articulations sur fixe*/
double x[6], y[6], z[6]; /*coordonnes des articulations sur mobile*/

/*si flag_max=1 on recherche un nombre maxi de solution mis a
jour dans n_max et nombre_sol retourne 100 si pour la configuration
le nombre de solution est inferieur a n_max
si flag_max=2 on recherche aussi le nombre mini de solution 
mis a jour dans n_min */

int debug=0;
 int n_max,n_min,flag_max=0;
double ro1,ro2,ro3,ro4,ro5,ro6;
double ro1_2,ro2_2,ro3_2,ro4_2,ro5_2,ro6_2;
double ap,mp,m,GAMMA,ap2,invap;
double singamma2,cosgamma2; /*sin(GAMMA)^2,cos(GAMMA)^2 */
double singamma,cosgamma; /*sin(GAMMA)^2,cos(GAMMA)^2 */
double xa2,xa3,ya3,ya2,xa2_2,invxa2,xa3_2,ya3_2,ya2_2;
double p12,p34,p56;
double K11,K21,K22,K32,K33;
double K11_2,K21_2,K22_2,K32_2,K33_2;
double L11,L21,L22,L32,L33;
double L11_2,L21_2,L22_2,L32_2,L33_2;
double M11,M21,M22,M32,M33;
double M11_2,M21_2,M22_2,M32_2,M33_2;
double I1,I2,I3,H1,H2,H3;
double N1,N2,N3,N4,N5,N6;
double I1H2,I1H3,I2H3;
double eq1[5],eq2[5],eq3[5];
double a_poly[9],b_poly[9],c_poly[9],d_poly[9],e_poly[9],f_poly[9];
double q_poly[32],r_poly[32],s_poly[37],T[25];
double t[500];

double sp_0,sp_2,sp_4,sp_6,sp_8,sp_10,sp_12,sp_14;
double sp_16,sp_18,sp_20,sp_24,sp_26,sp_30,sp_36;


double K22L32;
double K33L21;
double K32L21;
double K21L32;
double L32L33;
double K33L22;
double K22L33;
double K21L33;
double K32L22;


double aM33M22a;
double aM33M21a;
double aM11M33a;
double aM22M33a;
double aM11M32a;
double aM21M22a;
double aM22M32a;
double aM32M22a;
double aM11M21a;
double aM11M22a;
double aM32M33a;
double invap2;
double invxa2_2;
double ro1_4,ro2_4,ro3_4,ro4_4,ro5_4,ro6_4;
double M33_3,M22_3,M11_3,M21_4,M22_4;
double M32_2_21,M32_32_2,M22_2_33_2,M11_2_22_2,M21_2_32_2,M11_21_2;
double M32_21_1,M21_22_3,M21_22_2,M21_11_2,M21_21_2,M21_2M33_2,M22_2M32_2;
double M22_2aM11M33a,M22_2aM11M32a,aM11M22aM33_2,aM21M22aM33_2,M22_2aM32M33a;
double aM11M22aM32M33a,aM11M21aM33_2,aM21M22aM32M33a,M21_2aM11M33a;
double aM11M21aM32M33a,M21_2aM11M32a,aM11M22aM32_2,aM21M22aM11M33a;
double aM21M22aM11M32a,aM11M21aM32_2,M21_2aM32M33a,aM21M22aM32_2,M21_2aM22M32a;
double M32_32_2_21,M11_21_21_2;

double r12,r34,r56;
double o12x,o12y,o34x,o34y,o56x,o56y;
double a12,a34,a56;
double A[12],B[12],C[13];

