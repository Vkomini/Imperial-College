/* This program prints out a conversion table of temperatures, after
   prompting the user for upper and lower bounds of the table in
   Fahrenheit, and the temperature difference between table entries. */ 

#include <iostream>
#include <iomanip>
using namespace std;


void print_preliminary_message();
void input_table_specifications(int& lower, int& upper, int& step);
void print_message_echoing_input(int lower, int upper, int step);
void print_table(int lower, int upper, int step);

double celsius_of(int fahr);
double absolute_value_of(int fahr);

/* START OF MAIN PROGRAM */
int main() 
{
  int lower = 0; /* the lowest Fahrenheit entry in the table */
  int upper = 0; /* the highest Fahrenheit entry in the table */
  int step = 1;  /* difference in Fahrenheit between entries */
  
  cout << setiosflags (ios::left);

  /* print a message explaining what the program does: */
  print_preliminary_message();
  
  /* prompt the user for table specifications in Fahrenheit: */
  input_table_specifications(lower, upper, step);
  
  /* print appropriate message including an echo of the input: */
  print_message_echoing_input(lower, upper, step);
  
  /* Print the table (including the column headings): */
  print_table(lower, upper, step);

  return 0;
}
/* END OF MAIN PROGRAM */

/* FUNCTION TO PRINT OPENING MESSAGE TO USER */
void print_preliminary_message(){
  cout << " This program prints out a conversion table of temperatures.\n";
}

/* FUNCTION TO INPUT TABLE SPECIFICATIONS */
void input_table_specifications(int& lower,int&  upper,int&  step){
  cout << "Enter the minimum (whole number) temperature you want in the table, in Fahrenheit:" << endl;
  cin >> lower;
  cout << "Enter the maximum temperature you want in the table:";
  cin >> upper;
  cout << "Enter the temperature difference you want between table entries:";
  cin >> step;
  cout << endl << endl;
}

/* FUNCTION TO ECHO TABLE SPECIFICATIONS */
void print_message_echoing_input(int lower,int upper,int step){
  cout << "The minimum whole number you entered was:";
  cout << lower << endl;
  cout << "The maximum temperature you wanted in the table was:";
  cout << upper << endl;
  cout << "The temperature difference you wanted between the entries  was:";
  cout << step << endl;
}

/* FUNCTION TO PRINT THE TABLE */
void print_table(int lower,int  upper,int step){

  int fahr; 

  /* Print table heading */
  cout.width(17);
  cout << "Fahrenheit";
  cout.width(13);
  cout << "Celsius" << "Absolute Value" << endl << endl;

  /* set format of individual values */
  cout.precision(2); 
  cout.setf(ios::fixed); 

  /* print table from lowest_entry to highest_entry */
  for (fahr = lower ; fahr <= upper ; fahr += step) {
    cout << "   ";
    cout.width(15);
    cout << fahr;
    cout.width(15);
    cout << celsius_of(fahr) << absolute_value_of(fahr) << endl;
  }
}

/* FUNCTION TO CONVERT FAHRENHEIT TO CELSIUS */
double celsius_of(int fahr)
{
  return (static_cast<double>(5)/9) * (fahr - 32);
}
/* END OF FUNCTION */

/* FUNCTION TO CONVERT FAHRENHEIT TO ABSOLUTE VALUE */
double absolute_value_of(int fahr)
{
  return ((static_cast<double>(5)/9) * (fahr - 32)) + 273.15;
}
/* END OF FUNCTION */
