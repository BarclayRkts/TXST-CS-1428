// Deja Barclay     04/23/2019
//Project #5        Professor Ali, Moonis
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;

int n;  //n = number of students
const int NUMBER_OF_nonNumerical = 9;
const int NUMBER_OF_COURSES = 3;
const int NUMBER_OF_SCORES = 6;
const int THREE = 3;
const int TWO =2;
double total;
double average;
double x;
string comment1;
string comment2;

string student_nonNumeric1[THREE][NUMBER_OF_nonNumerical]; //store student string information
int student_numeric1 [THREE][TWO]; // store student age and years at Texas State
double courses_Numeric2 [THREE][NUMBER_OF_COURSES][NUMBER_OF_SCORES]; // store three students, three courses and five exams/computed average
char letterGrade [THREE][NUMBER_OF_COURSES]; // store letter grade of three students and three courses

//function prototypes
void inputData(int n, string student_nonNumeric1[][NUMBER_OF_nonNumerical],
               int student_numeric1 [THREE][TWO],
               double courses_Numeric2 [][NUMBER_OF_COURSES][NUMBER_OF_SCORES]);
void validateData(int student_numeric1 [THREE][TWO]);
void validateData(string student_nonNumeric1[][NUMBER_OF_nonNumerical]);

void NumGrade(double courses_Numeric2 [][NUMBER_OF_COURSES][NUMBER_OF_SCORES], int student_numeric1 [THREE][TWO]);
void LetGrade(double x, double courses_Numeric2 [][NUMBER_OF_COURSES][NUMBER_OF_SCORES], char letterGrade [THREE][NUMBER_OF_COURSES]);
int Comments(double);
void Reports(int n, string student_nonNumeric1[][NUMBER_OF_nonNumerical],
             int student_numeric1 [THREE][TWO], double courses_Numeric2 [][NUMBER_OF_COURSES][NUMBER_OF_SCORES]);

int main()
{
    //number of students
    cout << "Enter how many students do you want to see:" << endl;

    cin >> n;
    // Validate the input while loop
    while ( n < 3 || n > 100 )
    {

        cout << "You should have at least 3 students" << endl;

        //get number of students again

        cout << "Enter how many students do you want to see:";

        cin >> n;
    }

    inputData(n, student_nonNumeric1,
              student_numeric1,courses_Numeric2);

    NumGrade(courses_Numeric2, student_numeric1);

    LetGrade(x, courses_Numeric2,letterGrade);

    Reports( n,student_nonNumeric1, student_numeric1,courses_Numeric2);

    cout << "Data printed to project5_A04889172_Output.txt" << endl;

}

void inputData(int n, string student_nonNumeric1[][NUMBER_OF_nonNumerical],
               int student_numeric1 [THREE][TWO], double courses_Numeric2 [][NUMBER_OF_COURSES][NUMBER_OF_SCORES])
{
    ifstream fin;
    fin.open("project5_A04889172_Input.txt");
    if (!fin)
    {
        cout << "cant open input file" << endl;
    }
    getline(fin, comment1);
    getline(fin, comment2);
    //cout << comment1 << endl;
    //cout << comment2 << endl;
    for (int i = 0; i < n; i++)
    {
        getline(fin, student_nonNumeric1[i][0]); //header;

        getline(fin, student_nonNumeric1[i][1]); //name
        //fout << student_nonNumeric1[i][1];
        getline(fin, student_nonNumeric1[i][2]);    // Id number
        getline(fin, student_nonNumeric1[i][3]);    //address
        getline(fin, student_nonNumeric1[i][4]);    //phone number
        getline(fin, student_nonNumeric1[i][5]);    //social security
        fin >> student_numeric1[i][0];  // age
        fin >> student_numeric1[i][1];   //years at texas state
        fin.ignore();

        for (int j = 0; j < NUMBER_OF_COURSES; j++)
        {
            getline(fin, student_nonNumeric1[i][6+j]);
            for (int k = 0; k < NUMBER_OF_SCORES -1; k++)
            {
                fin >> courses_Numeric2[i][j][k];
                //cout << "Test Scores : " << courses_Numeric2[i][j][k] << endl;
                total += courses_Numeric2[i][j][k];
                //cout << total << endl;
            }
            fin.ignore(256,'\n');
            //cout << "Total : " << total << endl;
            average = total / 5;
            //total = validateData;
            courses_Numeric2[i][j][NUMBER_OF_SCORES] = average ;
            //cout<<"Average " << average << endl;
        }
    }
    validateData(student_nonNumeric1);

    validateData(student_numeric1);
    fin.close();
}
void validateData(string student_nonNumeric1[][NUMBER_OF_nonNumerical]) //non numeric data
{
    for(int i = 0; i < 3; i++)
        {
           if(student_nonNumeric1[i][i].length() < 1|| student_nonNumeric1[i][i].length() > 100)
        {
            cout << "student_nonNumeric1 out of range" << endl;
            continue;
        }

        }
}
void validateData(int student_numeric1 [THREE][TWO]) //numeric data
{
    for(int i = 0; i < 3; i++)
    {
        if ( student_numeric1[i][0] < 1 || student_numeric1[i][0] > 100) // Age Validation
        {
            cout << "Age is out of range" << endl;
            break;
        }
    }

    for(int j = 0; j < 3; j++)
    {
        if ( student_numeric1[j][1] < 1 || student_numeric1[j][1] > 10) //Validation
        {
            cout << "Years at Texas State is out of range" << endl;
            break;
        }
    }

}

void NumGrade(double courses_Numeric2 [][NUMBER_OF_COURSES][NUMBER_OF_SCORES], int student_numeric1 [THREE][TWO])
{
    double avg1,avg2,avg3,avg4,avg5;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            for( int k =0; k<5; k++)
            {
                if(k==0)
                {
                    avg1 =  courses_Numeric2[i][j][k]*0.10;
                }
                else if(k==1)
                {
                    avg2 =  courses_Numeric2[i][j][k]*0.15;
                }
                else if(k==2)
                {
                    avg3 =  courses_Numeric2[i][j][k]*0.20;
                }
                else if(k==3)
                {
                    avg4 = courses_Numeric2[i][j][k]*0.25;
                }
                else if(k==4)
                {
                    avg5 = courses_Numeric2[i][j][k]*0.30;
                }

            }
            x= avg1 + avg2 + avg3 +avg4 +avg5;

            // cout << x << endl; // final grade
            courses_Numeric2[i][j][5] = x;
        }
    }
}

void LetGrade(double x,double courses_Numeric2 [][NUMBER_OF_COURSES][NUMBER_OF_SCORES], char letterGrade[THREE][NUMBER_OF_COURSES])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            x = courses_Numeric2[i][j][5];
            //cout<<"\nNumeric grade : "<<x;
            if ( x < 0||x > 100)
            {
                cout<<"Test scores must be in interval 1-100. "<<endl;
            }

            else if (x <60)
            {
                letterGrade[i][j] = 'F';
            }
            else if (x <70)
            {
                letterGrade[i][j] = 'D';
            }
            else if (x < 80)
            {
                letterGrade[i][j] = 'C';
            }
            else if (x < 90)
            {
                letterGrade[i][j] = 'B';
            }
            else if  (x <=100)
            {
                letterGrade[i][j] = 'A';
            }
        }
    }
}

int Comments(double value)
{
    int note = 0;
    // Warning Note
    if(value < 70)
    {
        note = 1;
    }
    else if (value >= 95) //Good Note
    {
        note = 2;
    }
    return note;
}

void Reports(int n, string student_nonNumeric1[][NUMBER_OF_nonNumerical],
             int student_numeric1 [THREE][TWO], double courses_Numeric2 [][NUMBER_OF_COURSES][NUMBER_OF_SCORES])
{
    string note;

    ofstream fout;
    fout.open("project5_A04889172_Output.txt");
    if (!fout)
    {
        cout << "cant open output file" << endl;
    }
    //Student 1
    fout << right << setw(57) << student_nonNumeric1[0][0] << endl;
    fout << right << setw(31) << "Name of Student:" << setw(21) << student_nonNumeric1[0][1] << endl;
    fout << right << setw(31) << "Student ID:" << setw(16) << student_nonNumeric1[0][2] << endl;
    fout << right << setw(31) << "Address:" << setw(44) << student_nonNumeric1[0][3] << endl;
    fout << right << setw(31) << "Telephone Number:" << setw(23) << student_nonNumeric1[0][4] << endl;
    fout << right << setw(31) << "Student Social Security #:" << setw(18) << student_nonNumeric1[0][5] << endl;
    fout << right << setw(31) << "Age:" << setw(9) << student_numeric1[0][0] << endl;
    fout <<"Number of Years at Texas State:" << setw(8) << student_numeric1[0][1] << endl;
    fout << "" << endl;
    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[0][6] << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[0][0][k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< courses_Numeric2[0][0][5] << endl;
    int check = Comments(courses_Numeric2[0][0][5]);

    if(check == 1){
        note  =  comment2;
    }else if(check == 2){
        note = comment1;
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[0][0] << endl;
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "" << endl;

    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[0][7] << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[0][1][k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< courses_Numeric2[0][1][5] << endl;
    check = Comments(courses_Numeric2[0][1][5]);

    if(check == 1){
        note  =  comment2;
    }else if(check == 2){
        note = comment1;
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[0][1] << endl;
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "" << endl;

    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[0][8] << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[0][2][k] << endl;
    }

    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< courses_Numeric2[0][2][5] << endl;
    check = Comments(courses_Numeric2[0][2][5]);

    if(check == 1){
        note  =  comment2;
    }else if(check == 2){
        note = comment1;
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[0][2] << endl;
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "" << endl;

    //Student 2
    fout << right << setw(57) << student_nonNumeric1[1][0] << endl;
    fout << right << setw(31) << "Name of Student:" << setw(21) << student_nonNumeric1[1][1] << endl;
    fout << right << setw(31) << "Student ID:" << setw(16) << student_nonNumeric1[1][2] << endl;
    fout << right << setw(31) << "Address:" << setw(44) << student_nonNumeric1[1][3] << endl;
    fout << right << setw(31) << "Telephone Number:" << setw(23) << student_nonNumeric1[1][4] << endl;
    fout << right << setw(31) << "Student Social Security #:" << setw(18) << student_nonNumeric1[1][5] << endl;
    fout << right << setw(31) << "Age:" << setw(9) << student_numeric1[1][0] << endl;
    fout <<"Number of Years at Texas State:" << setw(8) << student_numeric1[1][1] << endl;
    fout << "" << endl;
    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[1][6] << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[1][0][k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< courses_Numeric2[1][0][5] << endl;
    check = Comments(courses_Numeric2[1][0][5]);

    if(check == 1){
        note  =  comment2;
    }else if(check == 2){
        note = comment1;
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[0][0] << endl;
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "" << endl;

    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[1][7] << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[1][1][k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< courses_Numeric2[1][1][5] << endl;
    check = Comments(courses_Numeric2[1][1][5]);

    if(check == 1){
        note  =  comment2;
    }else if(check == 2){
        note = comment1;
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[1][1] << endl;
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout <<""<< endl;

    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[1][8] << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[1][2][k] << endl;
    }

    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< courses_Numeric2[1][2][5] << endl;
    check = Comments(courses_Numeric2[1][2][5]);

    if(check == 1){
        note  =  comment2;
    }else if(check == 2){
        note = comment1;
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[1][2] << endl;
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "" << endl;

    //Student 3
    fout << right << setw(57) << student_nonNumeric1[2][0] << endl;
    fout << right << setw(31) << "Name of Student:" << setw(21) << student_nonNumeric1[2][1] << endl;
    fout << right << setw(31) << "Student ID:" << setw(16) << student_nonNumeric1[2][2] << endl;
    fout << right << setw(31) << "Address:" << setw(44) << student_nonNumeric1[2][3] << endl;
    fout << right << setw(31) << "Telephone Number:" << setw(23) << student_nonNumeric1[2][4] << endl;
    fout << right << setw(31) << "Student Social Security #:" << setw(18) << student_nonNumeric1[2][5] << endl;
    fout << right << setw(31) << "Age:" << setw(9) << student_numeric1[2][0] << endl;
    fout <<"Number of Years at Texas State:" << setw(8) << student_numeric1[2][1] << endl;
    fout << "" << endl;
    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[2][6] << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[2][0][k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< courses_Numeric2[2][0][5] << endl;
    check = Comments(courses_Numeric2[2][0][5]);

    if(check == 1){
        note  =  comment2;
    }else if(check == 2){
        note = comment1;
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[2][0] << endl;
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "" << endl;

    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[2][7] << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[2][1][k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< courses_Numeric2[2][1][5] << endl;
    check = Comments(courses_Numeric2[2][1][5]);

   if(check == 1){
        note  =  comment2;
    }else if(check == 2){
        note = comment1;
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[2][1] << endl;
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "" << endl;

    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[2][8] << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[2][2][k] << endl;
    }

    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< courses_Numeric2[2][2][5] << endl;
    check = Comments(courses_Numeric2[2][2][5]);

    if(check == 1){
        note  =  comment2;
    }else if(check == 2){
        note = comment1;
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[2][2] << endl;
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    //output file
    fout.close();
}
