$PARAM TVCL= 33, TVVc= 91, TVQ=35, TVVp=237, TVKA=4.1, clcr=31, alb=34, CsA=600, gender=1, wt=67

$SET end=12, delta=0.05

$CMT GUT CENT PERI

$MAIN
ALAG_GUT = 0.21;

double CL = TVCL*pow(wt/70, 0.75)*pow(clcr/48,-0.12)*pow(alb/30,-1.07)*pow(CsA/450,0.31)*pow(1.11,gender)*exp(ECL);
double Vc = TVVc*(wt/70)*pow(clcr/48,-0.62)*pow(alb/30,-1.13)*exp(EVc);
double KA = TVKA*exp(EKA);
double Q = TVQ*pow(wt/70, 0.75)*exp(EQ);
double Vp = TVVp*(wt/70)*exp(EVp);


$ODE
  
dxdt_GUT = -KA*GUT;
dxdt_CENT = KA*GUT - (CL/Vc)*CENT - (Q/Vc)*CENT + (Q/Vp)*PERI;
dxdt_PERI = (Q/Vc)*CENT - (Q/Vp)*PERI; 


$OMEGA @name IIV @labels ECL EVc EKA EQ EVp
0.096 0.8 1.2 0 1 


$SIGMA @name SGMA @labels PROP ADD
0 0


$TABLE
capture (IPRED) = CENT/Vc;
double CP = CENT/Vc*(1+PROP) + ADD;


$CAPTURE
CP IPRED CL Vc clcr alb CsA gender