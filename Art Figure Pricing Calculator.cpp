//     ***********************************************
//     **              PRICING PROGRAM              **
//     ***********************************************

//     ***********************************************
//     **                DESCRIPTION                **
//     ***********************************************
//     ** This program allows the user to calculate **
//     ** the price of a unique art figure based    **
//     ** on the shape and dimensions entered.      **
//     ***********************************************
//     **             Available shapes:             **
//     **         Cube - Torus - Ellipsoid          **
//     ***********************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	// PROJECT FORMATTING:
	cout << setprecision(2) << fixed << showpoint;

	// VARIABLE DECLARATION:
	const double PI = 3.1416;
	string CustomerName;
	double R = 0.0;
	double Mr = 0.0;
	double H = 0.0;
	double V = 0.0;
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double HandlingFee = 0.0;
	double ShippingFee = 0.0;
	double TotalCharge = 0.0;
	char MainMenuSelect;
	char ShapeSelect = 0;
	char repeat;
	char eval_repeat;

	do
	{

	// MENU SELECTION:
	cout << "**************************************" << endl;
	cout << "**             MAIN MENU            **" << endl;
	cout << "**************************************" << endl;
	cout << "**     | 1. Evaluate Pricing |      **" << endl;
	cout << "**     | 2. Exit Program     |      **" << endl;
	cout << "**************************************" << endl << endl;

	cout << "MENU SELECTION [1-2]: ";
	cin >> MainMenuSelect;
	cin.get();
	
		switch (MainMenuSelect)
		{
		case '1':
			// ENTER CUSTOMER NAME:
			cout << "\n\nEnter the Customer Name: ";
			getline(cin, CustomerName);

			do
			{

				// SHAPE SELECTION:
				cout << endl << "***************************************************" << endl;
				cout << "**                SHAPE SELECTION                **" << endl;
				cout << "***************************************************" << endl;
				cout << "**     | 1. Cube | 2. Torus | 3. Ellipsoid |     **" << endl;
				cout << "***************************************************" << endl << endl;

				cout << "***************************************************" << endl;
				cout << "**   SELECT PERFERED SHAPE FROM THE ABOVE MENU   **" << endl;
				cout << "***************************************************" << endl << endl;

				cout << "SHAPE SELECTION [1-3]: ";
				cin >> ShapeSelect;

				switch (ShapeSelect)
				{
					// SHAPE DIMENSION INPUT & CALCULATION:

					// CUBE SELECT:
				case '1':
					cout << "Enter the side length of the cube (feet): ";
					cin >> H;

					// CYLINDER CALCULATIONS:
					V = pow(H, 3);

					if (V <= 50)
						HandlingFee = 5.55;
					else if (V <= 100)
						HandlingFee = 7.75;
					else if (V <= 150)
						HandlingFee = 9.50;
					else if (V > 150)
						HandlingFee = 11.25;

					if (V <= 50)
						ShippingFee = (V * 0.10);
					else if (V <= 100)
						ShippingFee = (V - 50) * 0.23;
					else if (V <= 150)
						ShippingFee = (V - 100) * 0.28;
					else if (V > 150)
						ShippingFee = (V - 150) * 0.32;

					TotalCharge = ShippingFee + HandlingFee;

					// CUBE OUTPUT:
					cout << "\n\n\n\n***************************************" << endl;
					cout << "Shipping Invoice for " << CustomerName << endl << endl;
					cout << "Dimensions of the Cube:" << endl;
					cout << "Side: " << H << " Feet" << endl << endl;
					cout << "Volume: " << V << " Cubic Feet" << endl << endl;
					cout << "Handling Fee..........$" << HandlingFee << endl;
					cout << "Shipping Fee..........$" << ShippingFee << endl;
					cout << "Total Charge..........$" << TotalCharge << endl;
					cout << "***************************************" << endl << endl << endl << endl;

					break;

					// TORUS SELECT:
				case '2':
					cout << "Enter the major radius (R) of the Torus (feet): ";
					cin >> R;
					cout << "Enter the minor radius (r) of the Torus (feet): ";
					cin >> Mr;

					// TORUS CALCULATIONS:
					V = (1.0 / 4) * pow(PI, 2) * (Mr + R) * pow(Mr - R, 2); 

					if (V <= 50)
						HandlingFee = 5.55;
					else if (V <= 100)
						HandlingFee = 7.75;
					else if (V <= 150)
						HandlingFee = 9.50;
					else if (V > 150)
						HandlingFee = 11.25;

					if (V <= 50)
						ShippingFee = (V * 0.10);
					else if (V <= 100)
						ShippingFee = (V - 50) * 0.23;
					else if (V <= 150)
						ShippingFee = (V - 100) * 0.28;
					else if (V > 150)
						ShippingFee = (V - 150) * 0.32;

					TotalCharge = ShippingFee + HandlingFee;

					// TORUS OUTPUT:
					cout << "\n\n\n\n***************************************" << endl;
					cout << "Shipping Invoice for " << CustomerName << endl << endl;
					cout << "Dimensions of the Torus:" << endl;
					cout << "Major Radius: " << R << " Feet" << endl;
					cout << "Minor Radius: " << Mr << " Feet" << endl << endl;
					cout << "Volume: " << V << " Cubic Feet" << endl << endl;
					cout << "Handling Fee..........$" << HandlingFee << endl;
					cout << "Shipping Fee..........$" << ShippingFee << endl;
					cout << "Total Charge..........$" << TotalCharge << endl;
					cout << "***************************************" << endl << endl << endl << endl;

					break;

					// ELLIPSOID SELECT:
				case '3':
					cout << "A-axis Radius (feet): ";
					cin >> a;
					cout << "B-axis Radius (feet): ";
					cin >> b;
					cout << "C-axis Radius (feet): ";
					cin >> c;

					// ELLIPSOID CALCULATIONS:
					V = (4.0 / 3) * PI * a * b * c;

					if (V <= 50)
						HandlingFee = 5.55;
					else if (V <= 100)
						HandlingFee = 7.75;
					else if (V <= 150)
						HandlingFee = 9.50;
					else if (V > 150)
						HandlingFee = 11.25;

					if (V <= 50)
						ShippingFee = (V * 0.10);
					else if (V <= 100)
						ShippingFee = (V - 50) * 0.23;
					else if (V <= 150)
						ShippingFee = (V - 100) * 0.28;
					else if (V > 150)
						ShippingFee = (V - 150) * 0.32;

					TotalCharge = ShippingFee + HandlingFee;

					// ELLIPSOID OUTPUT:
					cout << "\n\n\n\n***************************************" << endl;
					cout << "Shipping Invoice for " << CustomerName << endl << endl;
					cout << "Dimensions of the cone:" << endl;
					cout << "A-axis: " << a << " Feet" << endl;
					cout << "B-axis: " << b << " Feet" << endl;
					cout << "C-axis: " << c << " Feet" << endl << endl;
					cout << "Volume: " << V  << " Cubic Feet" << endl << endl;
					cout << "Handling Fee..........$" << HandlingFee << endl;
					cout << "Shipping Fee..........$" << ShippingFee << endl;
					cout << "Total Charge..........$" << TotalCharge << endl;
					cout << "***************************************" << endl << endl << endl << endl;

					break;


					// UNKNOWN INPUT - DISPLAY ERROR
				default:
					cout << endl << "************************************************" << endl;
					cout << "***** Must select a number between 1 and 3 *****" << endl;
					cout << "************************************************" << endl << endl;
				}
				
				cout << "Re-run price evaluation? | Y | N | " << endl;
				cin >> eval_repeat;

			}while (eval_repeat == 'Y' || eval_repeat == 'y');

			break;

		case '2':
			cout << endl << "***** ENDING PROGRAM *****" << endl << endl;
			break;

		default:
			cout << endl << "*************************************" << endl;
			cout << "*****  The choices are 1 and 2  *****" << endl;
			cout << "***** Please Re-Run the Program *****" << endl;
			cout << "*************************************" << endl << endl;
		}

		cout << "Evaluate price for a new customer? | Y | N |" << endl;
		cin >> repeat;

	} while (repeat == 'Y' || repeat == 'y');

	return 0;
}