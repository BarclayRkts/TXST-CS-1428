// Deja Barclay     05/2/2019
//Project #6       Professor Ali, Moonis
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;

int n;  //n = number of students
const int NUMBER_OF_COURSES = 3;
const int NUMBER_OF_SCORES = 6;
const int THREE = 3;
const int TWO =2;
double total;
double average;
double x;
string comment1;
string comment2;

struct Students
{
    struct Courses
    {
        string name;
        double average;
        double scores[5];
        char letterGrade[9];

    };
    string name;
    string id;
    string address;
    string telephone;
    string social;
    int age;
    int years;
    string comment1;
    string comment2;
    string header;
    Courses course[THREE];
};

//function prototypes
void inputData(Students info[]);
void validateData(Students info[]);
void validateData(Students info[]);
void NumGrade(Students info[] );
void LetGrade(Students info[]);
int Comments(double);
void Reports(Students info[]);

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
    Students info[3];

    inputData(info);

    NumGrade(info);

    LetGrade(info);

    Reports(info);

    cout << "Data printed to project6_A04889172_Output.txt" << endl;

}
void inputData(Students info[])
{
    ifstream fin;
    fin.open("project6_A04889172_Input.txt");
    if (!fin)
    {
        cout << "cant open input file" << endl;
    }
    getline(fin, info[0].comment1);
    getline(fin, info[1].comment2);

    for (int i = 0; i < 3; i++)
    {
        getline(fin, info[i].header); //header;
        getline(fin, info[i].name); //name
        getline(fin,info[i].id);    // Id number
        getline(fin, info[i].address);    //address
        getline(fin,info[i].telephone);    //phone number
        getline(fin, info[i].social); //social security
        fin >> info[i].age ;  // age
        fin >> info[i].years ;   //years at texas state
        fin.ignore();

        for (int j = 0; j < NUMBER_OF_COURSES; j++)
        {
            getline(fin, info[i].course[j].name);
            for (int k = 0; k < NUMBER_OF_SCORES -1; k++)
            {
                fin >> info[i].course[j].scores[k];
                //cout << info[i].course[j].scores[k] << endl;
                total += info[i].course[j].scores[k];
                //cout << total << endl;
            }
            fin.ignore(256,'\n');
            //cout << "Total : " << total << endl;
            average = total / 5;
            //total = validateData;
            //courses_Numeric2[i][j][NUMBER_OF_SCORES] = average ;
            //cout<<"Average " << average << endl;
            //total =0;
        }
    }

    validateData(info);

    validateData(info);
    fin.close();
}

void validateData(Students info[]) //non numeric data
{
    for(int i = 0; i < 3; i++)
    {
           if(info[i].header.length() < 1|| info[i].header.length() > 100)
        {
            cout << "student header out of range" << endl;
            continue;
        }

        if(info[i].name.length() < 1|| info[i].name.length() > 100)
        {
            cout << "student name out of range" << endl;
            continue;
        }

        if(info[i].address.length() < 1|| info[i].address.length() > 100)
        {
            cout << "student address out of range" << endl;
            continue;
        }
        if(info[i].id.length() < 1|| info[i].id.length() > 100)
        {
            cout << "student id out of range" << endl;
            continue;
        }
        if(info[i].social.length() < 1|| info[i].social.length() > 100)
        {
            cout << "student social out of range" << endl;
            continue;
        }
        if(info[i].telephone.length() < 1|| info[i].telephone.length() > 100)
        {
            cout << "student telephone out of range" << endl;
            continue;
        }

    }
}

void validateData(Students info[], int i) //numeric data
{
    for(int i = 0; i < 3; i++)
    {
        if ( info[i].age < 1 || info[i].age > 100) // Age Validation
        {
            cout << "Age is out of range" << endl;
            break;
        }
    }

    for(int j = 0; j < 3; j++)
    {
        if ( info[j].years < 1 || info[j].years > 10) //Validation
        {
            cout << "Years at Texas State is out of range" << endl;
            break;
        }
    }
}

void NumGrade( Students info[])
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
                    avg1 =  info[i].course[j].scores[k]*0.10;
                }
                else if(k==1)
                {
                    avg2 =  info[i].course[j].scores[k]*0.15;
                }
                else if(k==2)
                {
                    avg3 =  info[i].course[j].scores[k]*0.20;
                }
                else if(k==3)
                {
                    avg4 = info[i].course[j].scores[k]*0.25;
                }
                else if(k==4)
                {
                    avg5 = info[i].course[j].scores[k]*0.30;
                }

            }
            x= avg1 + avg2 + avg3 +avg4 +avg5;

            // cout << x << endl; // final grade
            info[i].course[j].scores[5] = x;
            //cout <<"Weighted Numerical Grade   " << x << endl;
        }
    }
}

void LetGrade(Students info[])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                 x = info[i].course[j].scores[5];
            //cout<<"\nNumeric grade : "<<x;
            if ( x < 0||x > 100)
            {
                cout<<"Test scores must be in interval 1-100. "<<endl;
            }
            else if (x <60)
            {
                info[i].course[j].letterGrade[k] = 'F';
            }
            else if (x <70)
            {
                info[i].course[j].letterGrade[k]  = 'D';
            }
            else if (x < 80)
            {
                info[i].course[j].letterGrade[k]  = 'C';
            }
            else if (x < 90)
            {
                info[i].course[j].letterGrade[k] = 'B';
            }
            else if  (x <=100)
            {
                info[i].course[j].letterGrade[k]  = 'A';
            }
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

void Reports(Students info[])
{
    string note;
    ofstream fout;
    fout.open("project6_A04889172_Output.txt");
    if (!fout)
    {
        cout << "cant open output file" << endl;
    }
    //Student 1
    fout << right << setw(57) <<info[0].header << endl;
    fout << right << setw(31) << "Name of Student:" << setw(21) << info[0].name  << endl;
    fout << right << setw(31) << "Student ID:" << setw(16) << info[0].id  << endl;
    fout << right << setw(31) << "Address:" << setw(44) << info[0].address  << endl;
    fout << right << setw(31) << "Telephone Number:" << setw(23) << info[0].telephone << endl;
    fout << right << setw(31) << "Student Social Security #:" << setw(18) << info[0].social  << endl;
    fout << right << setw(31) << "Age:" << setw(9) << info[0].age  << endl;
    fout <<"Number of Years at Texas State:" << setw(8) << info[0].years  << endl;
    fout << "" << endl;
    fout << setw(31) << "Course:" << setw(13) << info[0].course[0].name  << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << info[0].course[0].scores[k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< info[0].course[0].scores[5] << endl;
    fout << setw(31) << "Letter Grade:" << setw(8)<<  info[0].course[0].letterGrade[0] << endl;
    int check = Comments(info[0].course[0].scores[5]);
    if(check == 1){
        note  =  info[1].comment2;
    }else if(check == 2){
        note = info[0].comment1;
    }
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "   " << endl;

    fout << setw(31) << "Course:" << setw(13) << info[0].course[1].name  << endl;
        for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << info[0].course[1].scores[k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< info[0].course[1].scores[5] << endl;
    fout << setw(31) << "Letter Grade:" << setw(8)<<  info[0].course[1].letterGrade[1] << endl;
    check = Comments(info[0].course[1].scores[5]);
    if(check == 1){
        note  =  info[1].comment2;
    }else if(check == 2){
        note = info[0].comment1;
    }
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "   " << endl;

    fout << setw(31) << "Course:" << setw(13) << info[0].course[2].name  << endl;
        for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << info[0].course[2].scores[k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< info[0].course[2].scores[5] << endl;
    fout << setw(31) << "Letter Grade:" << setw(8)<<  info[0].course[2].letterGrade[2] << endl;
    check = Comments(info[0].course[2].scores[5]);
    if(check == 1){
        note  =  info[1].comment2;
    }else if(check == 2){
        note = info[0].comment1;
    }
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "   " << endl;
    //Student 2
    fout << right << setw(57) <<info[1].header << endl;
    fout << right << setw(31) << "Name of Student:" << setw(21) << info[1].name  << endl;
    fout << right << setw(31) << "Student ID:" << setw(16) << info[1].id  << endl;
    fout << right << setw(31) << "Address:" << setw(44) << info[1].address  << endl;
    fout << right << setw(31) << "Telephone Number:" << setw(23) << info[1].telephone << endl;
    fout << right << setw(31) << "Student Social Security #:" << setw(18) << info[1].social  << endl;
    fout << right << setw(31) << "Age:" << setw(9) << info[1].age  << endl;
    fout <<"Number of Years at Texas State:" << setw(8) << info[1].years  << endl;
    fout << "" << endl;
    fout << setw(31) << "Course:" << setw(13) << info[1].course[0].name  << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << info[1].course[0].scores[k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< info[1].course[0].scores[5] << endl;
     fout << setw(31) << "Letter Grade:" << setw(8)<<  info[1].course[0].letterGrade[0] << endl;
     check = Comments(info[1].course[0].scores[5]);
    if(check == 1){
        note  =  info[1].comment2;
    }else if(check == 2){
        note = info[0].comment1;
    }
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "   " << endl;

    fout << setw(31) << "Course:" << setw(13) << info[1].course[1].name  << endl;
        for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << info[1].course[1].scores[k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< info[1].course[1].scores[5] << endl;
     fout << setw(31) << "Letter Grade:" << setw(8)<<  info[1].course[1].letterGrade[1] << endl;
      check = Comments(info[1].course[1].scores[5]);
    if(check == 1){
        note  =  info[1].comment2;
    }else if(check == 2){
        note = info[0].comment1;
    }
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "   " << endl;

    fout << setw(31) << "Course:" << setw(13) << info[1].course[2].name  << endl;
        for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << info[1].course[2].scores[k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< info[1].course[2].scores[5] << endl;
     fout << setw(31) << "Letter Grade:" << setw(8)<<  info[1].course[2].letterGrade[2] << endl;
      check = Comments(info[1].course[2].scores[5]);
    if(check == 1){
        note  =  info[1].comment2;
    }else if(check == 2){
        note = info[0].comment1;
    }
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "   " << endl;

    //Student 3
    fout << right << setw(57) <<info[2].header << endl;
    fout << right << setw(31) << "Name of Student:" << setw(21) << info[2].name  << endl;
    fout << right << setw(31) << "Student ID:" << setw(16) << info[2].id  << endl;
    fout << right << setw(31) << "Address:" << setw(44) << info[2].address  << endl;
    fout << right << setw(31) << "Telephone Number:" << setw(23) << info[2].telephone << endl;
    fout << right << setw(31) << "Student Social Security #:" << setw(18) << info[2].social  << endl;
    fout << right << setw(31) << "Age:" << setw(9) << info[2].age  << endl;
    fout <<"Number of Years at Texas State:" << setw(8) << info[2].years  << endl;
    fout << "" << endl;
    fout << setw(31) << "Course:" << setw(13) << info[2].course[0].name  << endl;
    for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << info[2].course[0].scores[k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< info[2].course[0].scores[5] << endl;
     fout << setw(31) << "Letter Grade:" << setw(8)<<  info[2].course[0].letterGrade[0] << endl;
     check = Comments(info[2].course[0].scores[5]);
    if(check == 1){
        note  =  info[1].comment2;
    }else if(check == 2){
        note = info[0].comment1;
    }
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "   " << endl;

    fout << setw(31) << "Course:" << setw(13) << info[2].course[1].name  << endl;
        for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << info[2].course[1].scores[k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< info[2].course[1].scores[5] << endl;
     fout << setw(31) << "Letter Grade:" << setw(8)<<  info[2].course[1].letterGrade[1] << endl;
     check = Comments(info[2].course[1].scores[5]);
    if(check == 1){
        note  =  info[1].comment2;
    }else if(check == 2){
        note = info[0].comment1;
    }
    fout << setw(31) << "Note:" << setw(54) << note << endl;
    fout << "   " << endl;

    fout << setw(31) << "Course:" << setw(13) << info[2].course[2].name  << endl;
        for (int k = 0; k < 5; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << info[2].course[2].scores[k] << endl;
    }
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<<info[2].course[2].scores[5] << endl;
     fout << setw(31) << "Letter Grade:" << setw(8)<<  info[2].course[2].letterGrade[2] << endl;
     check = Comments(info[2].course[2].scores[5]);
    if(check == 1){
        note  =  info[1].comment2;
    }else if(check == 2){
        note = info[0].comment1;
    }
    fout << setw(31) << "Note:" << setw(54) << note << endl;

    fout.close();

}
