IOdictionary EHDProperties
(
    IOobject
    (
        "EHDProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    )
);
    dimensionedScalar rho0("rho0", dimMass/dimVolume, laminarTransport);

    dimensionedScalar Cp0("Cp0", dimEnergy/dimMass/dimTemperature, laminarTransport);
    
  bool EHD= EHDProperties.lookupOrDefault("activateEHD",false);

     Info<< "activate EHD = " << EHD<<endl;

    dimensionedScalar epsilon0
    (
        EHDProperties.lookup("epsilon0")
    );   

    dimensionedScalar epsilonr
    (
        EHDProperties.lookup("epsilonr")
    );
    dimensionedScalar bpos
    (
        EHDProperties.lookup("bpos")
    );

    dimensionedScalar bneg
    (
        EHDProperties.lookup("bneg")
    );

    dimensionedScalar sig
    (
        EHDProperties.lookup("sig")
    );

    dimensionedScalar D
    (
        EHDProperties.lookup("D")
    );
    dimensionedScalar kb
    (
        EHDProperties.lookup("kb")
    );
    dimensionedScalar electron
    (
        EHDProperties.lookup("electron")
    );
	double pinum=constant::mathematical::pi;
	dimensionedScalar neq=sig/(bpos-bneg);
	dimensionedScalar kr=(bpos-bneg)/epsilon0;
	dimensionedScalar kdN=kr*neq*neq;
	dimensionedScalar joule=sig/(rho0*Cp0);


double p1=0.5;
double p2=0.87890594;
double p3=0.51498869;
double p4=0.15084934;
double p5=0.2658733e-1;
double p6=0.301532e-2;
double p7=0.32411e-3;
double q1=0.39894228;
double q2=0.3988024e-1;
double q3=-0.362018e-2;
double q4=0.163801e-2;
double q5=-0.1031555e-1;
double q6=0.2282967e-1;
double q7=-0.2895312e-1;
double q8=0.1787654e-1;
double q9=-0.420059e-2;
double yy=0.0;
double ax=0.0;
double bessi1=0.0;
double twoOmega=0.0;

		
