
// Deja Barclay     04/09/2019
//Project #4        Professor Ali, Moonis
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;

int main()
{
    double average;
    double total;

    int n = 3;  //n = number of students

    const int NUMBER_OF_nonNumerical = 9;

    const int NUMBER_OF_COURSES = 3;

    const int NUMBER_OF_SCORES = 5;
    const int THREE = 3;
    const int TWO =2;

    string student_nonNumeric1[n][NUMBER_OF_nonNumerical]; //store student string information

    int student_numeric1 [THREE][TWO]; // store student age and years at Texas State

    double courses_Numeric2 [n][NUMBER_OF_COURSES][NUMBER_OF_SCORES]; // store three students, three courses and five exams/computed average

    char letterGrade [THREE][NUMBER_OF_COURSES]; // store letter grade of three students and three courses

    //number of students
    cout << "Enter how many students do you want to see:" << endl;

    cin >> n;
    // Validate the input while loop
    while (n > 3 || n < 3 )
    {

        cout << "You should have exactly 3 students" << endl;

        //get number of students again

        cout << "Enter how many students do you want to see:";

        cin >> n;

    }
    //Open Input and Output file
    ifstream fin;

    fin.open("project4_A04889172_Input.txt");

    if (!fin) {

        cout << "could not open file" << endl;

        return -1;

    }
    ofstream fout;

    fout.open("project4_A04889172_Output.txt");

    if (!fout) {

        cout << "could not open file" << endl;

        return -1;

    }

    for (int i = 0; i < n; i++)
    {
        getline(fin, student_nonNumeric1[i][0]); //header;

        getline(fin, student_nonNumeric1[i][1]); //name
        getline(fin, student_nonNumeric1[i][2]);    // Id number
        getline(fin, student_nonNumeric1[i][3]);    //address
        getline(fin, student_nonNumeric1[i][4]);    //phone number
        getline(fin, student_nonNumeric1[i][5]);    //social security
        if(student_nonNumeric1[i][i].length() < 1|| student_nonNumeric1[i][i].length() > 100)
        {
            cout << "student_nonNumeric1 out of range" << endl;
            continue;
        }

        fin >> student_numeric1[i][0];  // age
        if ( student_numeric1[i][0] < 1 || student_numeric1[i][0] > 100) // Age Validation
        {
            cout << "Age is out of range" << endl;
            break;
        }
        fin >> student_numeric1[i][1];  //years at texas state
        if ( student_numeric1[i][1] < 1 || student_numeric1[i][1] > 10) //Validation
        {
            cout << "Years at Texas State is out of range" << endl;
            break;
        }
        fin.ignore();

        for (int j = 0, z = 6; j < NUMBER_OF_COURSES; j++, z++)
        {

            getline(fin, student_nonNumeric1[i][z]);
            if( student_nonNumeric1[i][z].length() > 50)
                {
                    cout << "Data is longer than string length" << endl;
                    continue;
                }


            total = 0;

            for (int k = 0; k < NUMBER_OF_SCORES; k++)
            {

                fin >> courses_Numeric2[i][j][k];
                if(courses_Numeric2[i][j][k] < 1 || courses_Numeric2[i][j][k] > 100)
                {
                    cout << "Numbers are out of the range" << endl;
                    break;
                }

                total += courses_Numeric2[i][j][k];

            }
            average = total / 5;
            courses_Numeric2[i][j][NUMBER_OF_SCORES] = average;
            fin.ignore();
        }
    }

    float avg1,avg2,avg3,avg4,avg5;
    float x;
    for(int i =0;i<3 ; i++)
    {
        for(int j=0;j<3; j++)
        {

            for(int k=0;k<5 ; k++)
            {
                if(k==0)
                {
                    avg1 =  (courses_Numeric2[i][j][k])*0.10;
                }
                else if(k==1)
                {
                    avg2 =  (courses_Numeric2[i][j][k])*0.15;
                }
                else if(k==2)
                {
                    avg3 =  (courses_Numeric2[i][j][k])*0.20;
                }
                else if(k==3)
                {
                    avg4 =  (courses_Numeric2[i][j][k])*0.25;
                }
                else if(k==4)
                {
                    avg5 =  (courses_Numeric2[i][j][k])*0.30;
                }
            }
            x= avg1 + avg2 + avg3 +avg4 +avg5;
        }
    }
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

    for (int k = 0; k < NUMBER_OF_SCORES; k++)
    {
        fout<< setprecision(2) << fixed << right << setw(31) << "Test:" << setw(12) << courses_Numeric2[0][0][k] << endl;

    }
    for( int k =0;k<5;k++)
    {

        if(k==0)
        {
            avg1 =  (courses_Numeric2[0][0][k])*0.10;
        }
        else if(k==1)
        {
            avg2 =  (courses_Numeric2[0][0][k])*0.15;
        }
        else if(k==2)
        {
            avg3 =  (courses_Numeric2[0][0][k])*0.20;
        }
        else if(k==3)
        {
            avg4 = (courses_Numeric2[0][0][k])*0.25;
        }
        else if(k==4)
        {
            avg5 = (courses_Numeric2[0][0][k])*0.30;
        }
    }
    x= avg1 + avg2 + avg3 +avg4 +avg5;
    fout << setprecision(2) << fixed << setw(32) << "Numerical Grade:" << setw(11)<< x<<endl;
    if ( x < 0||x > 100)
    {
        cout<<"Test scores must be in interval 1-100. "<<endl;
    }

    else if (x <60)
    {
        letterGrade[0][0] = 'F';
    }
    else if (x <70)
    {
        letterGrade[0][0] = 'D';
    }
    else if (x < 80)
    {
        letterGrade[0][0] = 'C';
    }
    else if (x < 90)
    {
        letterGrade[0][0] = 'B';
    }
    else if  (x <=100)
    {
        letterGrade[0][0] = 'A';
    }

    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[0][0];

    fout << "" << endl;

    // Warning Note
    if(x < 70)
    {
        fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
        fout << "" << endl;
    }
    else if (x >= 95)
    {
        fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
        fout << "" << endl;
    }
    else
    {
        fout << right << setw(31) << "No Note:" << endl;
        fout << "" << endl;
    }

    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[0][7] << endl;

    for (int k = 0; k < NUMBER_OF_SCORES; k++)
    {
        fout<< right << setw(31) << "Test:" << setw(12) << courses_Numeric2[0][1][k]<< endl;
    }
    for( int k =0;k<5;k++)
    {

        if(k==0)
        {
            avg1 =  (courses_Numeric2[0][1][k])*0.10;
        }
        else if(k==1)
        {
            avg2 =  (courses_Numeric2[0][1][k])*0.15;
        }
        else if(k==2)
        {
            avg3 =  (courses_Numeric2[0][1][k])*0.20;
        }
        else if(k==3)
        {
            avg4 = (courses_Numeric2[0][1][k])*0.25;

        }
        else if(k==4)
        {
            avg5 = (courses_Numeric2[0][1][k])*0.30;
        }


    }
    x= avg1 + avg2 + avg3 +avg4 +avg5;
    fout << setprecision(2) << fixed << setw(31) << "Numerical Grade:" << setw(12)<< x<<endl;
    if ( x < 0||x > 100)
    {
        cout<<"Test scores must be in interval 1-100. "<<endl;
        cout<<"Please exit the program and run it again"<<endl;
    }
    else if (x <60)
    {
        letterGrade[0][1] = 'F';
    }
    else if (x <70 && x >= 60)
    {
        letterGrade[0][1] = 'D';
    }
    else if (x < 80 && x >= 70)
    {
        letterGrade[0][1] = 'C';
    }
    else if (x < 90 && x >= 80)
    {
        letterGrade[0][1] = 'B';
    }
    else if  (x <=100 && x >= 90)
    {
        letterGrade[0][1] = 'A';
    }

    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[0][1];
    fout << "" << endl;
    // Warning Note
    if(x < 70)
    {
        fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
        fout << "" << endl;
    }
    else if (x >= 95)
    {
        fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
        fout << "" << endl;
    }
    else
    {
        fout << right << setw(31) << "No Note:" << endl;
        fout << "" << endl;
    }

    fout << setw(31) << "Course:" << setw(13) <<  student_nonNumeric1[0][8] << endl;

    for (int k = 0; k < NUMBER_OF_SCORES; k++)
    {
        fout<< right << setw(31) << "Test:" << setw(12) << courses_Numeric2[0][2][k]<< endl;
    }
    for( int k =0;k<5;k++)
    {

        if(k==0)
        {
            avg1 =  (courses_Numeric2[0][2][k])*0.10;
        }
        else if(k==1)
        {
            avg2 =  (courses_Numeric2[0][2][k])*0.15;
        }
        else if(k==2)
        {
            avg3 =  (courses_Numeric2[0][2][k])*0.20;
        }
        else if(k==3)
        {
            avg4 = (courses_Numeric2[0][2][k])*0.25;
        }
        else if(k==4)
        {
            avg5 = (courses_Numeric2[0][2][k])*0.30;
        }
    }
    x= avg1 + avg2 + avg3 +avg4 +avg5;
    fout << setprecision(2) << fixed << setw(31) << "Numerical Grade:" << setw(12)<< x<<endl;

    if ( x < 0||x > 100)
    {
        cout<<"Test scores must be in interval 1-100. "<<endl;
        cout<<"Please exit the program and run it again"<<endl;
        return 0;
    }
    else if (x <60 )
    {
        letterGrade[0][2] = 'F';
    }
    else if (x <70 && x >= 60)
    {
        letterGrade[0][2] = 'D';
    }
    else if (x < 80 && x >= 70)
    {
        letterGrade[0][2] = 'C';
    }
    else if (x < 90 && x >= 80)
    {
        letterGrade[0][2] = 'B';
    }
    else if  (x <=100 && x >= 90)
    {
        letterGrade[0][2] = 'A';
    }

    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[0][2];
    fout << "" << endl;
    // Warning Note
    if(x < 70)
    {
        fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
        fout << "" << endl;
    }
    else if (x >= 95)
    {
        fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
        fout << "" << endl;
    }
    else
    {
        fout << right << setw(31) << "No Note:" << endl;
        fout << "" << endl;
    }


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

    for (int k = 0; k < NUMBER_OF_SCORES; k++)
    {
        fout<< right << setw(31) << "Test:" << setw(12) << courses_Numeric2[1][0][k] << endl;
    }
    for( int k =0;k<5;k++)
    {

        if(k==0)
        {
            avg1 =  (courses_Numeric2[1][0][k])*0.10;
        }
        else if(k==1)
        {
            avg2 =  (courses_Numeric2[1][0][k])*0.15;
        }
        else if(k==2)
        {
            avg3 =  (courses_Numeric2[1][0][k])*0.20;
        }
        else if(k==3)
        {
            avg4 = (courses_Numeric2[1][0][k])*0.25;
        }
        else if(k==4)
        {
            avg5 = (courses_Numeric2[1][0][k])*0.30;
        }
    }
    x= avg1 + avg2 + avg3 +avg4 +avg5;
    fout << setprecision(2) << fixed << setw(31) << "Numerical Grade:" << setw(12)<< x<<endl;
    if ( x < 0||x > 100)
    {
        cout<<"Test scores must be in interval 1-100. "<<endl;
        cout<<"Please exit the program and run it again"<<endl;
        return 0;
    }
    else if (x <60)
    {
        letterGrade[1][0] = 'F';
    }
    else if (x <70 && x >= 60)
    {
        letterGrade[1][0] = 'D';
    }
    else if (x < 80 && x >= 70)
    {
        letterGrade[1][0] = 'C';
    }
    else if (x < 90 && x >= 80)
    {
        letterGrade[1][0] = 'B';
    }
    else if  (x <=100 && x >= 90)
    {
        letterGrade[1][0] = 'A';
    }

    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[1][0];
    fout << "" << endl;
    // Warning Note
    if(x < 70)
    {
        fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
        fout << "" << endl;
    }
    else if (x >= 95)
    {
        fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
        fout << "" << endl;
    }
    else
    {
        fout << right << setw(31) << "No Note:" << endl;
        fout << "" << endl;
    }

    fout << setw(31) << "Course:" << setw(13) <<  student_nonNumeric1[1][7] << endl;

    for (int k = 0; k < NUMBER_OF_SCORES; k++)
    {
        fout<< right << setw(31) << "Test:" << setw(12) << courses_Numeric2[1][1][k]<< endl;
    }
    for( int k =0;k<5;k++)
    {

        if(k==0)
        {
            avg1 =  (courses_Numeric2[1][1][k])*0.10;
        }
        else if(k==1)
        {
            avg2 =  (courses_Numeric2[1][1][k])*0.15;
        }
        else if(k==2)
        {
            avg3 =  (courses_Numeric2[1][1][k])*0.20;
        }
        else if(k==3)
        {
            avg4 = (courses_Numeric2[1][1][k])*0.25;
        }
        else if(k==4)
        {
            avg5 = (courses_Numeric2[1][1][k])*0.30;
        }
    }
    x= avg1 + avg2 + avg3 +avg4 +avg5;
    fout << setprecision(2) << fixed << setw(31) << "Numerical Grade:" << setw(12)<< x<<endl;
    if ( x < 0||x > 100)
    {
        cout<<"Test scores must be in interval 1-100. "<<endl;
        cout<<"Please exit the program and run it again"<<endl;
        return 0;
    }
    else if (x <60)
    {
        letterGrade[1][1] = 'F';
    }
    else if (x <70 && x >= 60)
    {
        letterGrade[1][1] = 'D';
    }
    else if (x < 80 && x >= 70)
    {
        letterGrade[1][1] = 'C';
    }
    else if (x < 90 && x >= 80)
    {
        letterGrade[1][1] = 'B';
    }
    else if  (x <=100 && x >= 90)
    {
        letterGrade[1][1] = 'A';
    }

    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[1][1];
    fout << "" << endl;
    // Warning Note
    if(x < 70)
    {
        fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
        fout << "" << endl;
    }
    else if (x >= 95)
    {
        fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
        fout << "" << endl;
    }
    else
    {
        fout << right << setw(31) << "No Note:" << endl;
        fout << "" << endl;
    }

    fout << setw(31) << "Course:" << setw(13) <<  student_nonNumeric1[1][8] << endl;

    for (int k = 0; k < NUMBER_OF_SCORES; k++)
    {
        fout<< right << setw(31) << "Test:" << setw(12) << courses_Numeric2[1][2][k]<< endl;
    }
    //Calculate weighted average of each test
    for( int k =0;k<5;k++)
    {

        if(k==0)
        {
            avg1 =  (courses_Numeric2[1][2][k])*0.10;

        }
        else if(k==1)
        {
            avg2 =  (courses_Numeric2[1][2][k])*0.15;
        }
        else if(k==2)
        {
            avg3 =  (courses_Numeric2[1][2][k])*0.20;
        }
        else if(k==3)
        {
            avg4 = (courses_Numeric2[1][2][k])*0.25;
        }
        else if(k==4)
        {
            avg5 = (courses_Numeric2[1][2][k])*0.30;
        }
    }
    x= avg1 + avg2 + avg3 +avg4 +avg5;
    fout << setprecision(2) << fixed << setw(31) << "Numerical Grade:" << setw(12)<< x<<endl;
    if ( x < 0||x > 100)
    {
        cout<<"Test scores must be in interval 1-100. "<<endl;
        cout<<"Please exit the program and run it again"<<endl;
        return 0;
    }
    else if (x <60)
    {
        letterGrade[1][2] = 'F';
    }
    else if (x <70 && x >= 60)
    {
        letterGrade[1][2] = 'D';
    }
    else if (x < 80 && x >= 70)
    {
        letterGrade[1][2] = 'C';
    }
    else if (x < 90 && x >= 80)
    {
        letterGrade[1][2] = 'B';
    }
    else if  (x <=100 && x >= 90)
    {
        letterGrade[1][2] = 'A';
    }

    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[1][2];
    fout << "" << endl;
    // Warning Note
    if(x < 70)
    {
        fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
        fout << "" << endl;
    }
    else if (x >= 95)
    {
        fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
        fout << "" << endl;
    }
    else
    {
        fout << right << setw(31) << "No Note:" << endl;
        fout << "" << endl;
    }

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
        fout<< right << setw(31) << "Test:" << setw(12) << courses_Numeric2[2][0][k] << endl;
    }

    for( int k =0;k<5;k++)
    {

        if(k==0)
        {
            avg1 =  (courses_Numeric2[2][0][k])*0.10;
        }
        else if(k==1)
        {
            avg2 =  (courses_Numeric2[2][0][k])*0.15;
        }
        else if(k==2)
        {
            avg3 =  (courses_Numeric2[2][0][k])*0.20;
        }
        else if(k==3)
        {
            avg4 = (courses_Numeric2[2][0][k])*0.25;
        }
        else if(k==4)
        {
            avg5 = (courses_Numeric2[2][0][k])*0.30;
        }
    }
    x= avg1 + avg2 + avg3 +avg4 +avg5;
    fout << setprecision(2) << fixed << setw(31) << "Numerical Grade:" << setw(12)<< x<<endl;
    if ( x < 0||x > 100)
    {
        cout<<"Test scores must be in interval 1-100. "<<endl;
        cout<<"Please exit the program and run it again"<<endl;
        return 0;
    }
    else if (x <60)
    {
        letterGrade[2][0] = 'F';
    }
    else if (x <70 && x >= 60)
    {
        letterGrade[2][0] = 'D';
    }
    else if (x < 80 && x >= 70)
    {
        letterGrade[2][0] = 'C';
    }
    else if (x < 90 && x >= 80)
    {
        letterGrade[2][0] = 'B';
    }
    else if  (x <=100 && x >= 80)
    {
        letterGrade[2][0] = 'A';
    }

    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[2][0];
    fout << "" << endl;
    // Warning Note
    if(x < 70)
    {
        fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
        fout << "" << endl;
    }
    else if (x >= 95)
    {
        fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
        fout << "" << endl;
    }
    else
    {
        fout << right << setw(31) << "No Note:" << endl;
        fout << "" << endl;
    }

    fout << setw(31) << "Course:" << setw(13) << student_nonNumeric1[2][7] << endl;

    for (int k = 0; k < NUMBER_OF_SCORES; k++)
    {
        fout<< right << setw(31) << "Test:" << setw(12) << courses_Numeric2[02][1][k]<< endl;
    }
    for( int k =0;k<5;k++)
    {

        if(k==0)
        {
            avg1 =  (courses_Numeric2[2][1][k])*0.10;
        }
        else if(k==1)
        {
            avg2 =  (courses_Numeric2[2][1][k])*0.15;

        }
        else if(k==2)
        {
            avg3 =  (courses_Numeric2[2][1][k])*0.20;

        }
        else if(k==3)
        {
            avg4 = (courses_Numeric2[2][1][k])*0.25;

        }
        else if(k==4)
        {
            avg5 = (courses_Numeric2[2][1][k])*0.30;
        }
    }
    x= avg1 + avg2 + avg3 +avg4 +avg5;
    fout << setprecision(2) << fixed << setw(31) << "Numerical Grade:" << setw(12)<< x<<endl;
    if ( x < 0||x > 100)
    {
        cout<<"Test scores must be in interval 1-100. "<<endl;
        cout<<"Please exit the program and run it again"<<endl;
        return 0;
    }
    else if (x <60)
    {
        letterGrade[2][1] = 'F';
    }
    else if (x <70 && x >= 60)
    {
        letterGrade[2][1] = 'D';
    }
    else if (x < 80 && x >= 70)
    {
        letterGrade[2][1] = 'C';
    }
    else if (x < 90 && x >= 80)
    {
        letterGrade[2][1] = 'B';
    }
    else if  (x <=100 && x >= 90)
    {
        letterGrade[2][1] = 'A';
    }

    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[2][1];
    fout << "" << endl;

    // Warning Note
    if(x < 70)
    {
        fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
        fout << "" << endl;
    }
    else if (x >= 95)
    {
        fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
        fout << "" << endl;
    }
    else
    {
        fout << right << setw(31) << "No Note:" << endl;
        fout << "" << endl;
    }

    fout << setw(31) << "Course:" << setw(13) <<  student_nonNumeric1[2][8] << endl;

    for (int k = 0; k < NUMBER_OF_SCORES; k++)
    {
        fout<< right << setw(31) << "Test:" << setw(12) << courses_Numeric2[2][2][k]<< endl;
    }
    for( int k =0;k<5;k++)
    {

        if(k==0)
        {
            avg1 =  (courses_Numeric2[2][2][k])*0.10;
        }
        else if(k==1)
        {
            avg2 =  (courses_Numeric2[2][2][k])*0.15;
        }
        else if(k==2)
        {
            avg3 =  (courses_Numeric2[2][2][k])*0.20;
        }
        else if(k==3)
        {
            avg4 = (courses_Numeric2[2][2][k])*0.25;
        }
        else if(k==4)
        {
            avg5 = (courses_Numeric2[2][2][k])*0.30;
        }
    }
    x= avg1 + avg2 + avg3 +avg4 +avg5;
    fout << setprecision(2) << fixed << setw(31) << "Numerical Grade:" << setw(12)<< x<<endl;
    if ( x < 0||x > 100)
    {
        cout<<"Test scores must be in interval 1-100. "<<endl;
        cout<<"Please exit the program and run it again"<<endl;
        return 0;
    }
    else if (x <60)
    {
        letterGrade[2][2] = 'F';
    }
    else if (x <70 && x >= 60)
    {
        letterGrade[2][2] = 'D';
    }
    else if (x < 80 && x >= 70)
    {
        letterGrade[2][2] = 'C';
    }
    else if (x < 90 && x >= 80)
    {
        letterGrade[2][2] = 'B';
    }
    else if  (x <=100 && x >= 90)
    {
        letterGrade[2][2] = 'A';
    }
    fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade[2][2] << endl;
    // Warning Note
    if(x < 70)
    {
        fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
        fout << "" << endl;
    }
    else if (x >= 95)
    {
        fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
        fout << "" << endl;
    }
    else
    {
        fout << right << setw(31) << "No Note:" << endl;
        fout << "" << endl;
    }
    cout << "Data written to project4_A04889172_Output.txt" << endl;

    // Close input and output file
    fin.close();
    fout.close();
    return 0;
}




