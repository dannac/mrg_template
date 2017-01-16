$PARAM TVCL=2.5, TVVC=80, TVQ =8, TVVP = 100, TVKA=1

$CMT GUT CENT PERIPH

$PKMODEL ncmt=2, depot=TRUE

$MAIN
double CL = TVCL*exp(ETA(1));
double V2 = TVVC;
double Q =  TVQ;
double V3 = TVVP*exp(ETA(2));
double KA = TVKA*exp(ETA(3));

$OMEGA cor=TRUE
  0.2
0.4 0.5
0.1 0.1 0.2

$TABLE double CP = CENT/V2;

$CAPTURE CP
