

    Info<< "Reading field phii\n" << endl;
    volScalarField phii
    (
        IOobject
        (
            "phii",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


   Info<< "Reading field pos\n" << endl;
    volScalarField pos
    (
        IOobject
        (
            "pos",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );
    
   Info<< "Reading field neg\n" << endl;
    volScalarField neg
    (
        IOobject
        (
            "neg",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );
    
        
    

    Info<< "Calculating field chargeDensity\n" << endl;
    volScalarField chargeDensity
    (
        IOobject
        (
            "chargeDensity",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        pos-neg
    );
    
    Info<< "Calculating field source\n" << endl;
    volScalarField source
    (
        IOobject
        (
            "source",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        kdN-kr*pos*neg
    );
        
    Info<< "Calculating field posFlux\n" << endl;
    surfaceScalarField posFlux
    (
        IOobject
        (
            "posFlux",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        -bpos*mesh.magSf()*fvc::snGrad(phii)
    );
    
      Info<< "Calculating field negFlux\n" << endl;
    surfaceScalarField negFlux
    (
        IOobject
        (
            "negFlux",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        -bneg*mesh.magSf()*fvc::snGrad(phii)
    );
    
        Info<< "Calculating field force\n" << endl;
    volVectorField force
    (
        IOobject
        (
            "force",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),        
        -chargeDensity*fvc::grad(phii)/rho0
	);
	    Info<< "Calculating field elec\n" << endl;
    volVectorField elec
    (
        IOobject
        (
            "elec",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        -fvc::grad(phii)
    );
    
    	    Info<< "Calculating field omega\n" << endl;
    volScalarField omega
    (
        IOobject
        (
            "omega",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        sqrt(pow(electron,3)/(4*pinum*epsilon0*pow(kb*T,2))*mag(elec))
    );
    	    Info<< "Calculating field fw\n" << endl;
    volScalarField fw
    (
        IOobject
        (
            "fw",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
		mesh,
		dimensionedScalar("fw",dimless,scalar(1))
//       (2*sqrt(pow(electron,3)*mag(elec)/epsilon0)/kbT)
    );
  


