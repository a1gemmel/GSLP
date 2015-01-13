#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/*
Gemm's Phrak's Greyskull Linear Program Variant Variant 


;; Upper split (2 day):

A:
Bench Press 3x5
Tricep Extension 3x8
Chinups 3x5
Barbell Curl 3x8
Facepull 3x8

B:
Overhead Press 3x5
Row Variant 3x5
Lateral Raise 3x8
Front Raise 3x8
Facepull 3x8

;; Lower Split (3 day):

A:
Deadlift 1x5
Barbell Shrug 3x8 - Done as deadlift cooldown 

B:
Squat 3x5

C:
Squat 3x5

*/


struct Exercise {
  string name;
  float weight;
  int reps, sets;
  float progression_rate;
  Exercise(string n, int r, int s,int w,int u):name(n), reps(r), sets(s), weight(w), progression_rate(u){}
  friend ostream& operator<<(ostream& out, Exercise& e) {
    out << e.name << " " << e.sets << "x" << e.reps << "  " << floor(e.weight) - ((int)floor(e.weight) % 5) << "lbs";
    return out;
  }
  void increment(){weight += progression_rate;}

};





int main(){
  
  Exercise routine[4][5] = {{Exercise("Bench Press", 5, 3, 135, 2.5),
			     Exercise("Chinups", 5, 3, 0, 2.5),	
			     Exercise("Tricep Extensions", 8, 3, 42.5, 1.125),
			     Exercise("Barbell Curl", 8, 3, 55, 1.125),
			     Exercise("Facepulls", 8, 3, 27.5, 0)},

			    {Exercise("Overhead Press", 5, 3, 75, 2.5),
			     Exercise("Barbell Row", 5, 3, 135, 2.5),
			     Exercise("Lateral Raise", 8, 3, 10, 1.125),
			     Exercise("Front Raise", 8, 3, 10, 1.125),
			     Exercise("Facepulls", 8, 3, 27.5, 0)},

			    {Exercise("Deadlift", 5, 1, 205, 5),
			     Exercise("Barbell Shrug", 8, 3, 155, 2.5),
			     Exercise("",0,0,0,0),
			     Exercise("",0,0,0,0),
			     Exercise("",0,0,0,0)},

			    {Exercise("Squat", 5, 3, 175, 2.5),
			     Exercise("",0,0,0,0),
			     Exercise("",0,0,0,0),
			     Exercise("",0,0,0,0),
			     Exercise("",0,0,0,0)}};


  cout << "== Gemm's Phrak's Greyskull Linear Program Variant Variant ==" << endl <<
    "Last set is always AMRAP. If 10 reps, double increment." << endl;
  for (int day = 0; day < 36; day++) {
    cout << "===Week "<< day / 3 + 1 << "===" << endl;
    if (day % 3 == 0) {
      cout << "Monday:" << endl;
    }  else if (day % 3 == 1) {
      cout << "Wednesday:" << endl;
    } else {
      cout << "Friday:" << endl;
    }
    for (int i = 0; i < 5; i++) { //upperbody print
      cout << routine[day % 2][i] << endl;
      routine[day % 2][i].increment();
    }
    if (day % 3 == 0) {
      cout << routine[2][0] << endl << routine[2][1] << endl;
      routine[2][0].increment();
      routine[2][1].increment();
    } else {
      cout << routine[3][0] << endl;
      routine[3][0].increment();
    }
    cout << endl;
  }
}
