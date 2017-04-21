$PARAM
TVKA=4.1 
TVVc=40 
TVCL=16 
TVVp=518 
TVQ=22 
wt=28.7 

$SET end=48, delta=0.1

$CMT GUT CENT PERI

$MAIN
ALAG_GUT=0.3; 

double CL=TVCL*pow(wt/70, 0.75)*exp(ECL);
double Vc=TVVc*(wt/70)*exp(EVc);
double KA=TVKA*exp(EKA);
double Q=TVQ*pow(wt/70, 0.75)*exp(EQ);
double Vp=TVVp*(wt/70)*exp(EVp);

$ODE
  
dxdt_GUT = -KA*GUT;
dxdt_CENT = KA*GUT - (CL/Vc)*CENT - (Q/Vc)*CENT + (Q/Vp)*PERI;
dxdt_PERI = (Q/Vc)*CENT - (Q/Vp)*PERI;

$OMEGA @name IIV @ labels ECL EVc EKA EQ EVp
0.39 1 1.87 0.7 5

$SIGMA @name SGMA @ labels PROP
0

$TABLE
capture IPRED = CENT/Vc;
double CP = IPRED + PROP;

$CAPTURE
CP IPRED CL Vc
