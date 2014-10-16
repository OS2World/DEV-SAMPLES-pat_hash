#include <iostream.h>
#include <iglobals.h>
#include <pat_hash.h>
#include <ihshks.h>

typedef IHashKeySet  <Patient , NameBirthSex>  PatientSet;


ostream & operator << ( ostream & sout, PatientSet patients)

   {
   PatientSet::Cursor patientsCursor(patients);

   IDate::YearFormat yearFormat=IDate::yyyy;

   for (patientsCursor.setToFirst();patientsCursor.isValid();patientsCursor.setToNext() )
     {
     Patient printElement = patients.elementAt(patientsCursor);

     cout << "Patient: " <<  printElement.patientName()
          << ",  " << printElement.patientBirth().asString(yearFormat)
          << ",  " << printElement.patientSex()
          << ",  " << printElement.patientDiagnosis() << endl;
     } /* endfor */

   return sout;
   }



int main ()
{
  PatientSet patients;

  Patient p1("Annnie Anderson", IDate(IDate::January, 17, 1970), "female", " ");
  Patient p2("Bernie Butcher", IDate(IDate::February, 19, 1934), "male", " ");
  Patient p3("Chris Capone", IDate(IDate::March, 12, 1924), "male", " ");
  Patient p4("Dave Dudley", IDate(IDate::April, 16, 1943), "male", " ");
  Patient p5("Elton Edwards", IDate(IDate::May, 12, 1960), "male", " ");
  Patient p6("Fanny Ferguson", IDate(IDate::June, 15, 1959), "female", " ");
  Patient p7("Greg Gigley", IDate(IDate::July, 22, 1936), "male", " ");
  Patient p8("Helen Hatchet", IDate(IDate::August, 30, 1940), "female", " ");
  Patient p9("Leslie Lonesome", IDate(IDate::June, 1, 1969), "female", " ");
  Patient p10("Leslie Lonesome", IDate(IDate::June, 1, 1969), "male", " ");

  p1.setPatientDiagnosis("fever");
  p2.setPatientDiagnosis("sickness");
  p3.setPatientDiagnosis("influenza");
  p4.setPatientDiagnosis("headache");
  p5.setPatientDiagnosis("indigestion");
  p6.setPatientDiagnosis("catarrh");
  p7.setPatientDiagnosis("laziness");
  p8.setPatientDiagnosis("appendicitis");
  p9.setPatientDiagnosis("stage-fright");
  p10.setPatientDiagnosis("hayfever");


        patients.add(p1);
        patients.add(p2);
        patients.add(p3);
        patients.add(p4);
        patients.add(p5);
        patients.add(p6);
        patients.add(p7);
        patients.add(p8);
        patients.add(p9);
        patients.add(p10);

        cout << "Printing the original patient collection:"
             << endl
             << "========================================="
             << endl
             << patients
             << endl;

        return 0;
}
