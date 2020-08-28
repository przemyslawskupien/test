#include"musicbuddy.h"
#include<iostream>

int main(){
    MajorScale cMajor {chromaticSteps::C};
    MinorScale aMinor {chromaticSteps::A};
    Chord cDur;
    Chord aMoll{A, MINOR};
    Scale *majPtr, *minPtr;
    majPtr = &cMajor;
    minPtr = &aMinor;

    std::cout << aMinor.getKey() << std::endl;
    std::cout << aMinor.getStep(2) << std::endl;
    std::cout << aMinor.getSize() << std::endl;
    std::cout << cDur << std::endl;
    std::cout << aMoll << std::endl;

    cMajor.Scale::orTest();
    aMinor.orTest();
    majPtr->orTest();
    minPtr->orTest();

    aMinor.printScale();
    cMajor.printScale();
}