#include <istring.hpp>
#include <idate.hpp>
#include <iglobals.h>
#include <stdio.h>


struct NameBirthSex
{
        IString ivName;
        IDate   ivBirth;
        IString ivSex;


        NameBirthSex (IString const& n, IDate const& b, IString const& s)
                                                       : ivName(n),
                                                         ivBirth(b),
                                                         ivSex(s)
                                                         {}

        Boolean operator== (NameBirthSex const& nbs) const
              {
               return
                   this->ivName == nbs.ivName
                   && this->ivBirth == nbs.ivBirth
                   && this->ivSex == nbs.ivSex;

              }
};

class Patient
{
        NameBirthSex  ivNameBirthSex;
        IString       ivDiagnosis;

public:

 // a constructor
 Patient( IString patName, IDate patBirth, IString patSex,
          IString patDiagnosis)
                                   : ivNameBirthSex(patName, patBirth, patSex),
                                     ivDiagnosis(patDiagnosis)
                                     {}


        IString const& patientName()  const
          {
            return ivNameBirthSex.ivName;
          }


        IDate const& patientBirth() const
          {
            return ivNameBirthSex.ivBirth;
          }

        IString const& patientSex()
          {
            return ivNameBirthSex.ivSex;
          }

        NameBirthSex const& getKey() const
          {
            return ivNameBirthSex;
          }

        IString const& patientDiagnosis()  const
          {
            return ivDiagnosis;
          }

        void setPatientDiagnosis(IString const& setDiagnosis)
          {
             this->ivDiagnosis = setDiagnosis;
          }
};

// key function
inline NameBirthSex const& key (Patient const& patient)
          {
              return patient.getKey();
          }

// hash function
// our private hash function composes "hashValue" by using
// the hash function 'hash' for string input provided by the collection classes
// n is the number of elements in the collection

inline unsigned long hash (NameBirthSex const& nbs,
                           unsigned long n)
     {
       unsigned long hashValue;
       int           sex;

       if (nbs.ivSex == "female") sex=1; else sex=2;

       return hashValue = (hash(nbs.ivName, n) + nbs.ivBirth.year() + sex) % n;
     }
