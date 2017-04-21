$PARAM TVCL=25.4, TVVc=65, TVKA=0.64, TVQ=30, TVVp=496, TValb=26, theta1=1, theta2=1, theta3=1, fkcy=1, wt=33.6   


$SET end=48, delta=0.1


$CMT GUT CENT PERI


$MAIN

double CL = TVCL*pow(wt/70, 0.75)*theta1*(1+theta2*(TValb-26))*(1+theta3*fkcy)*exp(ECL);
double Vc = TVVc*(wt/70)*exp(EVc);
double KA = TVKA*exp(EKA);
double Q = TVQ*pow(wt/70, 0.75)*exp(EQ);
double Vp = TVVp*(wt/70)*exp(EVp);


$ODE
  
dxdt_GUT = -KA*GUT;
dxdt_CENT = KA*GUT - (CL/Vc)*CENT - (Q/Vc)*CENT + (Q/Vp)*PERI;
dxdt_PERI = (Q/Vc)*CENT - (Q/Vp)*PERI;


$OMEGA @name BSV @ labels ECL EVc EKA EQ EVp    
0.32 0 1.09 0.78 0


$SIGMA @name SGMA @ labels PROP
0 


$TABLE
capture IPRED = CENT/Vc;
double CP = IPRED + PROP; 


$CAPTURE 
CP IPRED CL Vc 
  