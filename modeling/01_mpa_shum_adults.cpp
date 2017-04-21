$PARAM TVCL=27.1, TVVc=97.7, TVKA=2.27, TVQ=25.7, TVVp=206
 
 
$SET start=0.0, end=48, delta=0.1
 
 
$CMT GUT CENT PERI
 
 
$MAIN
ALAG_GUT=0.145; 

double CL = TVCL*exp(ECL);
double Vc = TVVc*exp(EVc);
double KA = TVKA*exp(EKA);
double Q = TVQ*exp(EQ);
double Vp = TVVp*exp(EVp);


$ODE
  
dxdt_GUT = -KA*GUT;
dxdt_CENT = KA*GUT - (CL/Vc)*CENT - (Q/Vc)*CENT + (Q/Vp)*PERI;
dxdt_PERI = (Q/Vc)*CENT - (Q/Vp)*PERI;


$OMEGA @name BSV @ labels ECL EVc EKA EQ EVp    
0.0396 0.309 0 0 2.27


$SIGMA @name SGMA @ labels EXP ADD
0 0


$TABLE
capture IPRED = CENT/Vc;
double CP = IPRED + ADD; 


$CAPTURE 
CP IPRED CL Vc 
  