    
#include <math.h>
#include <stdio.h>
#include<sys/types.h>
#include<sys/timeb.h>

#include "header_poly.h"

main(argc,argv)
int argc;
char *argv[];
/*----------------------
Compute the forward kinematics of a 6-3 robot with a planr base.

This program computes the associated 8th order polynomial.
------------------------*/
{
int i,choix,nbpt,j,zero,k,kk,mmm;
int nb_signe,nb12[24];

FILE *fp,*fopen();

double rol[6];
double solution[24],w56[24],w121[24],w122[24];
double inf_p34[24],sup_p34[24];
double p34min,p34max,pas;
double a12b,a34b,a56b,pos1[6],rok[6];
double pos[6],psi,teta,phi,trm1[9];
double pos_est[6];

char ifile[256];

double poly;

if(argc!=2)
        {
        printf("Usage: 6p-3 [robot file]\n");
        exit(-1);
	}
if(ficentre(argv[1])!=1)
        {
        printf("Problem with robot file\n");
        exit(-1);
	}
printf("6p-3, INRIA, Version 0.1, March 12, 1990\n");
parametre:


	printf("give position/orientation (angles in degree)?\n");
scanf("%lf %lf %lf %lf %lf %lf",&pos[0],&pos[1],&pos[2],&psi,&teta,&phi);

	psi*=(pi/degre);teta*=(pi/degre);phi*=(pi/degre);
	pos[3]=psi;pos[4]=teta;pos[5]=phi;
	matrot_double(trm1,&psi,&teta,&phi);
	mgnlin_mat(pos,trm1,rol);

	angle_triangle(pos,&a12b,&a34b,&a56b);
	p12=a12b;p34=a34b;p56=a56b;
printf("Corresponding angles:\n");
printf("p12= %f, p34=%f, p56=%f\n",p12*degre/pi,p34*degre/pi,p56*degre/pi);
printf("Corresponding leg lengths:\n");
for (i=0;i<6;i++)printf("%f ",rol[i]);
printf("\n");

coeff_poly16(rol);

deb:

printf("you want to :\n");
printf(
"compute the value of the polynomial for a given position-----> 1\n");
printf(
"see the algebraic form of the polynomial  -------------------> 2\n");
printf(
"create a xjpdraw file of the polynomial ---------------------> 3\n");
printf(
"recompute the coefficients of the polynomial-----------------> 4\n");
printf(
"put the coefficients of the polynomial in a file-------------> 5\n");
printf(
"the angles and postures -------------------------------------> 6\n");
printf(
"the solution closest to a given posture----------------------> 7\n");
printf(
"the number of roots of the polynomial------------------------> 8\n");
printf(
"the angles and postures for given leg lengths----------------> 9\n");
printf(
"quit ----- --------------------------------------------------> -1\n");
scanf("%d",&choix);
if(choix>9 || choix==0 || choix<-1)goto deb;

	switch(choix){

	case -1:
	exit(0);

	case 1:
	printf("value of p34 in degree?\n");
	scanf("%lf",&p34);p34*=(pi/degre);
	printf("x value:%f\n",tan(p34/2.));
	valeur_poly(p34,&poly);
	printf("polynomial value : %f\n",poly);
	break;

	case 2:
	ecrit_poly();

	break;

	case 3:
	printf("name of result file ?\n");
	scanf("%s",ifile);
	printf("number of points in file?\n");
	scanf("%d",&nbpt);
	printf("want a line a y=0 (1 or 0)?\n");
	scanf("%d",&zero);
	printf("give p34 min and p34 max in degree?\n");
	scanf("%lf %lf",&p34min,&p34max);
	p34min*=(pi/degre);p34max*=(pi/degre);
	ecrit_fichier_jpdraw(ifile,nbpt,p34min,p34max,zero);

	break;

	case 4:
	goto parametre;

	case 5:
	printf("name of result file ?\n");
	scanf("%s",ifile);
	ecrit_fichier_polynome(ifile);
	break;

	case 6:
	case 9:
	if(choix==9)
		{
	printf("Enter 6 leg lengths?\n");
	for(i=0;i<6;i++)scanf("%lf",&rol[i]);
	coeff_poly16(rol);
		}
	mmm=0;
	printf("saving result in poly.sol\n");
	fp=fopen("poly.sol","w");
	kk=0;
	j=resol_polynome16(&i,solution);
	if(j== -1)
	{printf("problem when solving polynomial\n");break;}
sym:
	i=resol_p56_p12(&j,solution,w56,w121,w122,nb12);
	if(i== -1 || i== -2)
	{printf("problem for finding p56\n");break;}
	if(i== -3)
	{printf("probleme for finding p12\n");break;}
	printf("solutions (p12,p34,p56)\n");
	for(i=0;i<j;i++)
		{
	if(nb12[i]==2)
	printf("p12: %f ou %f ",w121[i]*degre/pi,w122[i]*degre/pi);
	else printf("p12: %f ",w121[i]*degre/pi);
	printf("p34: %f  p56: %f\n",solution[i]*degre/pi,w56[i]*degre/pi);
		}
	printf("solutions for posture\n");
	for(i=0;i<j;i++)
		{
	position_tssm(w121[i],solution[i],w56[i],rol,pos1);
	printf("%f %f %f %f %f %f :",pos1[0],pos1[1],pos1[2],
	pos1[3]*degre/pi,pos1[4]*degre/pi,pos1[5]*degre/pi);
	matrot_double(trm1,&pos1[3],&pos1[4],&pos1[5]);
	mgnlin_mat(pos1,trm1,rok);
	for(k=0;k<6;k++)
			{
			if(fabs(rol[k]-rok[k])>0.01)break;
			}
	if(k==6)
			{
			printf("valid solution\n");
	fprintf(fp,"%f %f %f %f %f %f\n",pos1[0],pos1[1],pos1[2],
	pos1[3]*degre/pi,pos1[4]*degre/pi,pos1[5]*degre/pi);
			mmm++;
			}

	else printf("wrong solution\n");
	if(nb12[i]==2)
			{
			position_tssm(w122[i],solution[i],w56[i],rol,pos1);
	printf("%f %f %f %f %f %f :",pos1[0],pos1[1],pos1[2],
	pos1[3]*degre/pi,pos1[4]*degre/pi,pos1[5]*degre/pi);
	matrot_double(trm1,&pos1[3],&pos1[4],&pos1[5]);
	mgnlin_mat(pos1,trm1,rok);
	for(k=0;k<6;k++)
			{
			if(fabs(rol[k]-rok[k])>0.01)break;
			}
	if(k==6)
			{
			printf("valid solution\n");
	fprintf(fp,"%f %f %f %f %f %f\n",pos1[0],pos1[1],pos1[2],
	pos1[3]*degre/pi,pos1[4]*degre/pi,pos1[5]*degre/pi);
			mmm++;
			}
	else printf("wrong solution\n");
			}
		}
	if(kk)
		{
	printf("There is a total of %d solutions\n",mmm);
		fclose(fp);break;
		}
	printf("symmetrical solutions\n");
	for(k=0;k<j;k++)solution[k]= -solution[k];
	kk=1;
	goto sym;

	case 7:
	printf("give a position estimate\n");
	for(i=0;i<=5;i++)scanf("%lf",&pos_est[i]);
	for(i=3;i<=5;i++)pos_est[i]*=(pi/degre);
	mginv_poly16(rol,pos_est);
	printf("solution:");
	for(i=0;i<=2;i++)printf("%f ",pos_est[i]);
	for(i=3;i<=5;i++)printf("%f ",pos_est[i]*degre/pi);
	break;

	case 8:
	printf("number of solutions:%d\n",nombre_sol16(rol));
	break;



	default:
	goto deb;
	}
goto deb;
}
