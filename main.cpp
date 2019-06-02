#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>

using namespace std;

int main()
{
    string name, social, address, telephone, header;
    double test1, test2, test3, test4, finalexam, percentage;
    int age, numyears;
    char letterGrade;
    
    // open input file
    ifstream fin;
    fin.open("project2_input.txt");
    
    if (!fin) {
        cout << "could not open file" << endl;
        return -1;
    }
    
    // open output file
    ofstream fout;
    fout.open("project2_output.txt");
    
    
    if (!fout) {
        cout << "could not open file" << endl;
        return -1;
    }
    
    // read data from input file and print data to output file
    getline(fin,header);
    fout<< right << setw(45) << header<<endl;
    
    getline(fin,name);
    fout << right << setw(31) << "Name of Student:" << right << setw(22) << name << endl;
    
    fin >> age;
    fout << right << setw(31) << "Age:" << right << setw(10) << age << endl;
    fin.ignore();
    
    getline(fin,address);
    fout << right << setw(31) << "Address:" << right << setw(45) << address <<endl;
    
    fin >> numyears;
    fout << "Number of years at Texas State:" << right << setw(9) << numyears << endl;
    
    fin>> telephone;
    fout << right << setw(31) << "Telephone number:" << setw(21) << telephone << endl;
    
    fin>> social;
    fout << right << setw(31) << "Student Social Security #:" << right << setw(19) << social << endl;
    
    fin >> test1;
    fout << right << setw(31) << "Test #1:" << right << setw(12) << test1 << endl;
    
    fin >> test2;
    fout << right << setw(31) << "Test #2:" << right << setw(12) << test2 << endl;
    
    fin >> test3;
    fout << right << setw(31) << "Test #3:" << right << setw(12) << test3 << endl;
    
    fin >> test4;
    fout << right << setw(31) << "Test #4:" << right << setw(12) << test4 << endl;
    
    fin >> finalexam;
    fout << right << setw(31) << "Final Exam:" << right << setw(12) << finalexam << endl;
    
    // calculate average
    double grade1, grade2, grade3, grade4, grade5;
    
    grade1 = (10*test1)/100;
    grade2 = (15*test2)/100;
    grade3 = (15*test3)/100;
    grade4 = (20*test4)/100;
    grade5 = (40*finalexam)/100;
    
    percentage = grade1 + grade2 + grade3 + grade4 + grade5;
    
    // print average grade percentage
    fout << right << setw(31) << "Numerical Grade:" << setprecision(3) << right << setw(12) << percentage << endl;
    
    percentage = letterGrade;
    
    //assign letter grade
    if (letterGrade >= 90)
        fout  << right << setw(31) << "Letter Grade:" << right << setw(30) << "Congrats you go a A!!!" << endl;
    else if (letterGrade >= 90)
        fout << right << setw(31) << "Letter Grade:" << right << setw(30) << "Congrats you go a B!!!" << endl;
    else if (letterGrade >= 70)
        fout << right << setw(31) << "Letter Grade:" << right << setw(30) << "Congrats you go a C!!!" << endl;
    else if (letterGrade >= 60)
        fout << right << setw(31) << "Letter Grade:" << right << setw(30) << "Congrats you go a D!!!" << endl;
    else if (letterGrade <= 50)
        fout << right << setw(31) << "Letter Grade:" << right << setw(30) << "You got a F" << endl;
    else
        fout << "Invaild score" << endl;
    
    //close input and output file
    fin.close();
    fout.close();
    
    return 0;
}
