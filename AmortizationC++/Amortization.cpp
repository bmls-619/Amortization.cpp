#include<iostream>
#include<math.h>
using namespace std;

class RegularPaymentAmortization
{
	public:

		double RegularPayment(double loanAmount, double interestRate, double loanTerm) {

			double fee;

			fee = loanAmount * (interestRate / (1 - pow((1 + interestRate), -loanTerm)));

			return(fee);
		}
};

void tabla_amortizacion(void) {

	double c, p, i, regularPayment;
	RegularPaymentAmortization rpa;

		system("cls");
		cout << endl
			<< "                    AMORTIZATION TABLE GENERATOR "
			<< endl
			<< "                    -------------------------------------------";
		cout << endl
			<< endl;


		system("cls");
		cout << endl;
		cout << endl << "                Enter loan Amount: ";
		cin >> c;
		cout << endl << "              Enter Interest Rate: ";
		cin >> i;
		cout << endl << "                 Enter loan Term : ";
		cin >> p;


		double month = 12 * p;
		double interest_decimal = (i / 100) / 12;
		regularPayment = rpa.RegularPayment(c, interest_decimal, month);


		system("cls");

		cout << endl << "Month" << "\t\tFee" << "\t\tInterest"
			<< "\t\Principal" << "\t\tEnding Balance \n\n"
			<< "-----------------------------------------------------------------------------------------------------";


		for (int plz = 1; plz <= month; plz++)
		{
			
			double rate = interest_decimal * c;
			double amortization = regularPayment - rate;
			c = c - amortization;

			if (c < 0)
			{
				c = 0;
			}

			cout << endl << endl

				<< plz << "\t\t" << ceil(regularPayment) << "\t\t" << ceil(rate)
				<< "\t\t" << ceil(amortization) << "\t\t\t" << ceil(c);
		}


		cout << endl << endl;
}

int main()
{

	tabla_amortizacion();

	return 0;
}