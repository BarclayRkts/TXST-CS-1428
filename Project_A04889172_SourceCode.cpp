// Deja Barclay     03/07/2019
//Project #3        Professor Ali, Moonis

#include <iostream>

#include <fstream>

#include <string>

#include<iomanip>

using namespace std;



int main()

{

    string name, social, address, telephone, course, header;

    int n, age, years;

    double test=0.0;

    double total=0.0;

    char letterGrade;

    const int NUMBER_OF_COURSES = 3;

    const int NUMBER_OF_SCORES = 5;

    int min_students = 1,

        max_students = 100;

    //number of students

    cout << "Enter how many students do you want to see:" << endl;

    cin >> n;

    // Validate the input while loop

    while (n < min_students || n > max_students )

    {

        cout << "You should have at least "<< min_students << " student"
        << " and more than " << max_students << " students" << endl;

        //get number of students again

        cout << "Enter how many students do you want to see:";

        cin >> n;

    }

    //Open Input and Output file

    ifstream fin;

    fin.open("project3_A04889172_Input.txt");

    if (!fin) {

        cout << "could not open file" << endl;

        return -1;

    }

    ofstream fout;


    fout.open("project3_A04889172_Output.txt");

    if (!fout) {

        cout << "could not open file" << endl;

        return -1;

    }


    // Gather data from input file

    for (int i = 0; i < n; i++) {

        getline(fin,header);

        if( header.length() > 30)
        {
            cout << "Keep length between 1-30" << endl;
            continue;
        }

        getline(fin,name);

        if( name.length() > 30)
        {
            cout << "Keep length between 1-30" << endl;
            continue;
        }

        fin >> age;
        if(age > 100)
        {
            cout << "Keep age within range" << endl;
            continue;
        }


        fin.ignore();

        getline(fin,address);

        if( address.length() > 50)
        {
            cout << "Keep length between 1-50" << endl;
            continue;
        }

        fin >> years;
        if(years > 20)
        {
            cout << "Keep years within range" << endl;
            continue;
        }

        fin.ignore();

        getline(fin,telephone);

        if( telephone.length() > 20)
        {
            cout << "Keep length between 1-20" << endl;
            continue;
        }

        getline(fin,social);

        if( social.length() > 20)
        {
            cout << "Keep length between 1-20" << endl;
            continue;
        }

        fout << right << setw(43) << header << endl;
        fout << right << setw(31) << "Name of Student:" << setw(21) << name << endl;
        fout << right << setw(31) << "Age:" << setw(9) << age << endl;
        fout << right << setw(31) << "Address:" << setw(44) << address << endl;
        fout <<"Number of Years at Texas State:" << setw(8) << years << endl;
        fout << right << setw(31) << "Telephone Number:" << setw(23) << telephone << endl;
        fout << right << setw(31) << "Student Social Security #:" << setw(18) << social << endl;


        for (int j = 0; j < NUMBER_OF_COURSES; j++) {
            fin.ignore();

            getline(fin,course);

            if( course.size() > 50)
            break;

            fout << setw(31) << "Course:" << setw(12) << course << endl;

            double totalWeight = 0.0;
            for (int k = 0; k < NUMBER_OF_SCORES; k++) {
            double currentSubWeight = 0.0;

                fin >> test;

                total = total + test;

                fin.ignore();

                fout<< right << setw(31) << "Test:" << setw(11) << test << endl;

                // Assign Different weights to each test
                if( k == 0 )
                {
                    currentSubWeight = test * 10;
                }
                else if( k == 1 )
                {
                    currentSubWeight = test * 15;
                }
                else if(k == 2)
                {
                    currentSubWeight = test * 20;
                }
                else if(k==3)
                {
                    currentSubWeight = test * 25;
                }
                else if(k==4)
                {
                    currentSubWeight = test * 30;
                }
                else
                {
                    fout << "Not Valid";
                }

              totalWeight = totalWeight+ (currentSubWeight/100);

              if(totalWeight > 100 || totalWeight < 1)
              {
                 cout << "Numerical grade is not within range";
                 break;
              }

                }


                fout << setprecision(1) << fixed << setw(31) << "Numerical Grade:" << setw(11) << totalWeight << endl;

        // Assign a grade
        if (totalWeight<0 || totalWeight >100)
        {
		cout<<"Test scores must be in interval 1-100. "<<endl;
		cout<<"Please exit the program and run it again"<<endl;
		return 0;
        }
        else if (totalWeight <60)
        {
            letterGrade = 'F';
        }
        else if (totalWeight <70)
        {
            letterGrade = 'D';
        }
        else if (totalWeight < 80)
        {
            letterGrade = 'C';
        }
        else if (totalWeight < 90)
        {
            letterGrade = 'B';
        }
        else if  (totalWeight <=100)
        {
            letterGrade = 'A';
        }

        fout << setw(31) << "Letter Grade:" << setw(8)<< letterGrade << endl;

        // Warning Note
        if(totalWeight < 70)
        {
            fout << right << setw(31) << "Warning Note:" << setw(52) << "Your grade is too low and needs improvements." << endl;
            fout << "" << endl;
        }
        else if (totalWeight >= 95)
        {
            fout << right << setw(31) << "Appreciation Note:" << setw(54) << "Congratulations, Your performance is Excellent." << endl;
            fout << "" << endl;
        }
        else
        {
            fout << "" << endl;
        }


        }


    }



    cout << "Data written to project3_A04889172_Output.txt" << endl;

    // Close input and output file
    fin.close();
    fout.close();
}

