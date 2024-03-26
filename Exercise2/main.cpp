#include<iostream>
#include<fstream>
#include<iomanip>   //libreria necessaria per utilizzare il comando "setprecision"
using namespace std;

double Map(double x)    //funzione lineare che riscala i punti da [1,5] a [-1,2]
{   double y = (x-3)*3/4 + 0.5;
    return y;}


int main()
{   ifstream FileVal("data.csv");
    ofstream MeanVal ("result.csv");
    MeanVal << "# N Mean"<<endl;    //intestazione
    int i = 1;
    double val;    //verrà inzializzato direttamente nel ciclo while
    double mean = 0;
    double sum = 0;
    while(FileVal>>val)
    {   val = Map(val);
        sum = sum +val;
        mean = sum/i;
        MeanVal <<i<<" ";
        MeanVal <<setprecision(16)<<scientific<<mean <<endl;    //mean viene stampato in notazione esponenziale con 16 cifre decimali
        i++;
    }
    MeanVal.close();
    FileVal.close();


    return 0;
}
