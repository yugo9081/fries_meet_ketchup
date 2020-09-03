#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "project.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  int print = 4; //how many we want to print
  int maxsize = 1000; //max size for heap
  int m = 2; // # of matched people
  Heap pq1(maxsize);
  // Heap pq2(maxsize);
  bool flag = false;
  string country, city, type, vegeterian, price, rating, restaurant;
  string line1, line2;
  string filename1, filename2;
  string answerCountry, answerCity, answerType, answerVeg, answerPrice;
  string name, age, gender, job, face, interest1, interest2, YorN, realAge;
  string answer1, answerAge, answerGender, answerInterest1, answerInterest2;
  vector<Node2> v;
  int count = 0;
  filename1 = argv[1];
  filename2 = argv[2];
  ifstream inStream (filename1);
  ifstream inStream2(filename2);

  cout << "# Choose the cuisine of food:"<<endl;
  cout<< "1.American\n2.Japanese\n3.Chinese\n4.Korean\n5.Mediterranean\n6.Italian\n7.Indian\n8.Mexican" << endl;
  getline(cin, answerCountry);
  while(!(stoi(answerCountry) >= 1 && stoi(answerCountry) <= 8))
  {
     cout <<"Invalid country! Please try again"<<endl;
     getline(cin, answerCountry);
  }

  cout << "# Choose the city:" <<endl;
  cout<< "1.Boulder\n2.Westminster\n3.Denver" << endl;
  getline(cin, answerCity);
  while(!(stoi(answerCity) >= 1 && stoi(answerCity) <= 3))
  {
    cout <<"Invalid city! Please try again"<<endl;
    getline(cin, answerCity);
  }

  cout << "# Choose the type of food: "<<endl;
  cout<<"1.Brunch\n2.Coffee\n3.Restaurant" << endl;
  getline(cin, answerType);
  while(!(stoi(answerType) >= 1 && stoi(answerType) <= 3))
  {
    cout <<"Invalid date! Please try again"<<endl;
    getline(cin, answerType);
  }

  cout << "# Are you vegeterian or not: Y or N." << endl;
  getline(cin, answerVeg);
  while(answerVeg != "Y" && answerVeg != "N" )
  {
    cout <<"Invalid answer! Please try again"<<endl;
    getline(cin, answerVeg);
  }

  cout << "# Choose the price: $ or $$, or $$$" << endl;
  getline(cin, answerPrice);
  while(answerPrice != "$" && answerPrice != "$$" && answerPrice != "$$$" )
  {
    cout <<"Invalid price range! Please try again"<<endl;
    getline(cin, answerPrice);
  }

  if(inStream.is_open())
  {
    while (getline(inStream,line1))
    {
      if(line1 != "")
      {
        stringstream str(line1);
        getline(str, type, ',');
        getline(str, restaurant, ',');
        getline(str, vegeterian, ',');
        getline(str, country, ',');
        getline(str, rating, ',');
        getline(str, price, ',');
        getline(str, city,',');
        if(country == answerCountry && type == answerType && city == answerCity &&vegeterian == answerVeg &&price == answerPrice)
        {
          pq1.enqueue(restaurant, stod(rating));
        }
        }
      }
      if(pq1.isEmpty()){
        cout<<"Sorry!!No matched restaurants"<<endl;
        return 0;
      }
      else{
        pq1.printArray(print);
      }
    }
    inStream.close();
    cout<< "Do you want a company?(Y/N)"<<endl;
    getline(cin, answer1);
    while(answer1 != "Y" && answer1 != "N" && answer1 != "y" && answer1 != "n")
    {
      cout <<"Invalid answer! Please try again"<<endl;
      getline(cin, answer1);
    }

    if (answer1 == "N" || answer1 == "n")
    {
        cout<<"Enjoy!!" << endl;
    }

    else if (answer1 == "Y" || answer1 == "y")
    {
        cout<<"Choose age range: 1.18-21. 2.22-25. 3.26-30. 4.31-35"<<endl;
        getline(cin, answerAge);
        while(!(stoi(answerAge) >= 1 && stoi(answerAge) <= 4))
        {
          cout <<"Invalid answer! Please try again"<<endl;
          getline(cin, answerAge);
        }

        cout<<"Choose gender: 1.female 2.male "<<endl;
        getline(cin, answerGender);
        while(!(stoi(answerGender) >= 1 && stoi(answerGender) <= 2))
        {
          cout <<"Invalid answer! Please try again"<<endl;
          getline(cin, answerGender);
        }

        cout<<"First interest: "<<endl;
        cout<<"1.Reading\n2.Sports\n3.Hiking\n4.Skiing/Snowboarding\n5.Gaming\n6.Movies\n7.Cooking"<<endl;
        getline(cin, answerInterest1);
        while(!(stoi(answerInterest1) >= 1 && stoi(answerInterest1) <= 7))
        {
          cout <<"Invalid answer! Please try again"<<endl;
          getline(cin, answerInterest1);
        }

        cout<<"Second interest: "<<endl;
        cout<<"1.Reading\n2.Sports\n3.Hiking\n4.Skiing/Snowboardingn\n5.Gaming\n6.Movies\n7.Cooking"<<endl;
        getline(cin, answerInterest2);
        while(!(stoi(answerInterest2) >= 1 && stoi(answerInterest2) <= 7))
        {
          cout <<"Invalid answer! Please try again"<<endl;
          getline(cin, answerInterest2);
        }

        if (inStream2.is_open())
        {
          while (getline(inStream2,line2))
          {
            if(line2 != "")
            {
              stringstream str(line2);
              getline(str, face, ',');
              getline(str, name, ',');
              getline(str, realAge, ',');
              getline(str, gender, ',');
              getline(str, job, ',');
              getline(str, interest1, ',');
              getline(str, interest2,',');
              getline(str, city,',');
              getline(str, age, ',');
              Node2 z;
              z.name=name;
              z.job=job;
              z.face=face;
              z.realAge=realAge;
              z.city=city;
              if(gender == answerGender && age == answerAge && interest1 == answerInterest1 && interest2 == answerInterest2)
              {
                v.push_back(z);
              }
              if(gender == answerGender && age == answerAge && interest2 == answerInterest1 && interest1 == answerInterest2)
              {
                v.push_back(z);
              }
            }
          }
          for (int i = 0; i < v.size(); i++)
          {
              cout<<"Profile: "<<v[i].face<<endl;
              cout<<" "<<"Name: "<<v[i].name<<endl;
              cout<<" "<<"Age: "<<v[i].realAge<<endl;
              cout<<" "<<"Job: "<<v[i].job<<endl;
              cout<<" "<<"City: "<<v[i].city<<endl;
          }
          cout << "Enjoy!!" << endl;
          inStream2.close();
        }
    }
  }
