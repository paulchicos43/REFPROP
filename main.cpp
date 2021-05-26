
// Only this file gets the implementation
#define REFPROP_IMPLEMENTATION
#define REFPROP_FUNCTION_MODIFIER
#include "REFPROP_lib.h"
#undef REFPROP_FUNCTION_MODIFIER
#undef REFPROP_IMPLEMENTATION
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(int argc, char *argv[])
{	
	// You may need to change this path to suit your installation
	// Note: forward-slashes are recommended.
	char* path = "../";
	char* DLL_name = "librefprop.so";

	// Call a function in another file (and load the DLL, and then unload it)

	// Load the shared library
	std::string err;

	bool loaded_REFPROP = load_REFPROP(err, path, DLL_name);

	if (!loaded_REFPROP)
	{
		cout << err;
		return EXIT_FAILURE;
	}

	SETPATHdll(path, 400);

	int ierr = 0, nc = 1;
	char herr[255], hhmx[255] = "HMX.BNC", href[4] = "DEF";
	char* hfld = argv[2];
	SETUPdll(nc, hfld, hhmx, href, ierr, herr, 10000, 255, 3, 255);

	if (ierr > 0)
		printf("This ierr: %d herr: %s\n", ierr, herr);
	{	
		
		char* hIn = "102;152;204;305;354;401;452;502;552;601";
		char* hOut1 = "UNITUSER";
		double z1[20] = {};
		double c1 = -1;
		double q1 = -1;
		int hin_length1 = 255;
		int hout_length1 = 255;
		int herr_length1 = 255;
		int m = 0;
		int l = 0;
		double n = 0;
		double p = 0;
		REFPROP1dll(hIn,hOut1,m,l,n,p,z1,c1,q1,ierr,herr,hin_length1,hout_length1,herr_length1);
		
		int numberOfFluids = atoi(argv[1]);
		char* argumentTypes = "";
		int mode = atoi(argv[4]);
		if (mode == 1)
		{
			argumentTypes = "TP";
		}
		else if (mode == 2)
		{
			argumentTypes = "TD";
		}
		else if (mode == 54)
		{
			argumentTypes = "TE";
		}
		else if (mode == 56)
		{
			argumentTypes = "TS";
		}
		else if (mode == 40)
		{
			argumentTypes = "TH";
		}
		else if (mode == 46)
		{
			argumentTypes = "TQ";
		}
		else if (mode == 3)
		{
			argumentTypes = "PH";
		}
		else if (mode == 4)
		{
			argumentTypes = "PS";
		}
		else if (mode == 17)
		{
			argumentTypes = "PQ";
		}
		else if (mode == 41)
		{
			argumentTypes = "PD";
		}
		else if (mode == 57)
		{
			argumentTypes = "PE";
		}
		else if (mode == 58)
		{
			argumentTypes = "DH";
		}
		else if (mode == 59)
		{
			argumentTypes = "DS";
		}
		else if (mode == 60)
		{
			argumentTypes = "DE";
		}
		else if (mode == 61)
		{
			argumentTypes = "HS";
		}
		int ierr = 0;
		char herr[255];
		double z[20] = {1.0};
		double a = atof(argv[5]);
		double b = atof(argv[6]);
		int iflag1 = 2;
		double T = -1;
		double P = -1;
		double D = -1;
		double Dl = -1;
		double Dv = -1;
		double x[20] = {};
		double y[20] = {};
		double q = -1;
		double e = -1;
		double h = -1;
		double s = -1;
		double Cv = -1;
		double Cp = -1;
		double w = -1;
		int ixflag = 1;
		double x0[20] = {};
		double h0 = -1;
		double s0 = -1;
		double t0 = -1;
		double p0 = -1;
		SETREFdll("ASH", ixflag, x0, h0, s0, t0, p0, ierr, herr, 3, 255);
		char *hOut = "T,P,D,V,QMASS,E,H,S,CV,CP,STN,M,TTRP,TNBP,DIPOLE,ACF,TCRIT,PCRIT,DCRIT,R,BETA,W,F,VIS,TCX,PRANDTL,A,G";
		//M,TTRP,TNBP,TCRIT,PCRIT,DCRIT,ACF,DIPOLE,R,T,P,D,V,E,H,S,CV,CP,CP/CV,W,QMass,Z,JT,A,G,AR,GR,KAPPA,BETA,
		int iUnits = -1;
		int c = 0;
		GETENUMdll(c, "USER", iUnits, ierr, herr, 255, 255);
		
		
		int iFlag = 0;
		double output[200] = {};
		int hFld_length = 1000;
		int hIn_length = 255;
		int hOut_length = 255;
		int herr_length = 255;
		REFPROP2dll(hfld,argumentTypes,hOut,iUnits,iFlag,a,b,z,output,q,ierr,herr,hFld_length,hIn_length,hOut_length,herr_length);
		printf("Temperature: %F C\n",output[0]);
		printf("Pressure: %F kPa\n",output[1]);
		printf("Density: %F kg/m^3\n",output[2]);
		printf("Volume: %F m^3/kg\n",output[3]);
		printf("Quality: %F\n",output[4]);
		printf("Internal Energy: %F J/kg\n",output[5]);
		printf("Enthalpy: %F J/kg\n",output[6]);
		printf("Entropy: %F J/kg-K\n",output[7]);
		printf("Isochoric Heat Capacity: %F J/kg-K\n",output[8]);
		printf("Isobaric Heat Capacity: %F J/kg-K\n",output[9]);
		printf("Surface Tension: %F N/m\n",output[10]);
		printf("Molecular Weight: %F g/mol\n",output[11]);
		printf("Component 1 Triple Point Temperature: %F C\n",output[12]);
		printf("Component 1 Normal Boiling Point: %F C\n",output[13]);
		printf("Component 1 Dipole Moment: %F debye\n",output[14]);
		printf("Component 1 Acentric Factor: %F\n",output[15]);
		printf("Critical Temperature: %F C\n",output[16]);
		printf("Critical Pressure: %F kPa\n",output[17]);
		printf("Critical Density: %F kg/m^3\n",output[18]);
		printf("Gas Constant: %F J/mol-K\n",output[19]);
		printf("Thermal Expansion Coefficient: %F 1/K\n",output[20]);
		printf("Sound Speed: %F m/s\n",output[21]);
		printf("Component 1 Fugacity: %F kPa\n",output[22]);
		printf("Viscosity: %F microPa-s\n",output[23]);
		printf("Thermal Conductivity: %F W/m-K\n",output[24]);
		printf("Prandtl Number: %F\n",output[25]);
		printf("Helmholtz Energy: %F J/kg\n",output[26]);
		printf("Gibbs Free Energy: %F J/kg\n",output[27]);
	}
	

	// Call a function in another file (and load the DLL, and then unload it)

	return EXIT_SUCCESS;
}
